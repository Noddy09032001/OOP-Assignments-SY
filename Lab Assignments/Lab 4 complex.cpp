#include<iostream>
#include<cmath>

using namespace std;

class complex;         // forward declaration needed for the working of friend functions


class complex
{
    private:

    float real;    //stores the real part
    float img;     //stores the complex part

    public:

    // operator overloading for input and output display options

    friend istream & operator >> (istream &in,  complex &c2);
    friend ostream & operator << (ostream &out, const complex &c);



    complex()                              //constructor for initialization
	{
		real=img=0;
	}


	// operator overloading functions declarations

    complex operator+ (complex c1);
    complex operator- (complex c1);
    complex operator* (complex c1);
    complex operator/ (complex c1);


    // friend functions declarations

    friend complex Addition(complex,complex);
    friend complex Subtraction(complex,complex);
    friend complex Multiplication(complex,complex);
    friend complex Division(complex,complex);
};


// taking inputs from the user

istream & operator >> (istream &in,  complex &c2)
{
    cout << "Enter Real Part: -> ";
    in >> c2.real;
    cout << "Enter Imaginary Part: -> ";
    in >> c2.img;
    return in;
}


// displaying the output to the user

ostream & operator << (ostream &out, const complex &c)
{
    out << c.real;
    out << "+ " << c.img <<"i."<<endl;
    return out;
}



complex complex::operator/ (complex c1)
{
   complex division;
   division.real = ((real*c1.real)+(img*c1.img))/(pow(c1.real,2)+pow(c1.img,2));
   division.img = ((img*c1.real)-(real*c1.img))/(pow(c1.real,2)+pow(c1.img,2));
   return(division);
}



complex complex::operator* (complex c1)
{
   complex multiply;
   multiply.real = ((real*c1.real)-(img*c1.img));
   multiply.img = ((real*c1.img)+(c1.real*img));
   return(multiply);
}


complex complex::operator- (complex c1)
{
   complex sub;
   sub.real = real - c1.real;
   sub.img = img - c1.img;
   return(sub);
}



complex complex::operator+ (complex c1)
{
   complex add;
   add.real = real + c1.real;
   add.img = img + c1.img;
   return(add);
}


//friend function programs

complex Addition(complex c1, complex c2)
{
    complex t;
    t.real = c1.real + c2.real;
    t.img = c1.img + c2.img;

    cout<<"The Addition is: "<<t.real<<"i + "<<t.img<<"j ";
}

//subtraction


complex Subtraction(complex c1, complex c2)
{
    complex s;
    s.real = c1.real - c2.real;
    s.img = c1.img - c2.img;

    cout<<"The Subtraction is: "<<s.real<<"i - "<<s.img<<"j ";
}


// multiplication



complex Multiplication(complex c1, complex c2)
{
    complex Mult;

    Mult.real = (c1.real*c2.real) - (c1.img*c2.img);
    Mult.img = (c1.real*c2.img) - (c1.img*c2.real);

    cout<<"The Multiplication is: "<<Mult.real<<"i + "<<Mult.img<<"j ";
}



// Division


complex Division(complex c1, complex c2)
{
    complex Div;

    Div.real = (c1.real*c2.real + c1.img*c2.img)/(c2.real*c2.real + c2.img*c2.img);
    Div.img = (c1.img*c2.real + c1.real*c2.img)/(c2.real*c2.real + c2.img*c2.img);

    cout<<"The Division is: "<<Div.real<<"i + "<<Div.img<<"j ";
}



int main()
{
    int choice;

    cout<<"1. Operations using Friend Functions"<<endl<<"2. Operations using Operator Overloading."<<endl;
    cout<<endl<<"Select the Choice: ";
    cin>>choice;
    cout<<endl;
    cout<<"================================================";
    cout<<endl;

    if(choice == 1)
    {
        complex a,b,c;

        complex obj1,obj2;

        cin>>obj1;
        cout<<endl;

        cin>>obj2;
        cout<<endl;

    // beginning of the friend function operations

        Addition(obj1,obj2);
        cout<<endl;
        Subtraction(obj1,obj2);
        cout<<endl;
        Multiplication(obj1,obj2);
        cout<<endl;
        Division(obj1,obj2);

        cout<<endl;
        cout<<"================================================";
        cout<<endl;
    }
    else
    {
        // beginning of the operator overloading operations functions

        if(choice == 2)
        {
            complex a,b,c;
            int opt,opt1=1;

        while(opt1 == 1)
        {
            cin>>a;
            cout<<endl;
            cin>>b;
            cout<<endl;


            cout<<"1.Addition\n2.Subtraction\n3.Multiplication";
            cout<<"\n4.Division\n5.Exit\n\n---Enter your choice-->  ";

            cin>>opt;


            switch(opt)
            {
                case 1:
                    c = a+b;
                    cout<<"\n\n";

                    cout<<" The Addition of the Numbers is: ";
                    cout<<c;
                    break;

                case 2:
                    c = a-b;

                    cout<<"\n\n";
                    cout<<" The Subtraction of the Numbers is: ";
                    cout<<c;
                    break;

                case 3:
                    c = a*b;

                    cout<<"\n\n";
                    cout<<" The Multiplication of the Numbers is: ";
                    cout<<c;
                    break;

                case 4:
                    c = a/b;


                    cout<<"\n\n";
                    cout<<" The Division of the Numbers is: ";
                    cout<<c;
                    break;


                case 5: return 0;

                    default: cout<<"\nInvalid choice\n";
                    break;
            }
            cout<<"\n\n\nContinue??? (1 for more)";
            cin>>opt1;
        }
        }
        else
        {
            cout<<"Wrong choice!!!!";
        }
    }

   return 0;
}
