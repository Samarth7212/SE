/*
    Samamrth Kamble
    21142 (F1-Batch)
    Date of completion: 12/05/22

    Problem Statement:
    Department maintains a student information. The file contains roll number, name,
    division and address. Allow user to add, delete information of student. Display
    information of particular employee. If record of student does not exist an appropriate
    message is displayed. If it is, then the system displays the student details. Use
    sequential file to main the data.
*/
#include <bits/stdc++.h>
using namespace std;

class Database
{
public:
    class Student
    {
    private:
        int rollNum;
        char name[100];
        char address[100];
        char division[100];

    public:
        friend class Database;
        Student() { rollNum = -1; }
    };
    Student std;
    void addData()
    {
        ofstream outf;
        cout << "\nEnter name: ";
        cin.ignore();
        cin.getline(std.name, 100);
        cout << "Enter roll number: ";
        cin >> std.rollNum;
        cout << "Enter division: ";
        cin >> std.division;
        cout << "Enter address: ";
        cin.ignore();
        cin.getline(std.address, 100);
        outf.open("database.dat", ios::app | ios::binary);
        outf.write((char *)&std, sizeof(std)) << flush;
        outf.close();
        cout << "\nSuccessfully added";
    }

    void deleteData()
    {
        bool flag = 0;
        int rn, x;
        string s;
        cout << "\nEnter roll number: ";
        cin >> rn;
        ifstream fin;
        ofstream fout;
        fout.open("newDB.dat", ios::app | ios::binary);
        fin.open("database.dat", ios::in | ios::binary);
        while (fin.read((char *)&std, sizeof(std)))
        {
            if (std.rollNum == rn)
                flag = 1;
            if (std.rollNum != rn)
                fout.write((char *)&std, sizeof(std)) << flush;
        }
        remove("database.dat");
        rename("newDB.dat", "database.dat");
        cout << (flag ? "\n Deleted roll number-" : "\nCould not find roll number-") << rn;
    }

    void searchRecord()
    {
        bool flag = 0;
        int rn;
        cout << "\nEnter roll number: ";
        cin >> rn;
        ifstream inf;
        inf.open("database.dat", ios::in | ios::binary);
        inf.seekg(0);
        inf.clear();
        int x;
        if (inf.is_open())
        {
            while (inf.read((char *)&std, sizeof(std)))
            {
                if (std.rollNum == rn)
                {
                    flag = 1;
                    cout << "\nEntry present";
                    cout << "\nName: " << std.name;
                    cout << "\nRoll number: " << std.rollNum;
                    cout << "\nDivision: " << std.division;
                    cout << "\nAddress: " << std.address;
                }
            }
            if (!flag)
                cout << "\nCould not find roll number-" << rn;
            inf.close();
        }
        else
            cout << "\nUnable to open";
    }

    void showAll()
    {
        ifstream fin;
        fin.open("database.dat", ios::in | ios::binary);
        if (fin.is_open())
        {
            int i = 1;
            while (fin.read((char *)&std, sizeof(std)))
            {
                cout << "\nStudent-" << (i++);
                cout << "\nName: " << std.name;
                cout << "\nRoll number: " << std.rollNum;
                cout << "\nDivision: " << std.division;
                cout << "\nAddress: " << std.address;
                cout << endl;
            }
            fin.close();
        }
        else
            cout << "\nCould not open";
    }

    void removeDB() { remove("database.dat"); }

} * dt;

int main()
{
    bool menu = 1;
    dt = new Database();
    while (menu)
    {
        int ch;
        cout << "\n\n1.Enter data\n2.Search data\n3.Delete data\n4.Show all\nEnter: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            dt->addData();
            break;

        case 2:
            dt->searchRecord();
            break;

        case 3:
            dt->deleteData();
            break;

        case 4:
            dt->showAll();
            break;

        case -1:
            // dt->removeDB();
            menu = 0;
            break;

        default:
            break;
        }
    }

    return 0;
}
/*
1.Enter data
2.Search data
3.Delete data
Enter: 1

Enter name: Samarth Kamble
Enter roll number: 21142
Enter division: F1
Enter address: Pune, Maharashtra

Successfully added

1.Enter data
2.Search data
3.Delete data
Enter: 1

Enter name: Test Student
Enter roll number: 11111
Enter division: F2
Enter address: India

Successfully added

1.Enter data
2.Search data
3.Delete data
Enter: 2

Enter roll number: 21142

Entry present
Name: Samarth Kamble
Roll number: 21142
Division: F1
Address: IndiaMaharashtra

1.Enter data
2.Search data
3.Delete data
Enter: 2

Enter roll number: 11111

Entry present
Name: Test Student
Roll number: 11111
Division: F2
Address: India

1.Enter data
2.Search data
3.Delete data
Enter: 3

Enter roll number: 11111

 Deleted roll number-11111

1.Enter data
2.Search data
3.Delete data
Enter: 2

Enter roll number: 11111

Could not find roll number-11111

1.Enter data
2.Search data
3.Delete data
Enter: -1
*/