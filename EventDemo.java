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
class EventDemo {

EventDemo() {

JFrame jfrm = new JFrame("Your Chat Box");

jfrm.setLayout(new FlowLayout());

jfrm.setSize(700, 500);

jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

JTextArea chat=new JTextArea();

 chat.setColumns(50);
        chat.setRows(50);

jfrm.add(chat);


jfrm.setVisible(true);

while(true)
{
try{
 FileReader fr=new FileReader("chatbox.txt");
 BufferedReader reader=new BufferedReader(fr);
 String line;
 String compiledmsg="";
 while((line=reader.readLine())!=null)
 {
    compiledmsg=compiledmsg+line+"\n";
    
   
}
chat.setText(compiledmsg);
reader.close();
fr.close();
}
catch(Exception e)
{
System.out.println("in event demo");
}
}
}
public static void main(String args[]) {
// Create the frame on the event dispatching thread.
SwingUtilities.invokeLater(new Runnable() {
public void run() {
new EventDemo();
}
});
}
}
