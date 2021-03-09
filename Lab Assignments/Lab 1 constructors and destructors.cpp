#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class student
{
    char *name;
    int roll_no;
    int age;
    string gender;
    float cgpa;

    vector<string> subjects;
    vector<float> marks;

    public:

    student()                                      // this is the default constructor
    {
        name = new char[10];
        roll_no = 1;
        age = 10;
        string n = "Nobody";
        cgpa = 0.0;

        int i=0;
        for(i=0; i<n.length() ;i++)
        {
            name[i] = n[i];
        }
        n[i] = '\0';

        subjects.push_back("ThermoDynamics");
        subjects.push_back("OOP");
        subjects.push_back("Machine Design");
        subjects.push_back("Fluid Engineering");
    }

    student(string n,int number,int ageyr,string a)                // this is a parameterised constructor
    {
        name = new char[n.length()+1];
        roll_no = number;
        age = ageyr;
        gender = a;

        int i = 0;
        for(i=0;i<n.length();i++)
        {
            name[i] = n[i];
        }
        name[i] = '\0';


        cout<<"Name: "<<name<<endl;
        cout<<"Roll number: "<<roll_no<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Gender: "<<gender<<endl;
        cout<<"Object created by parameterized constructor"<<endl<<endl;
        cout<<"=========================================================================";

    }

    student (student &noddy)                                     // this is a copy constructor
    {
        char *temp = new char[(strlen(noddy.name)+1)];
        strcpy(temp , noddy.name);
        name = temp;
        roll_no = noddy.roll_no;
        age = noddy.age;
        gender = noddy.gender;

        cout<<"Name: "<<name<<endl;
        cout<<"Roll number: "<<roll_no<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Gender: "<<gender<<endl;

        cout<<"Object Created by COPY  constructor "<<endl<<endl;
        cout<<"=========================================================================";
        cout<<endl;
    }


    ~student()
    {
        int i=0;
        cout<<"\nObject Deleted with Name  :  ";
        while(name[i] != '\0')
        {
            cout<<name[i];
            i++;
        }
        delete name;
        cout<<endl;
  }

    void getmarks()
    {
        cout<<"Name of Student : ";
        cin>>name;
        cout<<"\nRoll number of Student : ";
        cin>>roll_no;

        for(int i=0;i<subjects.size() ; i++)
        {
            cout<<"Enter Marks for "<<subjects[i]<<"  :  ";
            float temp ;
            cin>>temp;
            marks.push_back(temp);
        }
        cgpa = calculateCGPA();
    }

    int calculateCGPA()
    {
        float cgpa = 0;
        for(int i=0;i<marks.size();i++)
        {
            cgpa += marks[i];
        }
        return (cgpa/(400)) * 100;
    }


    void displayData();
};

void student:: displayData(){
        cout<<"\nData you're looking for is as : \n";
        cout<<"Name of Student : "<<name<<endl;
        cout<<"Roll number of Student : "<<roll_no<<endl;
        cout<<"Age of the student: "<<age<<endl;
        cout<<"CGPA of Student : "<<cgpa<<endl;
        cout<<"\nMarks in last 4 sub. : \n";
        for(int i=0; i <marks.size(); i++)
        {
            cout<<subjects[i]<<" : "<<marks[i]<<"\n";
        }
        cout<<""<<endl;
}

int main()
{
    student s1,s4;
    s1.displayData();

    string namestudent ;
    int roll ;
    int agestudent;
    string genderstudent;

    cout<<"\nEnter Student Name: ";
    cin>>namestudent;
    cout<<"\nEnter Student Roll number: ";
    cin>>roll;
    cout<<"\nEnter Student Age: ";
    cin>>agestudent;
    cout<<"\nEnter Student Gender: ";
    cin>>genderstudent;
    cout<<"=========================================================================";
    cout<<endl;

    student s2(namestudent,roll,agestudent,genderstudent);

    cout<<"=========================================================================";
    cout<<endl;

    student s3(s2);

    s4.getmarks();
    s4.displayData();

    return 0;
}
