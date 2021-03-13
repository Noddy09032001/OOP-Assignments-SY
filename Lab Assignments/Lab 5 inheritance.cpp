#include <iostream>
#include <string>

using namespace std;

class Employee{
protected:
    int id;
    string name;
    string doj;

public:
    Employee(){
        cout << "Employee default constructor" << '\n';
        id = 0;
        name = "Nobody";
        doj = "1/00/2000";
    }

    Employee(int id, string name, string doj){
        cout << "Employee parameterized constructor" << '\n';
        this->id = id;
        this->name = name;
        this->doj = doj;
    }
};


class WageEmployee : virtual public Employee{
protected:
    int hours;
    int ratePerHour;

public:
    WageEmployee(){
        cout << "WageEmployee default constructor" << '\n';
        hours = 0;
        ratePerHour = 0;
    }

    WageEmployee(int id, string name, string doj, int hours, int ratePerHour) : Employee(id, name, doj){
        cout << "WageEmployee parameterized constructor" << '\n';
        this->hours = hours;
        this->ratePerHour = ratePerHour;
    }
};


class Manager : virtual public Employee{
protected:
    int numSubordinate;
    float basicSalary;
    float allowance;

public:
    Manager(){
        cout << "Manager default constructor" << '\n';
        numSubordinate = 0;
        basicSalary = 0;
        allowance = 0;
    }

    Manager(int id, string name, string doj, int numSubordinate, float basicSalary, float allowance) : Employee(id, name, doj){
        cout << "Manager parameterized constructor" << '\n';
        this->numSubordinate = numSubordinate;
        this->basicSalary = basicSalary;
        this->allowance = allowance;
    }
};


class SalesPerson : public WageEmployee{
protected:
    float expYears;

public:
    SalesPerson(){
        cout << "Salesperson default constructor" << '\n';
        expYears = 0;
    }

    SalesPerson(int id, string name, string doj, int hours, int ratePerHour, float expYears) : WageEmployee(id, name, doj, hours, ratePerHour){
        cout << "Salesperson parameterized constructor" << '\n';
        this->expYears = expYears;
    }
};


class SalesManager : public Manager, public SalesPerson{
public:
    SalesManager(){
        cout << "SalesManager default constructor" << '\n';
    }

    SalesManager(int id, string name, string doj, int hours, int ratePerHour, int numSubordinate, float basicSalary, float allowance, float expYears)
    :Employee(id, name, doj),
    Manager(id, name, doj, numSubordinate, basicSalary, allowance),
    SalesPerson(id, name, doj, hours, ratePerHour, expYears)
    {
        cout << "SalesManager parameterized constructor" << '\n';
    }

    void display(){
        cout << "\nid: " << id << '\n';
        cout << "Name: " << name << '\n';
        cout << "Date of joining: " << doj << '\n';
        cout << "Hours of work: " << hours << '\n';
        cout << "Rate per Hour in rupee: " << ratePerHour << '\n';
        cout << "Number of subordinates: " << numSubordinate << '\n';
        cout << "Basic salary: " << basicSalary << '\n';
        cout << "Allowance: " << allowance << '\n';
        cout << "Experience in years: " << expYears << "\n\n";


    }
};

int main()
{
    SalesManager noddy(109, "Niranjan Dhokarikar", "12th March, 2020", 7, 540, 15, 12000, 2000, 3);
    cout<<endl<<"=============================================================================================="<<endl;
    noddy.display();
    return 0;
}
