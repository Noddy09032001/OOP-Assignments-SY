#include <string>
#include <iostream>
#include <vector>

using namespace std;

class db;

class dm
{
    float metres,centimetres;

    public:

    dm()
    {
        metres = 0;
        centimetres = 0;
    }

    void getData()
    {
        cout<<"Enter distance in Meters: ";
        cin>>metres;
        cout<<"Enter distance in Centimeters: ";
        cin>>centimetres;
    }

    friend void Addition(dm,db);
};


class db
{
    float feet,inches;

    public:

    db()
    {
        feet = 0;
        inches = 0;
    }

    void getdata()
    {
        cout<<"Enter distance in Feet: ";
        cin>>feet;
        cout<<"Enter distance in Inches: ";
        cin>>inches;
    }

    friend void Addition(dm,db);
};


void Addition(dm object1,db object2)
{
    int choice;
    cout<<"0. Distance in Meters and Centimeters."<<endl;
    cout<<"1. Distance in Feet and Inches."<<endl;
    cout<<"Enter choice {0/1}: ";
    cin>>choice;

    if(choice == 0)
    {
        cout<<"The distance is: "<<object1.metres + (object2.feet * (0.3048))<<"  Meters "<<object1.centimetres + (object2.inches * (2.54))<<"  Centimetres."<<endl;
    }
    else
    {
        if(choice == 1)
        {
            cout<<endl<<"The distance is: "<<object2.feet + (object1.metres * (3.2804))<<"  Feet "<<object2.inches + (object1.centimetres * (0.3937))<<"  Inches."<<endl;
        }
        else
        {
            cout<<"Galat choice";
        }
    }
}

int main()
{
    dm object1;
    object1.getData();

    cout<<endl;
    cout<<"================================================================================";
    cout<<endl;

    db object2;
    object2.getdata();

    cout<<endl;
    cout<<"================================================================================";
    cout<<endl;
    Addition(object1, object2);
    return 0;


}

