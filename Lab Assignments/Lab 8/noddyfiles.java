package com.company;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class noddyfiles
{
    public static void main(String[] args) throws IOException {

        while(true)
        {

            Scanner sc1 = new Scanner(System.in);
            System.out.println("1. Create a new File ");
            System.out.println("2. Read the data in the file");
            System.out.println("3. Write data into the file");
            System.out.println("4. Delete the file");
            System.out.println("5. Rename a file");
            System.out.println("6. Get the absolute file path");
            System.out.println("7. Get the File information");
            System.out.println("8. Check the file permissions");
            System.out.println("Enter the choice: ");
            int choice = sc1.nextInt();

            if (choice == 1)
            {
                System.out.println("Enter the name of the file -> ");
                Scanner sc = new Scanner(System.in);
                String myname = sc.nextLine();
                // create a file object for the current location
                File file = new File(myname);

                try {

                    // trying to create a file based on the object
                    boolean value = file.createNewFile();
                    if (value) {
                        System.out.println("The new file is created.");
                        String absolute = file.getAbsolutePath();
                        System.out.println("Absolute  path: "
                                + absolute);

                    }
                    else {
                        System.out.println("The file already exists.");
                    }
                }
                catch(Exception e) {
                    e.getStackTrace();
                }

                System.out.println();
                System.out.println("===============================================================================================");
                System.out.println();

            }
            else if (choice == 2)
            {
                // reading the data which is present in the files

                char[] array = new char[100000];
                try {
                    // Creates a reader using the FileReader
                    FileReader input = new FileReader("C:\\Users\\NIRANJAN\\OneDrive\\Documents\\arduino.txt");

                    // Reads characters
                    input.read(array);
                    System.out.println("Data in the file:");
                    System.out.println(array);

                    // Closes the reader
                    input.close();
                }
                catch(Exception e) {
                    e.getStackTrace();
                }

                System.out.println();
                System.out.println("===============================================================================================");
                System.out.println();
            }
            else if (choice == 3)
            {
                // write data into the file
                System.out.println("Enter the data to be entered in the file -> ");
                Scanner sc = new Scanner(System.in);
                String data = sc.nextLine();
                char[] array = new char[100000];

                //String data = "We're not nameless were not faceless we were born for greatness";
                try {
                    // Creates a Writer using FileWriter
                    System.out.println("Enter the name of the file -> ");
                    Scanner scan1 = new Scanner(System.in);
                    String readFile = scan1.nextLine();
                    FileWriter output = new FileWriter(readFile);

                    // Writes string to the file
                    output.write(data);
                    System.out.println("Data is written to the file.");

                    output.close();
                }
                catch (Exception e) {
                    e.getStackTrace();
                }

                System.out.println();
                System.out.println("===============================================================================================");
                System.out.println();
            }
            else if (choice == 4)
            {
                System.out.println("Enter the name of the file -> ");
                Scanner scan1 = new Scanner(System.in);
                String readFile = scan1.nextLine();
                // creates a file object
                File file = new File(readFile);

                // deletes the file
                boolean value = file.delete();
                if(value) {
                    System.out.println("The File is deleted.");
                }
                else {
                    System.out.println("The File is not deleted.");
                }

                System.out.println();
                System.out.println("===============================================================================================");
                System.out.println();

            }
            else if (choice == 5)
            {
                System.out.println("Enter the name of the file to be renamed -> ");
                Scanner scan1 = new Scanner(System.in);
                String name1 = scan1.nextLine();
                File oldName =
                        new File(name1);
                boolean exists = oldName.exists();
                if(exists == true) {
                    System.out.println("Enter the new name of the file -> ");
                    Scanner scan2 = new Scanner(System.in);
                    String name2 = scan2.nextLine();
                    File newName =
                            new File(name2);

                    if (oldName.renameTo(newName))
                        System.out.println("Renamed successfully");
                    else
                        System.out.println("Error");
                }
                else
                {
                    System.out.println("The file doesn't exit!!!!!");
                }

                System.out.println();
                System.out.println("===============================================================================================");
                System.out.println();
            }
            else if (choice == 6)
            {
                try {
                    System.out.println("Enter the name of the file -> ");
                    Scanner sc = new Scanner(System.in);
                    String myname = sc.nextLine();

                    // Create a file object
                    File f = new File(myname);
                    boolean exists = f.exists();
                    if(exists == true) {

                        // Get the absolute path of file f
                        String absolute = f.getAbsolutePath();

                        // Display the file path of the file object
                        // and also the file path of absolute file
                        System.out.println("Original  path: "
                                + f.getPath());
                        System.out.println("Absolute  path: "
                                + absolute);
                    }
                    else{
                        System.out.println("The file doesn't exist!!!!!");
                    }
                }
                catch (Exception e) {
                    System.err.println(e.getMessage());
                }

                System.out.println();
                System.out.println("===============================================================================================");
                System.out.println();
            }
            else if (choice == 7)
            {
                File file = new File("C:\\Users\\NIRANJAN\\OneDrive\\Documents\\arduino.txt");
                FileInputStream fileStream = new FileInputStream(file);
                InputStreamReader input = new InputStreamReader(fileStream);
                BufferedReader reader = new BufferedReader(input);

                String line;

                // Initializing counters
                int countWord = 0;
                int sentenceCount = 0;
                int characterCount = 0;
                int paragraphCount = 1;
                int whitespaceCount = 0;

                // Reading line by line from the
                // file until a null is returned
                while((line = reader.readLine()) != null)
                {
                    if(line.equals(""))
                    {
                        paragraphCount++;
                    } else {
                        characterCount += line.length();

                        // \\s+ is the space delimiter in java
                        String[] wordList = line.split("\\s+");

                        countWord += wordList.length;
                        whitespaceCount += countWord -1;

                        // [!?.:]+ is the sentence delimiter in java
                        String[] sentenceList = line.split("[!?.:]+");

                        sentenceCount += sentenceList.length;
                    }
                }

                System.out.println("Total word count = " + countWord);
                System.out.println("Total number of sentences = " + sentenceCount);
                System.out.println("Total number of characters = " + characterCount);
                System.out.println("Number of paragraphs = " + paragraphCount);
                System.out.println("Total number of whitespaces = " + whitespaceCount);

                System.out.println();
                System.out.println("===============================================================================================");
                System.out.println();
            }
            else if (choice == 8)
            {
                System.out.println("Enter the name of the file -> ");
                Scanner scan1 = new Scanner(System.in);
                String readFile = scan1.nextLine();
                File file = new File(readFile);

                // check if the file exists
                boolean exists = file.exists();
                if(exists == true)
                {
                    // printing the permissions associated with the file
                    System.out.println("Executable: " + file.canExecute());
                    System.out.println("Readable: " + file.canRead());
                    System.out.println("Writable: "+ file.canWrite());

                    System.out.println();
                    System.out.println("===============================================================================================");
                    System.out.println();
                }
                else
                {
                    System.out.println("File not found.");
                }
            }

            else
            {
                System.out.println("Wrong choice..!!!!");
                System.out.println();
                System.out.println("===============================================================================================");
                System.out.println();
                break;
            }
        }

    }

}
