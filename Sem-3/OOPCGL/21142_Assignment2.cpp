/*
    Samarth Ramkrushna Kamble (21142 F1-Batch)
    Assignment-2 (Final Version)
    OOPCG Laboratory
    Date:- 08/10/2021
*/

/*
Develop a program in C++ to create a database of student’s information system
containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group,
Contactaddress, Telephone number, Driving license no., copy constructor and other. 
Construct the database with suitable member functions. Make use of constructor, default constructor, 
copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/

//Necessary header files included.
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <ctime>
#include <sstream>
using namespace std;

//Template function used to handle failed cases for integers and long long integers.
template <typename T>
void validate_input(T &tmp)
{
    cin >> tmp;
    bool tmp_fails = cin.fail();

    //If input fails, this loop will be executed as long as input isn't a valid number.
    while (tmp_fails)
    {
        //Input buffer cleared
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input given!\nEnter again: ";

        //Input re-entered.
        cin >> tmp;

        //Condition re-checked.
        tmp_fails = cin.fail();
    }
}

//Function to validate the entered licence number.
void validate_LcNum(string &str)
{
    cin >> str;

    //Checks if length and first two letters are valid.
    bool cond = (str.length() == 15 && str[0] == 'M' && str[1] == 'H');

    //As long as condition is false, this loop is executed.
    while (!cond)
    {
        cout << "Invalid licence number!!\nEnter again: ";
        cin >> str;

        //Condition checked again.
        cond = (str.length() == 15 && str[0] == 'M' && str[1] == 'H');
    }
}

//Function to validate blood group.
void validate_BG(string &str)
{
    cin >> str;

    //Condition to check if blood group entered is valid OR not.
    bool tmp = (str == "O+ve") || (str == "A+ve") || (str == "B+ve") || (str == "AB+ve") || (str == "A-ve") || (str == "B-ve") || (str == "AB-ve");
    if (!tmp)
    {
        cout << "Blood group is not valid!!!";
        cin >> str;

        //Condition checked again.
        bool tmp = (str == "O+ve") || (str == "A+ve") || (str == "B+ve") || (str == "AB+ve") || (str == "A-ve") || (str == "B-ve") || (str == "AB-ve");
    }
}

//Function to validate phone number.
void validate_PhNum(long long &mobnum)
{
    cin >> mobnum;

    //Exception handled if input is not a number.
    bool tmp_fails = cin.fail();

    //As long as input fails, this loop is executed.
    while (tmp_fails)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input given!\nEnter again: ";
        cin >> mobnum;
        tmp_fails = cin.fail();
    }
    int ct = 0;
    long long copy_num = mobnum;

    //Loop to check if number is of 10 digits.
    while (copy_num != 0)
    {
        copy_num /= 10;
        ct++;
    }

    //If there are not 10 digits, function will be called again.
    if (ct != 10)
    {
        cout << "Number entered is not correct!!!\nEnter again: ";
        validate_PhNum(mobnum);
    }
}

//Function to validate date of birth.
void validate_dob(string &s)
{
    //Objects of ctime module created
    time_t ttime = time(nullptr);
    tm *local_time = localtime(&ttime);

    //Today's year, month and day are obtained.
    int year = 1900 + local_time->tm_year;
    int month = 1 + local_time->tm_mon;
    int day = local_time->tm_mday;

    //Valid form dd/mm/yyyy created.
    string todayDate = to_string(day) + '/' + to_string(month) + '/' + to_string(year);

    //Input taken.
    cout << "Enter your date of birth(dd/mm/yyyy): ";
    cin >> s;

    //Condition for length checked.
    bool cond = s[2] != 47 || s[5] != 47 || s.length() != 10;

    //As long as condition is true, this loop is executed.
    while (cond)
    {
        cout << "Invalid input!\nEnter again: ";
        cin >> s;
        cond = s[2] != 47 || s[5] != 47 || s.length() != 10;
    }

    int day_int, month_int, year_int;
    stringstream day_obj, month_obj, year_obj;

    //Conversion from string to int
    day_obj << s.substr(0, 2);
    day_obj >> day_int;

    month_obj << s.substr(3, 2);
    month_obj >> month_int;

    year_obj << s.substr(6, 4);
    year_obj >> year_int;

    //Message is created to display if wrong date is entered.
    string msg = "You cannot be born in future!!!";
    bool condition = true;

    //Conditions checked if the date entered is not greater than today's date.
    if (year_int > year)
        condition = false;
    if (year_int == year && month_int == month && day_int >= day)
        condition = false;
    if (year_int == year && month_int > month)
        condition = false;
    if (year_int == 0 || month_int == 0 || day_int == 0)
    {
        condition = false;
        msg = "This date does not exist!!\n";
    }

    //If condition is false, this code will be executed.
    if (!condition)
    {
        cout << msg;
        s = "";
        validate_dob(s);
    }
}

//Function to validate the division entered.
void validate_div(string &str)
{
    cin >> str;
    bool cond = (str == "A" || str == "C" || str == "B" || str == "D");

    //As long as condition is false, this loop is executed.
    while (!cond)
    {
        cout << "Not a valid div!\nEnter again: ";
        cin >> str;
        cond = (str == "A" || str == "C" || str == "B" || str == "D");
    }
}

//Class declaration
class StudentF;

//Class definition
class StudentP
{
    //Private data
private:
    string *name;
    string dob;
    int *roll_num;
    string *div;
    string *bg;

    //Public data
public:
    //Default constructor is declared.
    StudentP();

    //Static integer declared
    static int count;

    //Static functions declared.
    static void get_count()
    {
        cout << "\n*****Total " << count << " entries were made*****";
    }

    //Function to increment count.
    static void increment_count()
    {
        count++;
    }

    //Function to decrement count.
    static void decrement_count()
    {
        count--;
    }

    //Member functions of class, to accept and show the data.
    void getdata(StudentF *);
    void printdata(StudentF *);

    //Constructor and destructor declared.
    StudentP(const StudentP &);
    ~StudentP();
};

//Class definition.
class StudentF
{
    //Private data
private:
    string address;
    long long *mobnum;
    string *lcnum;

    //Friend class mentioned.
    friend class StudentP;

    //Public data
public:
    StudentF();

    //Member functions of class, to accept and show the data.
    void getfdata();
    void printfdata();

    //Constructor and destructor declared.
    StudentF(const StudentF &);
    ~StudentF();
};

//Default constructor defined
StudentP::StudentP()
{
    //Defalut values to data is given.
    name = new string;
    roll_num = new int;
    div = new string;
    bg = new string;
    dob = "dd/mm/yy";
}

//Default destructor defined
StudentP::~StudentP()
{
    //Allocated memory is made free.
    delete div;
    delete roll_num;
    delete bg;
}

//Getdata function definition
void StudentP::getdata(StudentF *st)
{
    StudentP::increment_count();
    cout << "\nStudent-" << count << "\n";
    cout << "Enter the name of student: ";

    //Line with spaces is taken as input.
    cin.ignore();
    getline(cin, *name);

    cout << "Enter your roll number: ";
    //Input validated
    validate_input(*roll_num);

    cout << "Enter div: ";
    //Input validated
    validate_div(*div);

    //Input validated
    validate_dob(dob);
    // (*st).getfdata();
    st->getfdata();

    cout << "Enter your blood group: ";
    //Input validated
    validate_BG(*bg);
}

//Printdata function defined.
inline void StudentP::printdata(StudentF *st)
{
    //All the data is printed.
    cout << setw(95) << setfill('-') << endl;
    cout << "\nName of student: " << *name << "\n";
    cout << "Roll number: " << *roll_num << "\n";
    cout << "Division: " << *div << "\n";
    cout << "Date of birth: " << dob << "\n";
    cout << "Blood group: " << *bg << "\n";
    // (*st).printfdata();
    st->printfdata();
}

//Printdata function defined.
inline void StudentF::printfdata()
{
    //All the data is printed.
    cout << "Mobile number: " << *mobnum << "\n";
    cout << "Licence number: " << *lcnum << "\n";
    cout << "Address: " << address << "\n";
}

//Getdata function defined.
void StudentF::getfdata()
{
    cout << "Enter your address: ";

    //Line with spaces is taken as input.
    cin.ignore();
    getline(cin, address);

    cout << "Enter Mobile number: ";
    //Input validated
    validate_PhNum(*mobnum);

    cout << "Enter your licence number: ";
    //Input validated
    validate_LcNum(*lcnum);
}

//Default constructor is defined.
StudentF::StudentF()
{
    //Defalut values to data is given.
    address = "";
    mobnum = new long long;
    lcnum = new string;
}

//Default destructor is defined.
StudentF::~StudentF()
{
    //Allocated memory is made free.
    delete mobnum;
    delete lcnum;
}

//Static variable is initialized as zero.
int StudentP::count = 0;

//Main function
int main()
{
    //Array of pointers is created.
    StudentP *objp[50];
    StudentF *objf[50];

    //Choice, current_count is declared
    int ch = -1;
    int cur_ct;

    //Condition variable declared.
    bool condition;

    //This loop is ececuted as long as choice is not zero, OR the user don't want to exit.
    while (ch != 0)
    {
        //Menu printed
        cout << "\nMAIN MENU\nPress 1 to create.\nPress 2 to display.\nPress 3 to update.\nPress 4 to delete.\nPress 5 to copy.\nPress 0 to exit.\n";

        //Entries present at that time is printed.
        cout << "Entries present at this moment: " << StudentP::count << "\n";

        //Asks user for choice.
        cout << "\nEnter your choice: ";
        validate_input(ch);

        //Copy pointer objects for both classes created.
        StudentP *copy_obj;
        StudentF *copy_obj2;

        //Switch statements to handle the menu.
        switch (ch)
        {
        case 1: //To take new entry.

            cout << "Enter the number of students: ";
            int num;

            //Input validated
            validate_input(num);

            cur_ct = 0;
            cur_ct += StudentP::count;
            for (int i = cur_ct; i < cur_ct + num; i++)
            {
                objp[i] = new StudentP;
                objf[i] = new StudentF;
                objp[i]->getdata(objf[i]);
                // (*objp[i]).getdata(objf[i]);
            }
            break;

        case 2: //To view entries present at particular position.

            cout << "Enter the number of student: ";
            int n;

            //Input validated
            validate_input(n);

            if (n <= StudentP::count && n != 0)
                objp[n - 1]->printdata(objf[n - 1]);
            // (objp[n]).printdata(&objf[n]);

            //Condition checked for non-existing entry.
            else if (n == 0 || n > StudentP::count)
                cout << "The number does not exist!\n";
            break;

        case 3: //To update the profile present at given number.

            int up;
            cout << "Enter the number to be updated: ";

            //Input validated
            validate_input(up);

            if (up <= StudentP::count && n != 0)
            {
                StudentP::decrement_count();
                objp[up - 1]->getdata(objf[up - 1]);
                // (objp[up - 1]).getdata(&objf[up - 1]);
            }

            //Condition checked for non-existing entry.
            else if (up == 0 || up > StudentP::count)
                cout << "The number does not exist!\n";
            break;

        case 4: //To delete entry at given count from the array.
            int nd;
            cout << "Enter the number of entry to be deleted: ";

            //Input validated
            validate_input(nd);

            if (nd <= StudentP::count && n != 0)
            {
                StudentP::decrement_count();
                for (int j = nd - 1; j < StudentP::count; j++)
                {
                    objp[j] = objp[j + 1];
                    objf[j] = objf[j + 1];
                }
            }
            //Condition checked for non-existing entry.
            else if (nd == 0 || nd > StudentP::count)
            {
                cout << "The number does not exist!\n";
            }
            break;

        case 5:
            int cp;
            cout << "Enter the number of student whose data is to be copied: ";

            //Input validated
            validate_input(cp);

            condition = (cp <= StudentP::count);

            //Condition checked for non-existing entry.
            while (!condition)
            {
                cout << "Number entered does not exist!!\nEnter again: ";
                cp = 0;
                validate_input(cp);
                condition = (cp <= StudentP::count);
            }

            //copy object has been allocated memory and data is copied
            //Copy constructor is called here.
            copy_obj = new StudentP(*objp[cp - 1]);
            copy_obj2 = new StudentF(*objf[cp - 1]);

            //The copied objed is put in the array of student objects.
            objp[StudentP::count] = new StudentP(*copy_obj);
            objf[StudentP::count] = new StudentF(*copy_obj2);

            StudentP::increment_count();
            break;

        case 0://Exit case
            cout << "Quitting...";
            break;

        default://Default case
            break;
        }
    }

    //Allocated memory to the student array is been made free.
    for (int i = 0; i < StudentP::count; i++)
    {
        delete objp[i];
        delete objf[i];
    }
    return 0;
}

//Copy constructor defined.
StudentP::StudentP(const StudentP &obj)
{
    //Data is copied from obj to the calling object.
    this->bg = obj.bg;
    this->name = obj.name;
    this->roll_num = obj.roll_num;
    this->div = obj.div;
    this->dob = obj.dob;
}

//Copy constructor defined.
StudentF::StudentF(const StudentF &obj)
{
    //Data is copied from obj to the calling object.
    this->lcnum = obj.lcnum;
    this->mobnum = obj.mobnum;
    this->address = obj.address;
}
