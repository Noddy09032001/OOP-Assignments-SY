#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <time.h>

using namespace std;

class Librarian;
class Member;

class Book
{
    public:

    vector<string> title;
    vector<string> author;
    vector<string> genre;
    vector<int> id;
    vector<int> pages;
    vector<float> price;
    vector<int> quantity;

    public:

    Book()
    {
        title.push_back("Harry Potter and the Prizoner of Azkaban");
        title.push_back("Design of Machine Elements");
        title.push_back("A textbook of Thermodynamics ");
        title.push_back("Object Oriented Programming");
        title.push_back("Raavan: Orphan of Aryavarta");

        author.push_back("JK Rowling");
        author.push_back("VB Bhandari");
        author.push_back("Cengel and Boyle");
        author.push_back("Balaguruswamy");
        author.push_back("Amish Tripathi");

        genre.push_back("Fiction");
        genre.push_back("Mechanical Engineering");
        genre.push_back("Mechanical Engineering");
        genre.push_back("Computer Sciences");
        genre.push_back("Fiction");

        id.push_back(1);
        id.push_back(2);
        id.push_back(3);
        id.push_back(4);
        id.push_back(5);

        pages.push_back(100);
        pages.push_back(200);
        pages.push_back(300);
        pages.push_back(400);
        pages.push_back(500);

        price.push_back(1000);
        price.push_back(1000);
        price.push_back(1000);
        price.push_back(1000);
        price.push_back(1000);

        quantity.push_back(10);
        quantity.push_back(20);
        quantity.push_back(30);
        quantity.push_back(40);
        quantity.push_back(50);

    }

};

class Librarian : virtual public Book
{
    protected:

    string adminName;
    string adminPassword;

    vector<string> admins;
    vector<string> passwords;

    string bookname;
    string authorName;
    string genreName;
    int bookid;
    int bookpages;
    //int bookquantity;
    float bookprice;

    //Needed when we issue a book
    string bkname;     //  name of the book
    string domain;     //  genre of the book
    string writer;     //  name of the author

    int inserting; //Used as a counter


    public:

    int count; //Also used as a counter
    int bookquantity;
    //int inserting;

    Librarian()
    {
        admins.push_back("Niranjan_Dhokarikar");
        admins.push_back("Shrutish_Gadakh");
        admins.push_back("Sanket_Dhut");

        passwords.push_back("noddy0903");
        passwords.push_back("shru0603");
        passwords.push_back("sank0804");
    }

    friend class BookIssued;
    friend class Member;

    int adminDetails();              // user login for the librarian
    void AddBook();                    // adding new books
    void view();                     // viewing all the books
    void DeleteBook();              // deleting the book when issued
    int issuebook();                   // issue a book if it is there

};

int Librarian :: adminDetails()
{
    int i;
    int a = 0;
    cin.ignore();

    cout<<"Admin Name: ";
    cin>>adminName;
    //cin.ignore();
    //getline(cin,adminName);
    //cin.ignore();
    cout<<"Password: ";
    //cin.ignore();
    //getline(cin,adminPassword);

    cin>>adminPassword;

    for(i = 0;i<admins.size();i++)
    {
        if((adminName.compare(admins[i])) == 0 && (adminPassword.compare(passwords[i])) == 0)
        {
            a = 1;
            return(a);
        }
    }

    return(0);

}

void Librarian :: AddBook()
{
    Book b1;
    int i;
    int number;
    cout<<endl<<"Number of Books to be added: ";
    cin>>number;
    cout<<endl<<endl;

    for(i=0;i<number;i++)
    {
        cout<<"Enter the Book Details to be added: "<<endl;
        cout<<"Name: ";
        //cin.ignore();
        //getline(cin, bookname);
        cin>>bookname;
        title.push_back(bookname);

        cout<<endl<<"Author: ";
        //cin.ignore();
        //getline(cin, authorName);
        cin>>authorName;
        author.push_back(authorName);

        cout<<endl<<"Genre: ";
        cin>>genreName;
        genre.push_back(genreName);

        cout<<endl<<"Book ID: ";
        cin>>bookid;
        id.push_back(bookid);

        cout<<endl<<"Pages: ";
        cin>>bookpages;
        pages.push_back(bookpages);

        cout<<endl<<"Price: ";
        cin>>bookprice;
        price.push_back(bookprice);

        cout<<endl<<"Quantity: ";
        cin>>bookquantity;
        count = bookquantity;
        quantity.push_back(bookquantity);

       // update(bookname, authorName, genreName, bookid, bookpages, bookprice, bookquantity);
    }
}

