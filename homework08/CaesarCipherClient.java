/* Homework 8: Caesar Cipher Client
 * James Eapen (jpe4)
 * 2020 May 9
 *
 * This client connects to a Caesar cipher server sending it a rotation.
 * It receives user input, sends it to the 
 * server, and receives and displays the server response
 * Citation: https://docs.oracle.com/javase/tutorial/networking/sockets/examples/EchoClient.java
 */

import java.util.InputMismatchException;
import java.util.Scanner;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.io.DataOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;


public class CaesarCipherClient {

    public static void main(String[] args) {
        if (args.length !=2) {
            System.err.print("Usage: java CaesarCipherClient <hostname> <port>");
            System.exit(1);
        }

        // get host and portNumber from args
        String hostname = args[0];
        int port = 0;
        try {
            port = Integer.parseInt(args[1]);
        }
        catch (NumberFormatException e) {
            System.err.println("Port number must be an integer");
            System.exit(1);
        }
        
        System.out.println("Welcome to the Caesar Cipher Client!");
        System.out.println("Connecting to " + hostname + " on port " + port);

        // get rotation
        System.out.print("\nEnter the rotation amount between 1 and 25: ");
        int rotation = 0;
        Scanner userInput = new Scanner(System.in);
        
        //check if entered value is int
        try {
            rotation = userInput.nextInt();
        }
        catch (InputMismatchException e) {
            System.out.println("rotation must be an integer");
            System.exit(1);
        }

        // check if entered int is legal
        if (rotation > 25 || rotation < 1) {
            System.out.println("rotation must be between 1 and 25");
            System.exit(1);
        }

        // connect to server and communicate
        try (
            Socket CaesarScocket = new Socket(hostname, port);
            PrintWriter dataOut = new PrintWriter(CaesarScocket.getOutputStream(), true);
            BufferedReader dataIn = new BufferedReader(new InputStreamReader(CaesarScocket.getInputStream()));
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
            )

            {
              System.out.println("\nConnected to " + hostname + " on port " + port);
              System.out.println("\nType 'quit' to exit");
              dataOut.println(String.valueOf(rotation));
              System.out.println(dataIn.readLine());
                
              // take user input and receive server output
              // quit when user enters quit
              String line;
              System.out.print("Enter text: ");

              while ((line = stdIn.readLine()) != null && !line.equals("quit")) {
                  dataOut.println(line);
                  System.out.println("Server: " + dataIn.readLine());
                  System.out.print("Enter text: ");
              }

              System.out.println("quitting client");
            }

        catch(UnknownHostException e) {
            System.out.println("Error: " + hostname + " not known");
            System.exit(1);
        }

        catch(IOException e) {
            System.err.println("IO exception while connecting with " + hostname);
            System.exit(1);
        }
    }
}
