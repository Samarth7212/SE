/*
    Samarth Kamble (21142 F1-Batch)
    DSAL Assignment-5
    Date of starting: 31/03/2022
    Date of completion: 11/04/2022

    Problem Statement:
    Implement all the functions of a dictionary (ADT) using hashing and handle collisions using separate chaining using linked list.
    Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique.
    Standard Operations: Insert (key, value),Find(key), Delete(key)
 */

#include <iostream>
#define SIZE 101
using namespace std;

class HashTable
{
public:
    class HashEntry;
    static int hashFunction(string key);
    static string capitalise(string &s);
    void insert(string key, string value);
    void deleteKey(string key);
    void findKey(string key);
    void displayHashTable();
    HashTable();

private:
    HashEntry *hashTable[SIZE];

public:
    class HashEntry
    {
        string word;
        string meaning;
        HashEntry *next;
        int nodeCount;
        friend class HashTable;

    public:
        HashEntry()
        {
            word = meaning = "";
            next = nullptr;
            nodeCount = 0;
        }
        HashEntry(string key, string value)
        {
            this->word = key;
            this->meaning = value;
            this->next = nullptr;
            nodeCount = -1;
        }
    };
} HT;

HashTable::HashTable()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = new HashEntry();
}

void HashTable::displayHashTable()
{
    HashEntry *temp = nullptr;
    for (int i = 0; i < SIZE; i++)
    {
        temp = hashTable[i];
        if (temp->next != nullptr)
        {
            cout << "\nBucket-" << i << ":" << endl;
            cout << "Node Count: " << temp->nodeCount << endl;
            temp = temp->next;
            int ct = 1;
            while (temp != nullptr)
            {
                if (temp != nullptr)
                {
                    cout << ct++ << ": " << temp->word << " ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
}

int HashTable::hashFunction(string key)
{
    int hashValue = 0;
    int temp = 0;
    int len = key.length();
    for (int i = 0; i < len; i++)
        hashValue += key[i];
    while (hashValue)
    {
        temp += hashValue % 100;
        hashValue /= 100;
    }
    hashValue = temp % 100;
    return hashValue;
}

string HashTable::capitalise(string &s)
{
    for (auto &ch : s)
        ch = (char)(ch & (~(1 << 5)));
    return s;
}

void HashTable::insert(string key, string value)
{
    key = capitalise(key);
    int hashValue = hashFunction(key);
    HashEntry *temp = hashTable[hashValue];
    temp->nodeCount++;
    while (temp->next != nullptr)
    {
        if (temp->word == key)
        {
            cout << "\nDuplicate entry!";
            return;
        }
        if (temp != nullptr)
            temp = temp->next;
    }
    if (temp->word == key)
    {
        cout << "\nDuplicate entry!";
        return;
    }
    temp->next = new HashEntry(key, value);
    cout << "\nWord added to dictionary.";
}

void HashTable::findKey(string key)
{
    int comparisons = 0;
    string tempKey = key;
    key = capitalise(key);
    int hashValue = hashFunction(key);
    HashEntry *temp = hashTable[hashValue];
    while (temp != nullptr)
    {
        if (temp != nullptr)
        {
            comparisons++;
            if (temp->word == key)
            {
                cout << "Key found!\n\n"
                     << tempKey << "\nMeaning: "
                     << temp->meaning << endl;
                cout << "Number of comparisons: " << comparisons - 1 << endl;
                return;
            }
            temp = temp->next;
        }
    }
    cout << "Key not found! " << endl;
    if (temp == nullptr)
        comparisons += 1;
    cout << "Number of comparisons: " << comparisons - 1 << endl;
}

void HashTable::deleteKey(string key)
{
    key = capitalise(key);
    HashEntry *tail = nullptr;
    HashEntry *temp = nullptr;
    int hashValue = hashFunction(key);
    temp = hashTable[hashValue];
    if (temp->next == nullptr)
    {
        cout << "Word does not exist!";
        return;
    }
    while (temp != nullptr)
    {
        tail = temp;
        if (temp != nullptr)
            temp = temp->next;
        if (temp == nullptr)
        {
            cout << "Word does not exist!";
            return;
        }
        if (temp->word == key)
        {
            if (temp != nullptr)
                tail->next = temp->next;
            else
                tail->next = nullptr;
            delete temp;
            temp = nullptr;
            return;
        }
    }
}

int main()
{
    bool menu = 1;
    int ch;
    string key, val;
    while (menu)
    {
        cout
            << "\nMENU\n1.Insert\n2.Find\n3.Delete\n4.Display HashTable\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter word: ";
            cin >> key;
            cout << "\nEnter value: ";
            cin.ignore();
            getline(cin, val);
            HT.insert(key, val);
            break;

        case 2:
            cout << "\nEnter word: ";
            cin >> key;
            HT.findKey(key);
            break;

        case 3:
            cout << "\nEnter word: ";
            cin >> key;
            HT.deleteKey(key);
            break;

        case 4:
            HT.displayHashTable();
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