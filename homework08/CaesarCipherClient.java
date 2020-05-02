/* Homework 8: Caesar Cipher Client
 * James Eapen (jpe4)
 * 2020 May 9
 *
 * Connects to a Caesar cipher server sending it a rotation.
 * It receives user input, sends it to the 
 * server, and receives and displays the server response
 */

import java.util.Scanner;
import java.net.Socket;
import java.net.SocketException;
import java.io.DataOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;


public class CaesarCipherClient {
    
    public static void main(String[] args) {
        if (args.length !=2) {
            System.err.print("Usage: java CaesarCipherClient <hostname> <port>");
            System.exit(1);
        }

        String hostname = args[0];
        int port = Integer.parseInt(args[1]);

        System.out.println("Welcome to the Caesar Ciper Client");
        System.out.println("Connecting to " + hostname + " on port " + port);
        System.out.print("Enter the rotation amount: ");

        Scanner userInput = new Scanner(System.in);
        int rotation = userInput.nextInt();
        System.out.print("Rotation amount: " + rotation);
    }

}
