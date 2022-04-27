#include <iostream>
#include <limits>
using namespace std;

class Complex
{
    /*Class Complex stores real and imaginary values, and defines methods to be carried out on values.*/
private:
    //real and img are the variables to be used.
    float real, img;

public:
    Complex()
    {
        //Default constructor sets value of real and img to 0.
        real = 0;
        img = 0;
    }

    //Operators overloaded
    Complex operator+(Complex &obj);                           //Addition
    Complex operator-(Complex &obj);                           //Subtraction
    Complex operator*(Complex &obj);                           //Multiplication
    friend istream &operator>>(istream &input, Complex &obj);  //Input
    friend ostream &operator<<(ostream &output, Complex &obj); //Output
    void display(Complex &obj);                                //Function to display final result
    void menu(Complex &obj1, Complex &obj2);                   //Function to create menu.
    void restart(Complex &obj1, Complex &obj2);                //Function to continue the calculation.

    //Functions to carry out addition, subtraction and multiplication
    void addition(Complex &obj1, Complex &obj2)
    {
        Complex c3 = obj1 + obj2;
        cout << c3;
    }
    void subtraction(Complex &obj1, Complex &obj2)
    {
        Complex c3 = obj1 - obj2;
        cout << c3;
    }
    void multiplication(Complex &obj1, Complex &obj2)
    {
        Complex c3 = obj1 * obj2;
        cout << c3;
    }
}; //Class declaration ends here.

Complex Complex::operator+(Complex &obj)
{
    //Creates a temporary object
    Complex tmp;
    //Carries out addition of real and imaginary numbers
    tmp.real = obj.real + real;
    tmp.img = obj.img + img;
    //Object returned
    return tmp;
}

Complex Complex::operator-(Complex &obj)
{
    //Creates a temporary object
    Complex tmp;
    //Carries out subtraction of real and imaginary numbers
    tmp.real = real - obj.real;
    tmp.img = img - obj.img;
    return tmp;
}

Complex Complex::operator*(Complex &obj)
{
    //Creates a temporary object
    Complex tmp;
    //Carries out multiplication of real and imaginary numbers
    tmp.real = obj.real * real;
    tmp.img = obj.img * (-1) * img;
    return tmp;
}

istream &operator>>(istream &input, Complex &obj)
{
    cout << "Do you want to use default value(yes/no): ";
    string choice;
    input >> choice;
    if (choice == "no")
    {
        //The overloaded istream operator takes input of both reaal and imaginary part
        cout << "\nEnter the real part: ";
        input >> obj.real;
        bool rfail = input.fail(); //Checks if the input entered is valid OR not.Returns true if the input is invalid.
        while (rfail)              //As long as input is invalid, this loop will be executed.
        {
            //If input is invalid, clears the input and forces to enter input again till valid input is detected.
            input.clear();
            input.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the real number again: ";
            input >> obj.real;
            rfail = input.fail();//If input fails, value will be set to true.
        }

        cout << "\nEnter the imaginary number: ";
        input >> obj.img;
        bool ifail = input.fail();
        while (ifail)
        {
            input.clear();
            input.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the imaginary number again: ";
            input >> obj.img;
            ifail = input.fail();//If input fails value will be set to true.
        }
    }
    else if (choice == "yes")
    {
        // (0+0i) value will be set
        cout << "Using default values...\n";
    }
    return input; //Object returned
}

ostream &operator<<(ostream &output, Complex &obj)
{
    //The overloaded ostream operator outputs the complex number in a+bi form.
    //Manipulators used here takes care of the middle sign of the output.
    output << "\nresult is: " << noshowpos << obj.real;
    output << showpos << obj.img << "i\n";
    return output;
}
void Complex::restart(Complex &obj1, Complex &obj2)
{
    //This function asks user to continue OR not.
    cout << "\nDo you want to continue? (y/n):";
    char a;
    cin >> a;
    if (a == 'y')
    {
        menu(obj1, obj2); //Menu is initialized again for current set of inputs.
    }

    else if (a == 'n')
    {
        cout << "\nThank you!!!"; //Menu closed.
    }

    else
    {
        //Invalid input case handled.
        cout << "Invalid input!\nEnter again";
        restart(obj1, obj2);
    }
}

void Complex::menu(Complex &obj1, Complex &obj2)
{
    cout << "\nPress 1 for Addition.\n";
    cout << "Press 2 for Subtraction.\n";
    cout << "Press 1 for Multiplication.\n";
    int ch;
    cout << "Enter your choice: ";
    cin >> ch;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice detected!!!\nEnter your choice again: ";
        cin >> ch;
    }
    //Switch statements to handle choices.
    switch (ch)
    {
    case 1:
        addition(obj1, obj2);
        restart(obj1, obj2);
        break;
    case 2:
        subtraction(obj1, obj2);
        restart(obj1, obj2);
        break;
    case 3:
        multiplication(obj1, obj2);
        restart(obj1, obj2);
        break;

    default:
        cout << "Invalid choice detected!\n";
        restart(obj1, obj2);
        break;
    }
}

int main()
{
    //Driver code:
    //tmp works as temporary object to initialize calculator.
    Complex c1, c2, tmp;

    cout << "Number-1: \n";
    cin >> c1;
    cout << "Number-2: \n";
    cin >> c2;
    tmp.menu(c1, c2);

    return 0;
}
