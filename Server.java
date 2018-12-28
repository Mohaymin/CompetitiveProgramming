/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package socketpractice;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ASUS
 */
public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket ss=new ServerSocket(5555);
            System.out.println("Server Started");
            Socket s=ss.accept();
            
            DataInputStream dis = new DataInputStream(s.getInputStream());
            String fromClient= dis.readUTF();
            System.out.println("Client: " +fromClient);
        } catch (IOException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
