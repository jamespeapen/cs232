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
                System.out.println("New client connected");
                new ServerThread(clientSocket).start();
                System.out.println(new Date().toString());
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

    public void run() {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);

            String line;

            while((line = reader.readLine()) != null && !line.equals("quit")) {
                writer.println(line);
            }
            socket.close();
        }
        catch (IOException e) {
            System.err.println("IOException");
        }
    }
}