void Librarian :: view()
{
    int i;
    cout<<"Avaliable Books: "<<endl<<endl;
    for(i=0;i<title.size();i++)
    {
        cout<<"Book "<<i+1<<": "<<endl;
        cout<<title[i]<<" , Author: "<<author[i]<<" , Genre: "<<genre[i]<<" , ID: "<<id[i]<<" , Number of Pages: "<<pages[i]<<" , Price: "<<price[i]<<"Rs ,";
        cout<<"Total Number of Books "<<quantity[i]<<"."<<endl;
        cout<<endl;
    }
}

int Librarian :: issuebook()
{
    int a,b;//inserting;
    fflush(stdin);

    cout<<endl<<"Genre of the Book: ";
    cin>>domain;
    cout<<endl<<"Name of the Author: ";
    //cin.ignore();
    //getline(cin,writer);
    cin>>writer;
    cout<<endl<<"Name of the Book: ";
    //cin.ignore();
    //getline(cin,bkname);
    cin>>bkname;

    cin.ignore();


    for(int i = 0;i<title.size();i++)
    {
        if((domain.compare(genre[i])) == 0 && (writer.compare(author[i])) == 0 && (bkname.compare(title[i])) == 0)
        {
            cout<<"Book Found...!!!!!!!!!!!!!"<<endl<<endl<<endl<<endl;
            a = i;
            //cout<<a;
            //quantity.at(a) = noddy--;
            //inserting = --noddy;
            //quantity[a] = inserting;
            b =1; 
        }
    }

    inserting = --count;
    quantity[a] = inserting;

    int i;
    cout<<"Avaliable Books: "<<endl<<endl;
    for(i=0;i<title.size();i++)
    {
        cout<<"Book "<<i+1<<": "<<endl;
        cout<<title[i]<<" , Author: "<<author[i]<<" , Genre: "<<genre[i]<<" , ID: "<<id[i]<<" , Number of Pages: "<<pages[i]<<" , Price: "<<price[i]<<"Rs ,";
        cout<<"Total Number of Books "<<quantity[i]<<"."<<endl;
        cout<<endl;
    }

    return(b);
}


void Librarian :: DeleteBook()
{
    vector<string>::iterator genreFind = find(genre.begin(), genre.end(), domain);
    vector<string>::iterator authorFind = find(author.begin(), author.end(), writer);
    vector<string>::iterator titleFind = find(title.begin(), title.end(), bkname);


    if (genreFind == genre.end() && authorFind == author.end() && titleFind == title.end())
    {
        cout << "That Book is not in there!" << endl;
    }
    else
    {
        genre.erase(genreFind);
        author.erase(authorFind);
        title.erase(titleFind);
    }

}


class Member : virtual public Book, virtual public Librarian
{
    protected:

    string name;
    int userId;
    string stream;
    string division;
    int year;


    public:

    void getDetails();
    friend class BookIssued;
    void records(Librarian& is2);
    void bookreturn(Librarian& is2);

};

void Member :: getDetails()
{
    cout<<"Name: ";
    cin.ignore();
    getline(cin, name);
    cout<<"User ID: ";
    cin>>userId;
    cout<<"Stream: ";
    cin>>stream;
    cout<<"Division: ";
    cin>>division;
    cout<<"Year: ";
    cin>>year;
    cout<<endl<<endl;
    cout<<"=====================================";
    cout<<endl<<endl;
}

void Member :: records(Librarian& is2)
{
    int yr, month, day;
    time_t t = time (NULL);
    struct tm tm = *localtime (&t);
    yr = tm.tm_year + 1900;
    month = tm.tm_mon + 1;
    day = tm.tm_mday;

    cout<<"Details of the Borrower -> "<<endl;
    cout<<"Name: "<<name;
    cout<<endl<<"User ID: "<<userId;
    cout<<endl<<"Stream/Branch: "<<stream;
    cout<<endl<<"Division: "<<division;
    cout<<endl<<"Year: "<<year;
    cout<<endl<<"Genre of the book: "<<is2.domain;
    cout<<endl<<"Name of the Book: "<<is2.bkname;
    cout<<endl<<"Author of the Book: "<<is2.writer;
    cout<<endl<<"Issue Date: "<<day<<"//"<<month<<"//"<<yr;

    //ofstream myFile;
    //myFile.open("Results_book.csv");

    //for(int i=0;i<100;i++)
    //{
        //myFile<<name<<","<<userId<<","<<stream<<","<<division<<","<<year<<","<<is2.domain<<","<<is2.bkname<<","<<is2.writer;

    //}


}

