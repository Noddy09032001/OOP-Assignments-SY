package com.company;
import java.util.Scanner;

public abstract class shape                // creating class shape
{
    double x;
    double y;          // declaring the data members as double type

    public shape()                   // default constructor
    {
        x=y=0.0;
    }

    public shape(double x, double y)    // parameterised constructor
    {
        this.x = x;
        this.y = y;
    }

    public void get_data()
    {
        System.out.println("Enter the input parameters: ");
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the first parameter: ");
        x = sc.nextDouble();
        System.out.println("Enter the second parameter: ");
        y = sc.nextDouble();
    }

    public abstract void display_area();

    public static void main(String[] args) {

        while(true) {

            Scanner sc1 = new Scanner(System.in);
            System.out.println("1. Rectangle");
            System.out.println("2. Triangle");
            System.out.println("Select your choice: ");
            int choice = sc1.nextInt();

            if (choice == 2) {
                Triangle t = new Triangle();
                t.get_data();
                t.display_area();
            } else if (choice == 1) {
                Rectangle r = new Rectangle();
                r.get_data();
                r.display_area();
            } else {
                System.out.println("Wrong choice.");
                break;
            }
        }


    }
}

class Triangle extends shape
{
    public Triangle()
    {
        super();
    }

    public Triangle(double x, double y)
    {
        super(x,y);
    }

    public void display_area() {
        double area = 0.5*x*y;
        System.out.println("The area of the triangle is: "+ area);
    }
}

class Rectangle extends shape
{
    public Rectangle()
    {
        super();
    }

    public Rectangle(double x, double y)
    {
        super(x,y);
    }

    public void display_area() {
        double area = x*y;
        System.out.println("The area of the rectangle is: "+ area);
    }
}