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


public class CaesarClient {
    
    public static void main(String[] args) {
        System.out.println("Welcome to the Caesar Ciper Client");
        System.out.println("Enter the rotation amount: ");

        Scanner userInput = new Scanner(System.in);
        int rotation = userInput.nextInt();
        System.out.print("Rotation amount: " + rotation);
    }

}
