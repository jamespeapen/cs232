/* Homework 8: Caesar Server 
 * James Eapen (jpe4)
 * 2020 May 9
 *
 * Opens a TCP socket and listens for client connections
 * Receives an int n and saves and returns it
 * Spawns new threads to handle clientsj
 * Citation: https://docs.oracle.com/javase/tutorial/networking/sockets/examples/EchoServer.java
 */

import java.util.Scanner;
import java.util.Date;
import java.net.Socket;
import java.net.ServerSocket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.io.DataOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;

public class CaesarCipherServer {

    public static void main(String[] args) {

        if (args.length != 1) {
            System.err.println("Usage: java CaesarCipherServer <port number>");
            System.exit(1);
        }
         
        int port = Integer.parseInt(args[0]);
        Date date = new Date(); 
        try (
            ServerSocket serverSocket = new ServerSocket(port);
            ) 
        {
            System.out.println("server is listening on port " + port);

            while (true) {
                Socket clientSocket = serverSocket.accept(); 
                System.out.println(new Date().toString() +
                        ": New client connected: "+ clientSocket.getRemoteSocketAddress().toString());
                new ServerThread(clientSocket).start();
            }
        } catch (IOException e) {
            System.out.println("IOException while listening on port "
                + port);
            System.out.println(e.getMessage());
        }
    }
}
        
public class ServerThread extends Thread {
    private Socket socket;

    public ServerThread(Socket socket) {
        this.socket = socket;
    }

    /* Run the client connection threads
     * Receives plaintext and transmits ciphertext
     */
    public void run() {
        try {
            BufferedReader dataIn = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter dataOut = new PrintWriter(socket.getOutputStream(), true);

            String line;
            
            // get rotation from client
            line = dataIn.readLine();
            int rotation = Integer.valueOf(line);

            // check for legal rotation, log disconect
            if (rotation > 25 || rotation < 1) {
                dataOut.print("Enter an integer between 1 and 25 inclusive. Disconnecting...");
                socket.close();
            System.out.println(new Date().toString() + 
                    ": " + socket.getRemoteSocketAddress().toString() + " disconected: bad rotation");
            }

            // confirm rotation
            dataOut.println("Encrypting with rotation: " + rotation);
            
            // encrypt and send line
            while((line = dataIn.readLine()) != null && !line.equals("quit")) {
                dataOut.println(encryptLine(line, rotation));
            }

            //disconect client and log
            socket.close();
            System.out.println(new Date().toString() + ": " + socket.getRemoteSocketAddress().toString() + " disconected");
        }
        catch (IOException e) {
            System.err.println("IOException");
        }
    }

    /* Caesar Cipher Algorithm
     * Rotates the characters in the given string by rotation looping around the alphabet
     */
    private static String encryptLine(String line, int rotation) {

        char ch;
        String encryptedLine = "";

        for(int i = 0; i < line.length(); ++i){
			ch = line.charAt(i);

            // lowercase chars between 'a' and 'z'
			if(ch >= 'a' && ch <= 'z'){
	            ch = (char)(ch + rotation);
                
                // if encrypted char is above 'z', loop around
	            if(ch > 'z'){
	                ch = (char)(ch - 'z' + 'a' - 1);
	            }

	            encryptedLine += ch;
	        }

            // uppercase
	        else if(ch >= 'A' && ch <= 'Z'){
	            ch = (char)(ch + rotation);

	            if(ch > 'Z'){
	                ch = (char)(ch - 'Z' + 'A' - 1);
	            }

	            encryptedLine += ch;
	        }
	        else {
	        	encryptedLine += ch;
	        }
		}
        return encryptedLine;
    }
}
