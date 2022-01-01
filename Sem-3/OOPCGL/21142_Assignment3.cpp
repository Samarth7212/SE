/*
    Samarth Ramkrushna Kamble (21142 F1-Batch)
    Assignment-3 Final-Version
    OOPCG Laboratory
    Date:- 12/11/2021

    Imagine a publishing company which does marketing for book and audio cassette versions. 
    Create a class publication that stores the title (a string) and price (type float) of publications. 
    From this class derive two classes: book which adds a page count (type int) and tape which adds a playing 
    time in minutes (type float). Write a program that instantiates the book and tape class, allows user to 
    enter data and displays the data members. 
    If an exception is caught, replace all the data member values with zero values.
*/

#include <bits/stdc++.h>
using namespace std;

class Publication
{
private:
    string title; //To store title.
    float price;  //To store price.

public:
    void addP();     //To add data of publication.
    void displayP(); //To display data of publication.
    string getTitle() { return this->title; }
    float getprice() { return this->price; }
    bool flag = 0;
    void setNull()
    {
        title = "NULL";
        price = 0;
    }
};

class Book : public Publication
{
private:
    int pagecount; //To store number of pages.

public:
    void addB();                         //To add data of book.
    void displayB();                     //To display data of book.
    void displayAllB(int, vector<Book>); //To display all books.
    int getPagecount() { return this->pagecount; }
};

class Tape : public Publication
{
private:
    float playTime; //To store play time of tape.

public:
    void addT();                         //To add data of tape.
    void displayT();                     //To display data of tape.
    void displayAllT(int, vector<Tape>); //To display all tapes.
    float getPlayTime() { return this->playTime; }
};

void Publication::addP()
{
    try
    {
        cout << "\nEnter title of publication: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        if (cin.fail() || price < 0) //If input fails OR price is negative.
        {
            flag = 1;
            throw price;             //Exception thrown.
        }
    }
    catch (...)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        price = 0;
        title = "NULL";
    }
}

//Displaying all Books' data.
void Book::displayAllB(int countB, vector<Book> v)
{
    //3 8 8 3
    cout << endl;
    cout << "   Book |        Title        | Page-count | Price ";
    cout << endl;
    for (int i = 0; i < countB; i++)
    {
        cout << setw(6) << i + 1 << "  |";
        cout << setw(13) << v.at(i).getTitle() << "        |";
        cout << setw(7) << v.at(i).getPagecount() << "     |";
        cout << setw(4) << v.at(i).getprice();
        cout << endl;
    }
    cout << "\n\n";
}

//Displaying all Tapes' data.
void Tape::displayAllT(int countT, vector<Tape> v)
{
    cout << endl;
    cout << "   Tape |        Title        | Play-Time  | Price ";
    cout << endl;
    for (int i = 0; i < countT; i++)
    {
        cout << setw(6) << i + 1 << "  |";
        cout << setw(13) << v.at(i).getTitle() << "        |";
        cout << setw(7) << v.at(i).getPlayTime() << "     |";
        cout << setw(4) << v.at(i).getprice();
        cout << endl;
    }
    cout << endl;
}

void Publication::displayP()
{

    cout << "\nTitle of the publication: " << title << endl;
    cout << "Price: " << price << endl;
}

void Tape::addT()
{
    try
    {
        addP();
        if (flag)
            throw playTime;
        cout << "\nEnter play-time(in minutes): ";
        cin >> playTime;
        if (cin.fail() || playTime < 0)
            throw playTime; //Exception thrown
    }
    catch (float PlayTime)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        playTime = 0.0; //Value set to default.
        setNull();
    }
}

void Tape::displayT()
{
    displayP();
    cout << "\nPlaytime: " << playTime << "\n";
}

void Book::addB()
{
    try
    {
        addP();
        cout << "\nEnter the page count: ";
        cin >> pagecount;
        if (flag)
            throw pagecount;
        if (cin.fail() || pagecount < 0)
            throw pagecount;
    }
    catch (...)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        pagecount = 0;
        setNull();
    }
}

void Book::displayB()
{
    displayP();
    cout << "\nPage count: " << pagecount << endl;
}

