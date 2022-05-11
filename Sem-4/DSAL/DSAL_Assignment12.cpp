/*
    Department maintains a student information. The file contains roll number, name,
    division and address. Allow user to add, delete information of student. Display
    information of particular employee. If record of student does not exist an appropriate
    message is displayed. If it is, then the system displays the student details. Use
    sequential file to main the data.
*/

#include <iostream>
#include <fstream>
using namespace std;

class Student
{
    int rollNum;
    string name;
    string division;
    string address;

public:
    Student()
    {
        name = "";
        rollNum = -1;
        division = "";
        address = "";
    }
    Student(string name, int roll, string div, string addr)
    {
        this->name = name;
        this->rollNum = roll;
        this->division = div;
        this->address = addr;
    }
};

class Database
{
    ofstream outf;
    ifstream inf;

public:
    void addData()
    {
    }

    void search()
    {
    }

    void deleteData()
    {
    }
};

int main()
{
    bool menu = 1;
    while (menu)
    {
        int ch;
        cout << "\n\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            break;

        case -1:
            menu = 0;
            break;

        default:
            break;
        }
    }

    return 0;
}