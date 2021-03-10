#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Numbers
{
    float number1,number2;

    public:

    Numbers()
    {
        number1 = 1;
        number2 = 3;
    }


    float sum(float num1,float num2)
    {
        return num1+num2;
    }

    float sum(float num)
    {
        float no;
        cout<<"Enter a number to be added: ";
        cin>>no;


        return no + num;
    }

};

int main()
{
    Numbers obj;

    float a,b;
    cout<<"Enter the first number: ";
    cin>>a;
    cout<<endl<<"Enter the second number: ";
    cin>>b;

    cout<<obj.sum(a, b)<<endl;
    cout<<obj.sum(a)<<endl;

    return 0;
}
