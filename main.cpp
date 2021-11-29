#include <iostream>
#include <fstream>
using namespace std;
int n;
// **Main class**
class Student
{

private:
    char name[20], rollno[10], branch[10];
    int sem;

public:
    void input();
    void display();
};
void Student::input()
{
    fstream database;
    database.open("database.txt", ios::app);

    cout << "\nEnter Name:";
    cin >> name;
    database << "Name: " << name << endl;
    cout << "\nEnter Rollno.: ";
    cin >> rollno;
    database << "Roll No: " << rollno << endl;
    cout << "\nEnter Branch:";
    cin >> branch;
    database << "Branch: " << branch << endl;
    cout << "\nEnter Sem:";
    cin >> sem;
    database << "Sem: " << sem << endl;

    database.close();
}
void Student::display()
{
    cout << "\nStudent Details: " << endl;
    cout << "\n****" << endl;
    cout << "\nName:" << name << endl;
    cout << "\nRollno.:" << rollno << endl;
    cout << "\nBranch:" << branch << endl;
    cout << "\nSem:" << sem << endl;
}

// **Marks**
class marks : public Student
{
    int sub1;
    int sub2;
    int sub3;
    int per;

public:
    void getdata()
    {
        fstream database;
        database.open("database.txt", ios::app);
        input();
        cout << "\nEnter the marks1:";
        cin >> sub1;
        database << "Subject 1: " << sub1 << endl;
        cout << "\nEnter the marks2:";
        cin >> sub2;
        database << "Subject 2: " << sub2 << endl;
        cout << "\nEnter the marks3:";
        cin >> sub3;
        database << "Subject 3: " << sub3 << endl;

        database.close();
    }
    void putdata()
    {
        display();
        cout << endl << "\nMarks Details:";
        cout << endl << "\n****";

        cout << endl << "\nMarks1:" << sub1;
        cout << endl << "\nMarks2:" << sub2;
        cout << endl << "\nMarks3:" << sub3;
        per = (sub1 + sub2 + sub3) / 3;
        cout << endl << "\nTotal percentage:" << per;
        if (per >= 85)
            cout << endl << "\nGrade A+";
        else if (per >= 60)
            cout << endl << "\nGrade A";
        else if (per >= 50)
            cout << endl << "\nGrade B";
        else
            cout << endl << "\nGrade C";
    }
};
// ***Sports***
class sports : public Student
{
private:
    string player_name;
    string city;
    int age;
    string hobby;
    string game;

public:
    int insert();
    int show();
};

int sports::insert()
{
    fstream database;

    database.open("database.txt", ios::app);

    int choice;
    int interest;

    cout << "1. football" << endl;
    cout << "2. cricket" << endl;
    cout << "3. badminton" << endl;
    cout << "Choose one of the sports mention below: " << endl;

    cin >> choice;

    if (choice == 1)
    {
        string game = "football";
        cout << "Enter your name: ";
        cin >> player_name;
        database << "Player name: " << player_name << endl;
        cout << "Enter your city: ";
        cin >> city;
        database << "City: " << city << endl;
        cout << "Enter your age: ";
        cin >> age;
        database << "Age: " << age << endl;

        cout << "1. player" << endl;
        cout << "2. goal keeper" << endl;
        cout << "Choose one of the options mention below: ";
        cin >> interest;
        if (interest == 1)
        {
            string hobby = "player";
            database << "player" << endl;
        }
        else
        {
            string hobby = "goal keeper";
            database << "goal keeper" << endl;
        }
    }

    else if (choice == 2)
    {
        string game = "cricket";
        cout << "Enter your name: ";
        cin >> player_name;
        database << "Player name: " << player_name << endl;
        cout << "Enter your city: ";
        cin >> city;
        database << "City: " << city << endl;
        cout << "Enter your age: ";
        cin >> age;
        database << "Age: " << age << endl;

        cout << "1. batsman" << endl;
        cout << "2. baller" << endl;
        cout << "3. wicket keeper" << endl;
        cout << "Choose one of the options mention below: ";
        cin >> interest;
        if (interest == 1)
        {
            string hobby = "batsman";
            database << "Batsman" << endl;
        }
        else if (interest == 2)
        {
            string hobby = "baller";
            database << "Baller" << endl;
        }
        else
        {
            string hobby = "wicket keeper";
            database << "wicket keeper" << endl;
        }
    }

    else if (choice == 3)
    {
        string game = "badminton";
        cout << "Enter your name: ";
        cin >> player_name;
        database << "Player name: " << player_name << endl;
        cout << "Enter your city: ";
        cin >> city;
        database << "City: " << city << endl;
        cout << "Enter your age: ";
        cin >> age;
        database << "Age: " << age << endl;
        string hobby = "player";
        database.close();
    }

    else
    {
        cout << "Invalid input";
    }
    return 0;
}