void Member::bookreturn(Librarian& is2)
{
    string nm;
    int c,i;
    cout<<endl<<endl;
    cout<<"Name of the student: ";
    cin>>nm;

    if((nm.compare(name)) == 0)
    {
        cout<<"Details of the book issued: ";
        cout<<endl<<"Genre of the book: "<<is2.domain;
        cout<<endl<<"Name of the Book: "<<is2.bkname;
        cout<<endl<<"Author of the Book: "<<is2.writer;

        for(i = 0;i<is2.title.size();i++)
        {
            if((is2.domain.compare(is2.genre[i])) == 0 && (is2.writer.compare(is2.author[i])) == 0 && (is2.bkname.compare(is2.title[i])) == 0)
            {
            c = i;
            }
        }


        int q = is2.inserting;

        is2.quantity[c] = ++q;


        cout<<endl<<endl<<"Available Books: "<<endl<<endl;
        for(i=0;i<is2.title.size();i++)
        {
            cout<<"Book "<<i+1<<": "<<endl;
            cout<<is2.title[i]<<" , Author: "<<is2.author[i]<<" , Genre: "<<is2.genre[i]<<" , ID: "<<is2.id[i]<<" , Number of Pages: "<<is2.pages[i]<<" , Price: "<<is2.price[i]<<"Rs ,";
            cout<<"Total Number of Books "<<is2.quantity[i]<<"."<<endl;
            cout<<endl;
        }

    }

}

// as this is friend class it can acess the protected members of the class Librarian
class BookIssued
{
    protected:

    public:

    int issuebook(Librarian& is1);
};

int BookIssued :: issuebook(Librarian& is1)
{
    cout<<endl<<"The details are as follows: "<<endl;


    cout<<endl<<"Genre of the book: "<<is1.domain;
    cout<<endl<<"Name of the Book: "<<is1.bkname;
    cout<<endl<<"Author of the Book: "<<is1.writer;

}


int main()
{
    Member m3;
    Librarian l1,l2;
    BookIssued bki1;
    Member m2;

    int choice,result,result2,option,opt;

    cout<<"Welcome...Library Management System"<<endl<<endl;

    cout<<"===================================================================";
    cout<<endl<<endl;

    while(true)
    {
        cout<<"1. Librarian"<<endl<<"2. Member: "<<endl<<endl;
        cout<<"-> Choice: ";
        cin>>choice;
        cout<<"===================================================================";
        cout<<endl<<endl;


        if(choice == 2)
        {
            //Librarian l2;
            cout<<"Welcome Members..Have a Good Day!!"<<endl<<endl;

            while(true)
            {
                cout<<endl<<endl<<"=======Menu========"<<endl<<endl;
                cout<<"1. Borrow Book: "<<endl<<"2. View Updates: "<<endl;
                cout<<endl<<"Choice -> ";
                cin>>opt;
                cout<<endl<<endl<<"====================="<<endl<<endl;

                switch(opt)
                {
                    case 1:

                        cout<<"Details of the book to be borrowed: ";
                        l2.issuebook();
                        break;

                    //case 2:


                    default:
                        exit(1);
                }
            }
            Member m1;

            m1.getDetails();
            cout<<endl;

        }
        else
        {
            if(choice == 1)
            {
                cout<<"Welcome Admin..Have a Good Day!!"<<endl<<endl;
                /*Librarian l1;
                BookIssued bki1;
                Member m2;*/

                result = l1.adminDetails();
                if(result == 1)
                {
                    while(true)
                    {
                        cout<<endl<<endl<<"=======Menu========"<<endl<<endl;
                        cout<<"1. Add New Book"<<endl<<"2. View Existing Book Records"<<endl<<"3. Issue a Book"<<endl<<"4. Student Records: "<<endl<<"5. Return Book"<<endl;
                        cout<<endl<<"Choice -> ";
                        cin>>option;
                        cout<<endl<<endl<<"====================="<<endl<<endl;

                        switch(option)
                        {
                            case 1:
                                l1.view();
                                l1.AddBook();
                                l2 = l1;
                                break;

                            case 2:
                                l1.view();
                                break;

                            case 3:

                                cout<<"Details of the book to be issued: ";
                                result2 = l1.issuebook();
                                if(result2 == 1)
                                {
                                    cout<<endl;
                                    //m2.getDetails();
                                    //cout<<endl;
                                    bki1.issuebook(l1);
                                    cout<<endl<<endl;
                                    //l1.view();
                                    cout<<endl<<endl;
                                    //l1.DeleteBook();
                                    cout<<endl<<endl;
                                    //l1.view();
                                }
                                else
                                {
                                    cout<<endl<<"Book Currently Unavailable!!!!!!!!"<<endl;
                                }
                                break;

                            case 4:
                                m2.getDetails();
                                m2.records(l1);
                                break;

                            case 5:
                                m2.bookreturn(l1);
                                break;

                            default:
                                exit(1);


                        }
                    }

                }
                else
                {
                    cout<<"Sorry Admin...Login credentials incorrect..!!!"<<endl<<endl;
                }
            }
            else
            {
                exit(1);
            }
        }
    }
}

