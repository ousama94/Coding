#include <iostream>
#include <string>

using namespace std;

class Member						//The base class from where the Student and Staff classes are derived from//
{
protected:
    int age;
    string name;
    Member *next;					//This base class also has a pointer to the next node in the linked list//

public:
    Member();														//The Member default constructor which initialises the class with default values//
    Member(string name_input, int age_input);                         //The Member ordinary constructor which sets the class with user input values values//
    void set_next(Member *next_input) {next = next_input;};            //Public functions used to assign the values from the user into the variables //
    int get_age(){return age;}                                       //Public functions used to access the private variables in this base class//
    void set_age(int age_input){age = age_input;}
    string get_name(){return name;}
    void set_name(string name_input){name =name_input;}
    Member *get_next() {return next;};
    virtual void print_details();                                    //Virtual function which prints the details of the base or derived classes//

};

class Student: public Member                                                    //The derived Student class from Member which has the same template as before//
{
private:
    int year;
public:
    Student();
    Student(string name_input, int age_input, int year_input);
    int get_year(){return year;}
    void set_year(int year_input){year = year_input;}
    void print_details();
};

class Staff: public Member											//The derived Staff class from Member which has the same template as before//
{
private:
    string position;
public:
    Staff();
    Staff(string name_input, int age_input, string position_input);
    string get_position(){return position;}
    void set_position(string position_input){position = position_input;}
    void print_details();
};


class DeptList													//The List class which is used to manage the linked list //
{
	private:
		Member *Head;                                           //Head pointer of data type Member, this always points to the latest entry of the list//
	public:
		DeptList() {Head = NULL;}                                  //Initialising the default constructor with Head pointing to Null//
		void add_member(string name_input, int age_input);          //Function prototypes for printing adding the nodes of the base and derived classes//
		void add_student(string name_input, int age_input, int year_input);
		void add_staff(string name_input, int age_input, string position_input);
		void print_list();									//Function prototype to print the list//
};

void DeptList::add_member(string name_input, int age_input)  
{
	Member *temp = new Member();				//This constructs a new node every time its called, pointer type of class member which points to the address of a new node//
	temp->set_age(age_input);						//This points to the age member of the node //
	temp->set_name(name_input);					//This points to the name member of the node//
	temp->set_next(Head);							//This points to the next pointer of the node//
	Head = temp;								//This makes the head pointer point to the node just created//
}

void DeptList::add_staff(string name_input, int age_input, string position_input)      //Same as previous but the pointer type is of staff//
{
	Staff *temp = new Staff();
	temp->set_age(age_input);
	temp->set_name(name_input);
	temp->set_position(position_input);
	temp->set_next(Head);
	Head = temp;
}


void DeptList::add_student(string name_input, int age_input, int year_input) //Same as previous but the pointer type is of student//
{
	Student *temp = new Student();
	temp->set_age(age_input);
	temp->set_name(name_input);
	temp->set_year(year_input);
	temp->set_next(Head);
	Head = temp;
}





void DeptList::print_list()					//Print list function, the pointer is initially points to the address of the latest entry, and will keep pointing to the next node until it reaches the tail//
{
	Member *peek;
	for (peek = Head; peek != NULL; peek = peek->get_next())
	{

		peek->print_details();

	}
}

Member::Member()                        //Member default constructor//
{
    age=-1;
    name="X";
    next=NULL;

}

void Member::print_details()                                     //Member print details//
{
	cout << "\nName: " << name << ", Age: " << age << endl;
}

Member::Member(string name_input, int age_input)
{
    name = name_input;
    age = age_input;

}



Staff::Staff():Member()														//Staff default constructor//
{

    position = -1;
}

Staff::Staff(string name_input, int age_input, string position_input):
    Member(name_input, age_input)
{
	position = position_input;
}

void Staff::print_details()															//Staff print details//
{
    cout << "\nName: " << get_name() << ", Age: " << get_age() << ", Position: " << position << endl;
}

Student::Student():Member()														//Student default constructor//
{

    year = -1;
}

Student::Student(string name_input, int age_input, int year_input)         //Student ordinary constructor //
:Member(name_input, age_input)
{

        year = year_input;
}

void Student::print_details()											//Student print details //
{
   cout << "Name: " << get_name() << ", Age: " << get_age() << ", Year: " << year << endl;
}


int main(void)
{
    string MemberType;											//Variables where user input is sotred into
    string StudentName;
    int StudentAge;
    int StudentYear;
    string StaffName;
    int StaffAge;
    string StaffPosition;
    DeptList Database;								//Object initialised of the list class//



    cout<<"Enter the Imperial membership type [student or staff or quit]: ";
cin>>MemberType;

while (MemberType != "Quit" || MemberType != "quit")      //While loop which carries on until the user enters quit //
{



    if (MemberType == "Student" || MemberType == "student")						//The required user input for student //
      {

        cout<<"\nEnter their name: ";
        cin.ignore();
        getline(cin, StudentName);
        cout<<"Enter their age: ";
        cin>>StudentAge;
        cout<<"Enter their year: ";
        cin>>StudentYear;
        Database.add_student(StudentName,StudentAge,StudentYear);           //taking the user input variables as the arguments for the add_student function //
        Database.print_list();												//then the list is printed //

    }

    else if (MemberType == "Staff" || MemberType == "staff")					//The required user input for staff//
    {

        cout<<"Enter their name: ";
        cin.ignore();
        getline(cin, StaffName);
        cout<<"Enter their age: ";
        cin>>StaffAge;
        cout<<"Enter their position: ";
        cin>>StaffPosition;
        Database.add_staff(StaffName,StaffAge,StaffPosition);					//taking the user input variables as the arguments for the add_staff function //
        Database.print_list();													//then the list is printed //


    }
    else
    {
        return 0;
    }

   cout<<"\nEnter the Imperial membership type [student or staff or quit]: ";
cin>>MemberType;

}
    return 0;
}