int sports::show()
{
    cout << "You " << player_name << " from " << city << " of age " << age << " have successfully registered " << endl;
    return 0;
}

// **Payment**
class Payment : public Student
{
    long static int y1, y2, y3, y4, h; //Constant values of academic and hostel fees
    long int excess, remaining, paid;
    int year;
    char type; // Hosteller or Dayscholar

public:
    void get();                                         //Takes input of students details
    void fees(int year, char type, long int paid);      //This function tells how much fees has to be paid
    void show();                                        //Displays students record
};
long int Payment::y1 = 150700;
long int Payment::y2 = 150300;
long int Payment::y3 = 150600;
long int Payment::y4 = 180200;
long int Payment::h = 100320;

void Payment::fees(int year, char type, long int paid)
{
    // Year 1
    if (year == 1)
    {
        cout << "\t\nYour academic fees is " << y1 << endl;

        if (type == 'd') // Dayscholar
        {
            cout << "\t\nTotal fees to be paid is " << y1 << endl;
            cout << "\nThe total amount you have paid amount is " << paid << endl;

            if (paid > y1)
            {
                excess = paid - y1;
                cout << "\n......You have paid excess amount  ...... " << endl;
                cout << "\nThe amount is " << excess << endl;
            }
            else if (paid < y1)
            {
                remaining = y1 - paid;
                cout << "\nThe remaining balance to be paid is " << remaining << endl;
            }
            else
            {
                cout << "\nYou have paid the total fee." << endl;
            }
        }
        else if (type == 'h') // Hosteller
        {
            cout << "\t\nYour hostel fees is " << h << endl;
            cout << "\t\nTotal fees to be paid is " << y1 + h << endl;
            cout << "\nThe total amount you have paid amount is " << paid << endl;

            if (paid > y1 + h)
            {
                excess = paid - (y1 + h);
                cout << "\n......You have paid excess amount......" << endl;
                cout << "\nThe amount is " << excess << endl;
            }
            else if (paid < y1 + h)
            {
                remaining = (y1 + h) - paid;
                cout << "\nThe remaining balance to be paid is " << remaining << endl;
            }
            else
            {
                cout << "\nYou have paid the total fee." << endl;
            }
        }
        else
            cout << "\nWrong input" << endl;
    }
    // Year 2
    else if (year == 2)
    {
        cout << "\t\nYour academic fees is " << y3 << endl;

        if (type == 'd')
        {
            cout << "\t\nTotal fees to be paid is " << y3 << endl;
            cout << "\nThe total amount of fees you have paid is " << paid << endl;

            if (paid > y3)
            {
                excess = paid - y3;
                cout << "\n......You have paid excess amount  ...... " << endl;
                cout << "\nThe amount is " << excess << endl;
            }
            else if (paid < y3)
            {
                remaining = y3 - paid;
                cout << "\nThe remaining balance to be paid is " << remaining << endl;
            }
            else
            {
                cout << "\nYou have paid the total fee" << endl;
            }
        }
        else if (type == 'h')
        {
            cout << "\t\nYour hostel fees is " << h << endl;
            cout << "\t\nTotal fees to be paid is " << y3 + h << endl;
            cout << "\nThe total amount of fee you have paid is  " << paid << endl;

            if (paid > y3 + h)
            {
                excess = paid - (y3 + h);
                cout << "\n......You have paid excess amount......" << endl;
                cout << "\nThe amount is " << excess << endl;
            }
            else if (paid < y3 + h)
            {
                remaining = (y3 + h) - paid;
                cout << "\nThe remaining balance to be paid is " << remaining << endl;
            }
            else
            {
                cout << "\nYou have paid the total fee" << endl;
            }
        }
        else
            cout << "\nWrong input" << endl;
    }
    // Year 3
    else if (year == 3)
    {
        cout << "\t\nYour academic fees is " << y3 << endl;

        if (type == 'd')
        {
            cout << "\t\nTotal fees to be paid is " << y3 << endl;
            cout << "\nThe total amount of fees you have paid is " << paid << endl;

            if (paid > y3)
            {
                excess = paid - y3;
                cout << "\n......You have paid excess amount  ...... " << endl;
                cout << "\nThe amount is " << excess << endl;
            }
            else if (paid < y3)
            {
                remaining = y3 - paid;
                cout << "\nThe remaining balance to be paid is " << remaining << endl;
            }
            else
            {
                cout << "\nYou have paid the total fee" << endl;
            }
        }
        else if (type == 'h')
        {
            cout << "\t\nYour hostel fees is " << h << endl;
            cout << "\t\nTotal fees to be paid is " << y3 + h << endl;
            cout << "\nThe total amount of fee you have paid is " << paid << endl;

            if (paid > y3 + h)
            {
                excess = paid - (y3 + h);
                cout << "\n......You have paid excess amount......" << endl;
                cout << "\nThe amount is " << excess << endl;
            }
            else if (paid < y3 + h)
            {
                remaining = (y3 + h) - paid;
                cout << "\nThe remaining balance to be paid is " << remaining << endl;
            }
            else
            {
                cout << "\nYou have paid the total fee" << endl;
            }
        }
        else
            cout << "\nWrong input" << endl;
    }
    // Year 4
    else if (year == 4)
    {
        cout << "\t\nYour academic fees is " << y4 << endl;

        if (type == 'd')
        {
            cout << "\t\nTotal fees to be paid is " << y4 << endl;
            cout << "\nThe total amount of fees you have paid is " << paid << endl;

            if (paid > y4)
            {
                excess = paid - y4;
                cout << "\n......You have paid excess amount  ...... " << endl;
                cout << "\nThe amount is " << excess << endl;
            }
            else if (paid < y4)
            {
                remaining = y4 - paid;
                cout << "\nThe remaining balance to be paid is " << remaining << endl;
            }
            else
            {
                cout << "\nYou have paid the total fee" << endl;
            }
        }
        else if (type == 'h')
        {
            cout << "\t\nYour hostel fees is " << h << endl;
            cout << "\t\nTotal fees to be paid is " << y4 + h << endl;
            cout << "\nThe amount of fee you have paid is " << paid << endl;

            if (paid > y4 + h)
            {
                excess = paid - (y4 + h);
                cout << "\n......You have paid excess amount......" << endl;
                cout << "\nThe amount is " << excess << endl;
            }
            else if (paid < y4 + h)
            {
                remaining = (y4 + h) - paid;
                cout << "\nThe remaining balance to be paid is " << remaining << endl;
            }
            else
            {
                cout << "\nYou have paid the total fee" << endl;
            }
        }
        else
            cout << "\nWrong input" << endl;
    }
}
void Payment::get()
{
    fstream database;
    database.open("database.txt", ios::app);
    input();    // Called from main class
    cout << "Enter you are in which year" << endl;
    cin >> year;
    database << "Year: " << year << endl;
    cout << "Enter h for hosteller and d for dayschollar" << endl;
    cin >> type;
    database << "Type: " << type << endl;
    cout << "Enter the amount of fee you have paid" << endl;
    cin >> paid;
    database << "Amount paid: " << paid << endl;
    database.close();
}

