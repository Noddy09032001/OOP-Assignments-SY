#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;
template<class noddy>

class Stack
{
    private:
    int top; //current top of stack
    int MaxTop; //max val for top
    noddy *S; //element array


    public:

    Stack(int MaxStackSize);
    ~Stack()
    {
        delete[] S;

    }
    int IsEmpty()const
    {
        return top==-1;

    }
    int IsFull()const
    {
        return top==MaxTop;

    }

    noddy Peek()const;
    void Push(noddy);
    //noddy Pop();
    void Pop()
    {
        if(top==-1)
        {
            cout<<"\n Stack underflow";
            return;
        }
        cout<<"\n Delete data is "<<S[top];
        top--;
    }

    void Display();

};

template<class noddy>
Stack<noddy>::Stack(int MaxStackSize)   // the stack constructor
{

    MaxTop=MaxStackSize-1;
    S=new noddy[MaxStackSize];
    top=-1;
}

template<class noddy>
noddy Stack<noddy>::Peek()const                // this function returns the top element of the stack
{
    if(IsEmpty())
        return 0;
    else
        return S[top];
}

template<class noddy>
void Stack<noddy>::Push(noddy x)                   // pushing the elements into the stack
{
    if(IsFull())
        cout<<"\nno memory()"; //add fails
    else
    {
        S[++top]=x;
    }
}

/*template<class noddy>                // removing the top most element of the stack
void Stack<noddy>::Pop(noddy x)
{
    //noddy x;
    if(/*IsEmpty()*//* top == -1)
    {
        cout<<"\nstack is empty\n";
        return;
    }
    else
    {
        cout<<"Popped element is: "<<S[top];
        //x=S[top--];
        //return x;
        top--;
    }
}*/

template<class noddy>                   // displaying the entie stack
void Stack<noddy>::Display()
{
    if(IsEmpty())
        cout<<"\nOut of bounds"; //delete fails
    else
        for(int i=top;i>=0;i--)
        {
            cout<<S[i]<<"\t";
        }
}


void menu()                         // generating the menu for the program
{
        cout<<endl<<"\n 1.Push\n 2.Pop\n 3.Peek\n 4.Display\n";
        cout<<endl<<"================================================================"<<endl;
}
int main()
{
    //Stack<int>obj(5);
    int ch,x,size,choice;
    float element;
    string n;

    cout<<"Enter the size of the stack: ";
    cin>>size;

    Stack<int>obj(size);
    Stack<float>obj1(size);
    Stack<string>obj2(size);

    cout<<endl<<"================================================================";

    cout<<endl<<"\n 1.Int\n 2.FLoat\n 3.String\n Choose the stack type: ";
    cin>>choice;

    do
    {

        cout<<endl<<"================================================================"<<endl;
        menu();
        cout<<"\nEnter the choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\nEnter the element to push into the stack\n";
            if(choice == 1)
            {
                for(int i = 0; i<size;i++)
                {
                    cin>>x;
                    obj.Push(x);
                }
            }
            else
            {
                if(choice == 2)
                {
                    for(int i = 0; i<size;i++)
                    {
                        cin>>element;
                        obj1.Push(element);
                    }
                }
                else
                {
                    for(int i = 0; i<size;i++)
                    {
                        cin>>n;
                        obj2.Push(n);
                    }
                }
            }
            cout<<endl<<"================================================================"<<endl;
            break;

            case 2:

            if(choice == 1)
            {
                obj.Pop();
                //if(x!=-1)
                //cout<<"\nPopped value is \t"<<x<<endl;
            }
            else
            {
                if(choice == 2)
                {
                    obj1.Pop();
                    //if(element!=-1)
                    //cout<<"\nPopped value is \t"<<element<<endl;
                }
                else
                {
                    obj2.Pop();
                    //if(n!=-1)
                    //cout<<"\nPopped value is \t"<<n<<endl;
                    //cout<<"noddy";
                }
            }
            cout<<endl<<"================================================================"<<endl;
            break;


            case 3:

            if(choice == 1)
            {
                x=obj.Peek();
                cout<<"\nThe top most value is \t"<<x<<endl;
            }
            else
            {
                if(choice == 2)
                {
                    element=obj1.Peek();
                    cout<<"\nThe top most value is \t"<<element<<endl;
                }
                else
                {
                    n=obj2.Peek();
                    cout<<"\nThe top most value is \t"<<n<<endl;
                }
            }
            cout<<endl<<"================================================================"<<endl;
            break;

            case 4:

            cout<<"The stack becomes: ";
            if(choice == 1)
            {
                obj.Display();
            }
            else
            {
                if(choice == 2)
                {
                    obj1.Display();
                }
                else
                {
                    obj2.Display();
                }
            }
            cout<<endl<<"================================================================"<<endl;
            break;
        }

    }while(ch>=1&&ch<=4);

    return 0;

}
