/* Homework 8: Caesar Cipher Client
 * James Eapen (jpe4)
 * 2020 May 9
 *
 * Connects to a Caesar cipher server sending it a rotation.
 * It receives user input, sends it to the 
 * server, and receives and displays the server response
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
        
        System.out.println("Welcome to the Caesar Ciper Client");

        // get rotation
        System.out.print("Enter the rotation amount between 1 and 25: ");
        int rotation = 0;
        Scanner userInput = new Scanner(System.in);
        try {
            rotation = userInput.nextInt();
        }
        catch (InputMismatchException e) {
            System.out.println("rotation must be an integer");
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
              System.out.println("Connecting to " + hostname + " on port " + port);
              dataOut.println(String.valueOf(rotation));
              System.out.println(dataIn.readLine());
                
              String line;
              System.out.print("Encrypt this: ");
              while ((line = stdIn.readLine()) != null && line != "quit") {
                  //if (line == "quit") { 
                  //    System.out.println("exit");
                  //    System.exit(0);
                  //}
                  dataOut.println(line);
                  System.out.println("Server: " + dataIn.readLine());
                  System.out.print("Encrypt this: ");
              }
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