void Payment::show()
{
    display();  // Called from main class
    cout << "\nYear of Study : " << year << endl;
    if (type == 'h')
        cout << " \n You are a hostelite";
    else
        cout << " \n You are a dayscholar";
    fees(year, type, paid);
}

//***Main Program**
int main()
{
    int ch;
    while (1)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tStudent Database Management System" << endl;
        cout << "1. Student Details" << endl;
        cout << "2. Student Marks Details" << endl;
        cout << "3. Student Sports Details" << endl;
        cout << "4. Student Payment Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;

        if (ch == 1) // Student Details
        {
            cout << "Enter the number of students: " << endl;
            cin >> n;
            Student s[n];
            for (int i = 0; i < n; i++)
            {
                s[i].input();
            }
            for (int i = 0; i < n; i++)
            {
                s[i].display();
            }
        }

        else if (ch == 2) // Student Marks Details
        {
            cout << "Enter the number of students: " << endl;
            cin >> n;
            marks m[n];
            for (int i = 0; i < n; i++)
            {
                m[i].getdata();
            }
            for (int i = 0; i < n; i++)
            {
                m[i].putdata();
            }
        }

        else if (ch == 3) // Student Sports details
        {
            sports s;
            s.insert();
            s.show();
        }

        else if (ch == 4) // Student Payment details
        {
            Payment p;
            p.get();
            p.show();
        }

        else if (ch == 5) // Program termination
        {
            exit(0);
        }

        else
        {
            cout << "Invalid input.\n";
        }
    }
    return 0;
}