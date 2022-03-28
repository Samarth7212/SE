/*
 Samarth Kamble
 21142 (F1-Batch)
 Date of start: 21/03/2022
 Date of completion: 28/03/2022

 Problem statement:
 Consider telephone book database of N clients. Make use of a hash table
 implementation to quickly look up client‘s telephone number. Make use of two
 collision handling techniques and compare them using number of comparisons
 required to find a set of telephone numbers (use linear probing with replacement and
 without replacement)
 */
#include <iostream>
#define SIZE 123
using namespace std;

class HashEntry
{
    long int phoneNumber;
    string name;

public:
    HashEntry()
    {
        this->name = "";
        this->phoneNumber = -1;
    }
    long int getPhoneNumber()
    {
        return phoneNumber;
    }
    string getName()
    {
        return name;
    }
    void setPhoneNumber(long int number)
    {
        this->phoneNumber = number;
    }
    void setName(string name)
    {
        this->name = name;
    }
};

class HashTable
{
    HashEntry arr[SIZE];
    int entryCount;

public:
    static int multiplyDigits(long int num)
    {
        int ans = 1;
        while (num)
        {
            int temp = ((num % 10));
            ans *= temp;
            num /= 10;
        }
        return ans % SIZE;
    }
    static int hash(long int key)
    {
        int hashCode = multiplyDigits(key);
        return hashCode;
    }
    HashTable()
    {
        entryCount = 0;
    }
    void makeEntry();
    void insertWithoutReplacement(long, string);
    void insertionWithReplacement(long, string);
    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i].getPhoneNumber() != -1)
                cout << "At "
                     << "index " << i << ": "
                     << "Phone number- "
                     << arr[i].getPhoneNumber() << " Name- "
                     << arr[i].getName() << endl;
        }
    }
    void search(long int number)
    {
        int comparisons = 0;
        int hashValue = hash(number);
        int initial = hashValue - 1;
        while (arr[hashValue].getPhoneNumber() != number)
        {
            if (arr[hashValue].getPhoneNumber() != -1)
                comparisons++;
            hashValue = (hashValue + 1) % SIZE;
            if (hashValue == initial && arr[hashValue].getPhoneNumber() == -1)
            {
                cout << "\nNot found\n";
                cout << "The comparisons required were " << comparisons << endl;
                return;
            }
        }
        cout << "\nFOUND " << arr[hashValue].getPhoneNumber() << " at index "
             << hashValue << endl;
        cout << "The comparisons required were " << comparisons << endl;
    }
} *HT = NULL;

void HashTable::makeEntry()
{
    long int num;
    string name;
    cout << "\nEnter contact number: ";
    cin >> num;
    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, name);
    if (entryCount >= SIZE)
    {
        cout << "\nHashTable is full\n";
        return;
    }
    int ch;
    cout
        << "\nEnter 1 to enter without replacement\nEnter 2 to enter with replacement\nEnter: ";
    cin >> ch;
    if (ch == 1)
        insertionWithReplacement(num, name);
    else
        insertionWithReplacement(num, name);
    entryCount++;
}

void HashTable::insertWithoutReplacement(long num, string name)
{

    int hashValue = hash(num);
    int position = hashValue;
    while ((arr[position]).getPhoneNumber() != -1)
    {
        position = (position + 1) % SIZE;
    }
    arr[position].setPhoneNumber(num);
    arr[position].setName(name);
}

void HashTable::insertionWithReplacement(long num, string name)
{
    int hashValue = hash(num);
    int position = hashValue;

    if (arr[hashValue].getPhoneNumber() == -1)
    {
        arr[hashValue].setPhoneNumber(num);
        arr[hashValue].setName(name);
    }
    else
    {
        int thisHashValue = hash(arr[position].getPhoneNumber());
        if (thisHashValue == position)
        {
            while ((arr[position]).getPhoneNumber() != -1)
            {
                position = (position + 1) % SIZE;
            }
            arr[position].setPhoneNumber(num);
            arr[position].setName(name);
        }
        else
        {
            long replacementNum = arr[position].getPhoneNumber();
            string replacementName = arr[position].getName();
            arr[position].setName(name);
            arr[position].setPhoneNumber(num);
            position = (position + 1) % SIZE;

            while ((arr[position]).getPhoneNumber() != -1)
            {
                position = (position + 1) % SIZE;
            }
            arr[position].setPhoneNumber(replacementNum);
            arr[position].setName(replacementName);
        }
    }
}

int main()
{
    HT = new HashTable();
    bool menu = 1;
    int ch;
    while (menu)
    {
        cout << "\n1.Make an entry\n2.Remove an entry\n3.Display\n4.Search\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            HT->makeEntry();
            break;
        case 2:

            break;
        case 3:
            HT->display();
            break;
        case 4:
            long int num;
            cout << "\nENter: ";
            cin >> num;
            HT->search(num);
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