/*
    Samarth Ramkrushna Kamble (21142 F1-Batch)
    Assignment-7
    OOPCG Laboratory
    Date:- 02/12/2021

    Write a C++ program that creates an output file, writes information to it, closes the file,
    open it again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
using namespace std;

class FileHandling
{
private:
    ofstream fileOut; // Object of ofstream class created.
    ifstream fileIn;  // Object of ifstream class created.
    string s;

public:
    FileHandling() { s = ""; }
    void writeFile(bool x);
    void readFile();
};

// Function to write given data in the file.
void FileHandling::writeFile(bool x)
{
    cout << "Enter your data below:\n";
    if (x)
        fileOut.open("FILE", ios::app); // Opening in append mode.
    else
        fileOut.open("FILE", ios::out); // Opening in output mode(Removes previous data).
    cin.ignore();
    while (s != "-1")
    {
        getline(cin, s); // Taking line as an input.
        if (s != "-1")
            fileOut << s << "\n"; // Writing to the file.
    }
    fileOut.close(); // Closing the file.
}

// Function to read given data in the file.
void FileHandling::readFile()
{
    cout << endl;
    fileIn.open("FILE");
    if (!fileIn) // File fails to open.
    {
        cout << "\nNo file exists!!!";
        return; // End function here.
    }
    while (!fileIn.eof()) // While end of file is not reached
    {
        getline(fileIn, s); // Store the line in s.
        cout << s << "\n";  // Print s.
    }
    fileIn.close(); // Closing the file.
}

int main()
{
    bool menu = 1;
    FileHandling obj;
    while (menu)
    {
        // Menu and choice input
        cout << "\n\nMENU\n1.Write(append) the file.\n2.Overwrite the file.\n3.Read the file.\n4.Exit.\nEnter your choice: ";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            obj.writeFile(1);
        }
        else if (ch == 2)
        {
            obj.writeFile(0);
        }
        else if (ch == 3)
        {
            obj.readFile();
        }
        else if (ch == 4)
        {
            cout << "\n\nThank you!!!";
            menu = 0;
        }
        else
        {
            cout << "\n\nInvalid choice!!!";
        }
    }

    return 0;
}