int main()
{
    vector<Book> bk; //Vector to store objects of book.
    vector<Tape> tp; //Vector to store objects of tape.

    //Temporary objects.
    Book tmp1;
    Tape tmp2;
    unsigned int ch;

    int countB = 0; //Count of books.
    int countT = 0; //Count of tapes.
    while (1)
    {
        //Printing Menu
        cout << "\n******PUBLICATION COMPANY******\n";
        cout << "\nMENU:\n1.Add book data.\n2.Display book data.\n3.Delete book.\n\n4.Add tape data.\n5.Display tape data.\n6.Delete tape.\n\n7.Show book column.\n8.Show tape column.\n\n9.Exit\n";
        cout << "Total number of books: " << countB << "\nTotal number of tapes: " << countT << endl;
        cout << "Enter your choice: ";

        //Taking input for menu.
        try
        {
            cin >> ch;
            if (cin.fail() || ch > 9)
                throw ch; //Exception thrown
        }
        catch (...) //If an exception is caught, still program will not terminate.
        {
            cin.clear(); //Clearing buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid choice!!\nRestarting...\n";
            continue;
        }

        vector<Book>::iterator itr = bk.begin();  //Iterator pointing at first book.
        vector<Tape>::iterator itr2 = tp.begin(); //Iterator pointing at first tape.

        //Switch case statements to handle options.
        switch (ch)
        {
        case 1:                 //Add book data.
            tmp1.addB();        //To take input of book data.
            bk.push_back(tmp1); //Book pushed in vector.
            countB++;           //Book count incremented.
            break;

        case 2: //Display book data.
            int b;
            try
            {
                cout << "\nEnter number of book: ";
                cin >> b;
                if (b > countB || b == 0 || cin.fail()) //If input given fails OR unavailable.
                    throw b;                            //Exception thrown
                else
                    bk[b - 1].displayB();
            }
            catch (...) //If an exception is caught, still program will not terminate.
            {
                cin.clear(); //Clearing buffer.
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nBook with this number does not exist!!\n";
            }
            break;

        case 3: //Delete book data.
            int del;
            try
            {
                cout << "\nEnter the number of book you want to delete: ";
                cin >> del;
                if (del > countB || del == 0 || cin.fail()) //If input given fails OR unavailable.
                    throw del;                              //Exception thrown
                else
                {
                    itr += del - 1; //Iterator placed at correct position.
                    bk.erase(itr);  //Object pointed by iterator is deleted.
                    countB--;       //Book count decremented.
                }
            }
            catch (...)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nBook with this number does not exist!!\n";
            }
            break;

        case 4:                 //Add tape data.
            tmp2.addT();        //To take input of Tape data.
            tp.push_back(tmp2); //Tape push backed in vector.
            countT++;           //Incrementing number of tapes.
            break;

        case 5: //Display tape data
            int t;
            try
            {
                cout << "Enter number of tape: ";
                cin >> t;
                if (t > countT || t == 0 || cin.fail()) //If input given fails OR unavailable.
                {
                    throw t; //Exception thrown
                }
                else
                    tp[t - 1].displayT();
            }
            catch (...) //If an exception is caught, still program will not terminate.
            {
                cout << "\nTape with this number does not exist!!\n";
                cin.clear(); //Clearing buffer.
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;

        case 6: //Delete tape data.
            int delt;
            try
            {
                cout << "\nEnter tape-number you want to delete: ";
                cin >> delt;
                if (cin.fail() || delt > countT || delt == 0) //If input given fails OR unavailable.
                    throw delt;                               //Exception thrown
                else
                {
                    itr2 += delt;   //Iterator placed at correct position.
                    tp.erase(itr2); //Object pointed by iterator is deleted.
                    countT--;       //Tape count decremented.
                }
            }
            catch (...)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nTape with this number does not exist!!\n";
            }
            break;

        case 7: //Book chart
            tmp1.displayAllB(countB, bk);
            break;

        case 8: //Tape chart
            tmp2.displayAllT(countT, tp);
            break;

        case 9:
            cout << "\nThank you!!!";
            abort();
            break;

        default:
            break;
        }
    }
    return 0;
}