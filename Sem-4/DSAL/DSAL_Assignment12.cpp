/*
    Samamrth Kamble
    21142 (F1-Batch)

    Problem Statement:
    Department maintains a student information. The file contains roll number, name,
    division and address. Allow user to add, delete information of student. Display
    information of particular employee. If record of student does not exist an appropriate
    message is displayed. If it is, then the system displays the student details. Use
    sequential file to main the data.
*/
#include <bits/stdc++.h>
#define sp " "
using namespace std;

class Database
{
public:
    class Student
    {
    private:
        int rollNum;
        string name;
        string address;
        string division;

    public:
        friend class Database;
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
    void addData()
    {
        Student std;
        ofstream outf;
        cout << "\nEnter name: ";
        cin.ignore();
        getline(cin, std.name);
        cout << "Enter roll number: ";
        cin >> std.rollNum;
        cout << "Enter division: ";
        cin >> std.division;
        cout << "Enter address: ";
        cin.ignore();
        getline(cin, std.address);
        outf.open("database.txt", ios::app);
        outf << std.rollNum << endl
             << std.name << endl
             << std.division << endl
             << std.address << '\n'
             << endl;
        outf.close();
        cout << "\nSuccessfully added";
    }
    void search()
    {
        bool flag = 0;
        int rn;
        cout << "\nEnter roll number: ";
        cin >> rn;
        ifstream inf;
        inf.open("database.txt", ios::in);
        int x;
        if (inf.is_open())
        {
            while (!inf.eof())
            {
                inf >> x;
                if (x == 0)
                    break;
                if (x == rn)
                {
                    flag = 1;
                    cout << "\nEntry present";
                    string s;
                    inf.ignore();
                    getline(inf, s);
                    cout << "\nName: " << s;
                    cout << "\nRoll number: " << x;
                    inf >> s;
                    cout << "\nDivision: " << s;
                    inf.ignore();
                    getline(inf, s);
                    cout << "\nAddress: " << s;
                    inf.ignore();
                    getline(inf, s);
                }
                else
                {
                    for (int i = 0; i < 5; i++)
                    {
                        string s;
                        getline(inf, s);
                    }
                }
            }
            if (!flag)
                cout << "\nCould not find roll number-" << rn;
            inf.close();
        }
        else
            cout << "\nCould not open";
    }
    void deleteData()
    {
        bool flag = 0;
        int rn, x;
        string s;
        cout << "\nEnter roll number: ";
        cin >> rn;
        ofstream out;
        ifstream in;
        out.open("newDB.txt", ios::app);
        in.open("database.txt", ios::in);
        bool tmp = true;
        if (in.is_open() && out.is_open())
        {
            while (!in.eof())
            {
                in >> x;
                if (x == 0)
                    break;
                if (x == rn)
                {
                    flag = 1;
                    for (int i = 0; i < 5; i++)
                    {
                        string s;
                        getline(in, s);
                    }
                }
                else
                {
                    if (x == 0)
                        break;
                    out << x << endl;
                    in.ignore();
                    getline(in, s);
                    out << s << endl;
                    in >> s;
                    out << s << endl;
                    in.ignore();
                    getline(in, s);
                    out << s << endl;
                    s = "";
                    x = 0;
                    in.ignore();
                    out << "\n";
                }
            }
            remove("database.txt");
            rename("newDB.txt", "database.txt");
            cout << (flag ? "\n Deleted roll number-" : "\nCould not find roll number-") << rn;
            in.close();
            out.close();
        }
        else
            cout << "\nCould not open";
    }
} * dt;

int main()
{
    bool menu = 1;
    dt = new Database();
    while (menu)
    {
        int ch;
        cout << "\n\n1.Enter data\n2.Search data\n3.Delete data\nEnter: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            dt->addData();
            break;

        case 2:
            dt->search();
            break;

        case 3:
            dt->deleteData();
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