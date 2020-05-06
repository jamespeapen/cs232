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
import java.net.UnknownHostException;
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
        System.out.print("Enter the rotation amount: ");

        Scanner userInput = new Scanner(System.in);
        int rotation = userInput.nextInt();

        try (
            Socket CaesarScocket = new Socket(hostname, port);
            DataOutputStream dataOut = new DataOutputStream(CaesarScocket.getOutputStream());
            BufferedReader dataIn = new BufferedReader(new InputStreamReader(CaesarScocket.getInputStream()));
            )
        {
            System.out.println("Connecting to " + hostname + " on port " + port);
            dataOut.writeBytes(Integer.toString(rotation));
            dataOut.flush();
            System.out.println("sent rotation " + rotation);
            String line;
            System.out.println("reading");
            System.out.println(dataIn.readLine());
            while(dataIn.readLine() != null){
                System.out.println("getting input");
                line = dataIn.readLine();
                System.out.println(line);
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
