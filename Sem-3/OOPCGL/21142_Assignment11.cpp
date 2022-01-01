/*
    Samarth Ramkrushna Kamble (21142 F1-Batch)
    Assignment-11
    OOPCG Laboratory
    Date:- 15/12/21

    Write C++ program using STL for sorting and searching
    user defined records such as Item records (Item code,
    name, cost, quantity etc) using vector container.
*/

#include <iostream>  //Standard input output stream header file
#include <algorithm> //The header file for STL generic algorithms
#include <vector>    //The header file for the STL vector container
using namespace std;
class Item // Creating class Item
{
public:
    string name;                                                                // To store name of the item.
    int quantity;                                                               // To store quantity of the item.
    int cost;                                                                   // To store cost of the item.
    int code;                                                                   // To store code of the item.
    bool operator==(const Item &item1) { return (code == item1.code) ? 1 : 0; } // Returns true if code is matching
};
vector<Item> itemVec; // Vector to store Item objects.
vector<int> codes;    // Vector to store codes.

bool compare(const Item &item1, const Item &item2) { return item1.cost < item2.cost; } // Compares cost of items.

void insert()
{
    bool isWrongInput = 1; // This will get false after correct input.
    cout << "\nENTER THE FOLLOWING ITEM DETAILS: \n";
    Item item1; // Object created
    cout << "\nNAME : ";
    cin >> item1.name; // Name taken

    while (isWrongInput)
    {
        try
        {
            cout << "\nCOST: ";
            cin >> item1.cost;
            if (cin.fail() || item1.cost < 0) // Cost cannot be less than zero
                throw 0;
            isWrongInput = false;
        }
        catch (...) // Clearing stream
        {
            cout << "\nCOST CANNOT BE NEGATIVE OR INVALID!!!";
            cin.clear();
            cin.ignore(1000000000, '\n');
        }
    }
    isWrongInput = true;
    while (isWrongInput)
    {
        try
        {
            cout << "\nQUANTITY : ";
            cin >> item1.quantity;
            if (cin.fail() || item1.quantity < 0) // Quantity cannot be negative
                throw 0;
            isWrongInput = false;
        }
        catch (...) // Clearing stream
        {
            cout << "\nQUANTITY CANNOT BE NEGATIVE OR IVALID!!!";
            cin.clear();
            cin.ignore(1000000000, '\n');
        }
    }
    isWrongInput = true;
    while (isWrongInput)
    {
        try
        {
            cout << "\nCODE : ";
            cin >> item1.code;
            if (cin.fail() || find(codes.begin(), codes.end(), item1.code) != codes.end()) // Code checked if it is repeated
                throw 0;
            isWrongInput = false;
            codes.push_back(item1.code);
        }
        catch (...) // Clearing stream
        {
            cout << "\nCODE CANNTO BE NEGATIVE OR REPITITIVE";
            cin.clear();
            cin.ignore(1000000000, '\n');
        }
    }
    isWrongInput = true;
    itemVec.push_back(item1); // Item pushed int vector.
}

void printItem(Item &item1) // TO print data of each item
{
    // Printing all the data
    cout << "\n\nItem Name : " << item1.name;
    cout << "\nItem Quantity : " << item1.quantity;
    cout << "\nItem Cost : " << item1.cost;
    cout << "\nItem Code : " << item1.code;
    cout << "\n\n";
}

void display() { for_each(itemVec.begin(), itemVec.end(), printItem); } // Iterate for object by object and display its data.

void search()
{
    bool isWrongInput = 1;
    vector<Item>::iterator p; // Iterator created
    Item item1;               // Object created

    while (isWrongInput)
    {
        try
        {
            cout << "\nEnter Item code : ";
            cin >> item1.code;
            if (cin.fail() || item1.code < 0) // Code cannot be negative
                throw 0;
            isWrongInput = false;
        }
        catch (...) // Clearing stream
        {
            cout << "\nINVALID CODE ENCOUNTERED!!!";
            cin.clear();
            cin.ignore(1000000000, '\n');
        }
    }
    isWrongInput = true;
    p = find(itemVec.begin(), itemVec.end(), item1); // Finding for item in vector
    if (p == itemVec.end())                          // Pointing at end so not present.
        cout << "\nITEM NOT PRESENT IN LIST!!!";
    else // It is present
    {
        cout << "\nITEM PRESENT IN LIST!!!";
        printItem(*p); // Printing the found item.
    }
}

int main()
{
    bool menu = 1;
    int ch;
    while (menu)
    {
        cout << "\n\nMenu\n1.Insert\n2.Display\n3.Search\n4.Sort\n5.Exit\nEnter your choice : ";//Printing menu
        cin >> ch;//Taking choice input.

        switch (ch)
        {
        case 1:
            insert();//Inserting on choice 1
            break;

        case 2:
            display();//Displaying on chouce 2
            break;

        case 3:
            search();//Searching on
            break;

        case 4:
            sort(itemVec.begin(), itemVec.end(), compare);
            cout << "\n\n SORTED BY COST : ";
            display();
            break;
        case 5:
            menu = 0;
            break;
        default:
            cout << "\nINVALID CHOICE!!!";
            break;
        }
    }
    return 0;
}