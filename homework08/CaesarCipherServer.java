/* Homework 8: Caesar Server 
 * James Eapen (jpe4)
 * 2020 May 9
 *
 * Opens a TCP socket and listens for client connections
 * Receives an int n and saves and returns it
 * Spawns new threads to handle clientsj
 * Citation: https://docs.oracle.com/javase/tutorial/networking/sockets/examples/EchoServer.java
 */

import java.util.InputMismatchException;
import java.util.Scanner;
import java.net.Socket;
import java.net.ServerSocket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.io.DataOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class CaesarCipherServer {

    public static void main(String[] args) {

        if (args.length != 1) {
            System.err.println("Usage: java CaesarCipherServer <port number>");
            System.exit(1);
        }
         
        int port = Integer.parseInt(args[0]);
         
        try (
            ServerSocket serverSocket =
                new ServerSocket(Integer.parseInt(args[0]));
            Socket clientSocket = serverSocket.accept();     
            PrintWriter out =
                new PrintWriter(clientSocket.getOutputStream(), true);                   
            BufferedReader in = new BufferedReader(
                new InputStreamReader(clientSocket.getInputStream()));
        ) {
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                out.println(inputLine);
            }
        } catch (IOException e) {
            System.out.println("Exception caught when trying to listen on port "
                + port + " or listening for a connection");
            System.out.println(e.getMessage());
        }
    }
}
        
