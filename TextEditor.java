package com.company;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import javax.swing.JMenuItem;
import javax.swing.JTextField;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JFileChooser;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.Color;
import java.awt.Desktop;
import java.awt.Image;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.net.URI;


class TextEditor implements ActionListener {

    JFrame f;
    JMenuBar menuBar;
    JMenu file,edit,themes;
    JTextArea textArea;
    JScrollPane scroll;
    JMenuItem darkTheme,moonLightTheme,save,open,close,cut,copy,paste,New,selectAll,fontSize;
    JPanel saveFileOptionWindow;
    JLabel fileLabel, dirLabel;
    JTextField fileName, dirName;

    TextEditor(){

        f = new JFrame("Java Text Editor Assignment"); //setting the frame

        Image img = Toolkit.getDefaultToolkit().getImage("src\\com\\company\\logo.JPG"); //adding image
        f.setIconImage(img);

        menuBar = new JMenuBar();

        //menues
        file = new JMenu("File");
        edit = new JMenu("Edit");
        themes = new JMenu("Themes");

        //adding menues to menubar
        menuBar.add(file);
        menuBar.add(edit);
        menuBar.add(themes);
        f.setJMenuBar(menuBar);


        //adding submenus to file
        save = new JMenuItem("Save");
        open = new JMenuItem("Open");       //file menu
        New = new JMenuItem("New");
        close = new JMenuItem("Exit");
        file.add(open);
        file.add(New);
        file.add(save);
        file.add(close);

        cut = new JMenuItem("Cut");
        copy = new JMenuItem("Copy");        //edit menu
        paste = new JMenuItem("Paste");
        selectAll = new JMenuItem("Select all");
        fontSize = new JMenuItem("Font size");
        edit.add(cut);
        edit.add(copy);
        edit.add(paste);
        edit.add(selectAll);
        edit.add(fontSize);

        //adding submenues to tools menu

        //adding themes
        darkTheme = new JMenuItem("Dark Theme");
        moonLightTheme = new JMenuItem("Moonlight Theme");
        themes.add(darkTheme);
        themes.add(moonLightTheme);


        //Textarea
        textArea = new JTextArea(32,88);
        f.add(textArea);
        //scrollpane
        scroll = new JScrollPane(textArea);
        scroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        f.add(scroll);


        //adding event listeners for cut , copy & paste
        cut.addActionListener(this);
        copy.addActionListener(this);
        paste.addActionListener(this);
        selectAll.addActionListener(this);
        fontSize.addActionListener(this);//change the font size
        open.addActionListener(this); //open the file
        save.addActionListener(this);//Save the file
        New.addActionListener(this);//Create the new document
        darkTheme.addActionListener(this);//dark theme
        moonLightTheme.addActionListener(this);//moonlight theme

        close.addActionListener(this);//close the window
        f.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {

            }

            @Override
            public void windowClosing(WindowEvent e) {

                int confirmExit = JOptionPane.showConfirmDialog(f,"Do you want to exit?","Confirm Before Saving...",JOptionPane.YES_NO_OPTION);

                if (confirmExit == JOptionPane.YES_OPTION)
                    f.dispose();
                else if (confirmExit == JOptionPane.NO_OPTION)
                    f.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
            }

            @Override
            public void windowClosed(WindowEvent e) {

            }

            @Override
            public void windowIconified(WindowEvent e) {

            }

            @Override
            public void windowDeiconified(WindowEvent e) {

            }

            @Override
            public void windowActivated(WindowEvent e) {

            }

            @Override
            public void windowDeactivated(WindowEvent e) {

            }
        });

        //Keyboard Listeners
        KeyListener k = new KeyListener() {

            @Override
            public void keyTyped(KeyEvent e) { }

            @Override
            public void keyPressed(KeyEvent e) {

                int keyCode = e.getKeyCode();

                if (keyCode == KeyEvent.VK_S && e.isControlDown()){

                    saveTheFile(); //Saving the file
                }
            }

            @Override
            public void keyReleased(KeyEvent e) { }
        };

        textArea.addKeyListener(k);


        //Default Operations for frame
        f.setSize(1000,596);
        f.setResizable(false);
        f.setLocation(250,100);
        f.setLayout(new FlowLayout());
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    //

    @Override
    public void actionPerformed(ActionEvent e) {

        //Copy paste operations
        if (e.getSource()==cut)
            textArea.cut();
        if (e.getSource()==copy)
            textArea.copy();
        if (e.getSource()==paste)
            textArea.paste();
        if (e.getSource()==selectAll)
            textArea.selectAll();


        //change the fontsize by value
        if (e.getSource()==fontSize){

            String sizeOfFont = JOptionPane.showInputDialog(f,"Enter Font Size",JOptionPane.OK_CANCEL_OPTION);

            if (sizeOfFont != null){

                int convertSizeOfFont = Integer.parseInt(sizeOfFont);

                Font font = new Font(Font.SANS_SERIF,Font.PLAIN,convertSizeOfFont);

                textArea.setFont(font);

            }

        }

        //Open the file
        if (e.getSource()==open){

            JFileChooser chooseFile = new JFileChooser();

            int i = chooseFile.showOpenDialog(f);

            if (i == JFileChooser.APPROVE_OPTION){

                File file = chooseFile.getSelectedFile(); //select the file

                String filePath = file.getPath(); //get the file path

                String fileNameToShow = file.getName(); //get the file name

                f.setTitle(fileNameToShow);

                try {

                    BufferedReader readFile = new BufferedReader(new FileReader(filePath));

                    String tempString1 = "";

                    String tempString2 = "";

                    while ((tempString1 = readFile.readLine()) != null){

                        tempString2 += tempString1 + "\n";
                    }

                    textArea.setText(tempString2);

                    readFile.close();

                }catch (Exception ae){

                    ae.printStackTrace();
                }
            }
        }


        //Save the file
        if (e.getSource()==save){
            saveTheFile();

        }

        //New menu operations
        if (e.getSource()==New){
            textArea.setText("");
        }

        //Exit from the window
        if (e.getSource()==close){
            System.exit(1);
        }

        //themes area
        if (e.getSource()==darkTheme){

            textArea.setBackground(Color.DARK_GRAY);        //dark Theme

            textArea.setForeground(Color.WHITE);
        }

        if (e.getSource()==moonLightTheme){

            textArea.setBackground(new Color(107, 169, 255));

            textArea.setForeground(Color.black);
        }

    }

//Save the file

    public void saveTheFile(){

        saveFileOptionWindow = new JPanel(new GridLayout(2,1));

        fileLabel = new JLabel("Filename      :- ");

        dirLabel = new JLabel("Save File To :- ");

        fileName = new JTextField();

        dirName = new JTextField();

        saveFileOptionWindow.add(fileLabel);

        saveFileOptionWindow.add(fileName);

        saveFileOptionWindow.add(dirLabel);

        saveFileOptionWindow.add(dirName);

        JOptionPane.showMessageDialog(f,saveFileOptionWindow); //show the saving dialogue box

        String fileContent = textArea.getText();

        String filePath = dirName.getText();

        try {

            BufferedWriter writeContent = new BufferedWriter(new FileWriter(filePath));

            writeContent.write(fileContent);

            writeContent.close();

            JOptionPane.showMessageDialog(f,"File Successfully saved!");

        }catch (Exception ex){

            ex.printStackTrace();
        }

    }


    public static void main(String[] args) {

        new TextEditor();
        System.out.println("This is a new text editor");

    }
}


