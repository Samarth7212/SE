/*
    Samarth Ramkrushna Kamble (21142 F1-Batch)
    Assignment-8 Final Version
    OOPCG Laboratory
    Date:- 24/11/2021

    Write a function template for selection sort that inputs, 
    sorts and outputs an integer array and a float array.
*/

#include <bits/stdc++.h>
using namespace std;

//Template function to handle the given numeric data type.
template <typename T>
void swapData(T &x, T &y, int i, int k)
{
    if (i == k) //When indices arre same, nothing to swap.
        return;
    // printf("\ti:%d,k:%d ", i, k);
    //Swap values.
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

//Template function to handle the given numeric data type.
template <typename T>
void selectionSort(T arr[], int n) //Selection Sorting function.
{
    int i, j, k;
    j = k = i = 0;

    for (i = 0; i < n - 1; i++) //Iterate from 0 to n-2.
    {
        for (j = k = i; j < n; j++) //Initially j and k are pointing on ith index.
        {
            if (arr[j] < arr[k])
                k = j; //k will store index of lowest element in array from i to n.
        }
        // cout << "Current array: ";
        // for (int p = 0; p < n; p++)
        // {
        // cout << arr[p] << " ";
        // }
        // swapData(arr[i], arr[k], i, k);
        // cout << "\n\n";
    }

    cout << "\n\nSorted array: ";
    for (int i = 0; i < n; i++) //Printing sorted array.
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    while (1)
    {
        int ch, sz = 0;   //Necessary variables.
        int *arr1;        //Array pointer for int.
        float *arr2;      //Array pointer for float.
        cout << "\nMENU"; //Printing menu.
        cout << "\n1.Integer array.\n2.Float array.\n3.Exit\nEnter your choice: ";
        cin >> ch; //Taking choice input.
        switch (ch)
        {
        case 1: //Integer array
            cout << "Enter length: ";
            cin >> sz;
            arr1 = new int[sz];
            for (int i = 0; i < sz; i++)
            {
                printf("Enter element-%d: ", i + 1);
                cin >> arr1[i];
            }
            selectionSort(arr1, sz);
            break;

        case 2: //Float array
            cout << "Enter length: ";
            cin >> sz;
            arr2 = new float[sz];
            for (int i = 0; i < sz; i++)
            {
                printf("Enter element-%d: ", i + 1);
                cin >> arr2[i];
            }
            cout << endl;
            selectionSort(arr2, sz);
            break;

        case 3: //Exit the program.
            cout << "\nThank you!!";
            delete[] arr1; //Deleting dynamically allocated memory
            delete[] arr2; //Deleting dynamically allocated memory
            abort();       //Exit the code.
            break;

        default:
            cout << "\n\nInvalid choice!!!";
            break;
        }
    }
    return 0;
}
