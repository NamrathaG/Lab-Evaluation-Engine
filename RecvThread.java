import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import javax.swing.Timer;
import javax.swing.SwingUtilities;
class RecvThread {
JLabel jlab;
RecvThread() {


try{
JNIDemo jdo=new JNIDemo();
jdo.recv();
}
catch(Exception e)
{
System.out.println("inside the Recv Thread");
}




}
public static void main(String args[]) {
// Create the frame on the event dispatching thread.
SwingUtilities.invokeLater(new Runnable() {
public void run() {
new RecvThread();
}
});
}
}
