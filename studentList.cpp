//****************************************************************************************************
//
//		File:					studentList.cpp
//		
//		Student:				Manish Bhandari
//
//		Assignment:	 			Program  # 10
//
//		Course Name:			Data Structures   II 
//
//		Course Number:			COSC 3100 - 01
//
//		Due:					Nov 6, 2019
//
//
//		This program implements binary class to manipulate student data.
//		
//****************************************************************************************************

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

#include "BST.h"
#include "student.h"

//****************************************************************************************************

void process(BST<Student> & studentList);
char getChoice();
void buildList(BST<Student> & studentList);
void addStudent(BST<Student> & studentList);
void findStudent(BST<Student> & studentList);
void removeStudent(BST<Student> & studentList);
void updateStudent(BST<Student> & studentList);
void displayStudents(BST<Student> & studentList);
void displaylistInfo(BST<Student> & studentList);
void displayoneStudent(Student s);


//****************************************************************************************************

int main()
{
	BST<Student> studentList;

	buildList(studentList);
	process(studentList);

	return 0;

}

//****************************************************************************************************

void process(BST<Student> & studentList)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A':	addStudent(studentList);
			break;
		case 'S':	findStudent(studentList);
			break;
		case 'D':	removeStudent(studentList);
			break;
		case 'U':	updateStudent(studentList);
			break;
		case 'P':	displayStudents(studentList);
			break;
		case 'X':	displaylistInfo(studentList);
			break;
		case 'Q':	break;
		}
	} 
	while (choice != 'Q');
}

//****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "========MENU=======\n"
		<< "A:    Add a new Student \n"
		<< "S:    Search a student Record \n"
		<< "U:    Update a student Record \n"
		<< "D:    Delete a student Record \n"	
		<< "P:    Display student Record \n"
		<< "X:    Display list information \n"
		<< "Q:    Quit    \n \n"
		<< "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A':	valid = true;
			break;
		case 'S':	valid = true;
			break;
		case 'U':	valid = true;
			break;
		case 'D':	valid = true;
			break;
		case 'P':	valid = true;
			break;
		case 'X':	valid = true;
			break;
		case 'Q':	valid = true;
			break;
		default:	valid = false;
			cout << "\a Invalid choice \n" << "Please try again:";
			break;
		}
	} 
	while (!valid);

	return choice;

}

//****************************************************************************************************

void buildList(BST<Student> & studentList)
{
	Student student;
	ifstream studentData;

	studentData.open("studentFile.txt");

	while (studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
					>> student.gender
					>> student.year
					>> student.credits
					>> student.gpa
					>> student.major;

		studentList.insert(student);
	}

	studentData.close();
}

//****************************************************************************************************

void addStudent(BST<Student> & studentList)
{
	Student newStudent;

	cout << "Enter student id:";
	cin >> newStudent.id;

	cin.ignore();
	cout << "Enter student name:";
	cin.getline(newStudent.name, 50);

	cout << "Enter city and state:";
	cin.getline(newStudent.citystate, 50);

	cout << "Enter phone number:";
	cin >> newStudent.phone;

	cout << "Enter gender:";
	cin >> newStudent.gender;

	cout << "Enter year:";
	cin >> newStudent.year;

	cout << "Enter credits:";
	cin >> newStudent.credits;

	cout << "Enter gpa:";
	cin >> newStudent.gpa;

	cout << "Enter major:";
	cin >> newStudent.major;

	if (studentList.insert(newStudent))
	{
		cout << "Student added to the list" << endl;
		cout << left << setw(15) << "Student id: " << newStudent.id << endl;
		cout << left << setw(15) << "Student name: " << newStudent.name << endl;
		cout << left << setw(15) << "Citystate:" << newStudent.citystate << endl;
		cout << left << setw(15) << "Phone:" << newStudent.phone << endl;
		cout << left << setw(15) << "Gender:" << newStudent.gender << endl;
		cout << left << setw(15) << "Year:" << newStudent.year << endl;
		cout << left << setw(15) << "Credits:" << newStudent.credits << endl;
		cout << left << setw(15) << "GPA:" << newStudent.gpa << endl;
		cout << left << setw(15) << "Major:" << newStudent.major << endl;
	}
	else
		cout << "Cannot add student to the list";

}

//****************************************************************************************************

void findStudent(BST<Student> & studentList)
{
	Student student;

	cout << "Enter the student id:";
	cin >> student.id;

	if (studentList.retrieve(student))
	{
		cout << "STUDENT FOUND" << endl;
		cout << left << setw(15) << "Student id: " << student.id << endl;
		cout << left << setw(15) << "Student name: " << student.name << endl;
		cout << left << setw(15) << "Citystate:" << student.citystate << endl;
		cout << left << setw(15) << "Phone:" << student.phone << endl;
		cout << left << setw(15) << "Gender:" << student.gender << endl;
		cout << left << setw(15) << "Year:" << student.year << endl;
		cout << left << setw(15) << "Credits:" << student.credits << endl;
		cout << left << setw(15) << "GPA:" << student.gpa << endl;
		cout << left << setw(15) << "Major:" << student.major << endl;
	}
	else
		cout << "Student not found!!" << endl;
}

//****************************************************************************************************

void removeStudent(BST<Student> & studentList)
{
	Student student;

	cout << "Enter the student id:";
	cin >> student.id;

	if (studentList.remove(student))
	{
		cout << "STUDENT REMOVED" << endl;
		cout << left << setw(15) << "Student id: " << student.id << endl;
		cout << left << setw(15) << "Student name: " << student.name << endl;
		cout << left << setw(15) << "Citystate:" << student.citystate << endl;
		cout << left << setw(15) << "Phone:" << student.phone << endl;
		cout << left << setw(15) << "Gender:" << student.gender << endl;
		cout << left << setw(15) << "Year:" << student.year << endl;
		cout << left << setw(15) << "Credits:" << student.credits << endl;
		cout << left << setw(15) << "GPA:" << student.gpa << endl;
		cout << left << setw(15) << "Major:" << student.major << endl;
	}
	else
		cout << "Student not found!!" << endl;
}

//****************************************************************************************************

void updateStudent(BST<Student> & studentList)
{
	Student student;

	cout << "Enter the student id:";
	cin >> student.id;
	
	cin.ignore();
	cout << "Enter student name:";
	cin.getline(student.name, 50);

	cout << "Enter city and state:";
	cin.getline(student.citystate, 50);

	cout << "Enter phone number:";
	cin >> student.phone;

	cout << "Enter gender:";
	cin >> student.gender;

	cout << "Enter year:";
	cin >> student.year;

	cout << "Enter credits:";
	cin >> student.credits;

	cout << "Enter gpa:";
	cin >> student.gpa;

	cout << "Enter major:";
	cin >> student.major;

	
	if (studentList.update(student))
	{
		cout << "Student  updated " << endl;
		cout << left << setw(15) << "Student id: " << student.id << endl;
		cout << left << setw(15) << "Student name: " << student.name << endl;
		cout << left << setw(15) << "Citystate:" << student.citystate << endl;
		cout << left << setw(15) << "Phone:" << student.phone << endl;
		cout << left << setw(15) << "Gender:" << student.gender << endl;
		cout << left << setw(15) << "Year:" << student.year << endl;
		cout << left << setw(15) << "Credits:" << student.credits << endl;
		cout << left << setw(15) << "GPA:" << student.gpa << endl;
		cout << left << setw(15) << "Major:" << student.major << endl;
	}
	else
		cout << "Could not update. Student doesnot exist!!" << endl;
}

//****************************************************************************************************

void displayStudents(BST<Student> & studentList)
{
	cout << "=======================================================";
	cout << endl;
	cout << "ID" << right << setw(18) << "NAME" << setw(22) << "MAJOR"
		<< setw(8) << "GPA" << endl;
	cout << "=======================================================" << endl;
	studentList.inorderTraverse(displayoneStudent);
}

//****************************************************************************************************

void displaylistInfo (BST<Student> & studentList)
{
	
	cout << endl;
	cout << " List Information" << endl;

	if (studentList.isEmpty())
		cout << "The tree is empty." << endl;
	else
		cout << "The tree is not empty." << endl;
	
	if (studentList.isFull())
		cout << "The tree is full." << endl;
	else
		cout << "The tree is not full." << endl;

	cout << "Number of elements is " << studentList.getCount() << endl;
	cout << "The height of the tree is " << studentList.getHt() << "."
		 << endl;

	if (studentList.isComplete())
		cout << "The tree is complete." << endl;
	else
		cout << "The tree is not complete." << endl;

	if (studentList.isComplete())
		cout << "The tree is balanced." << endl;
	else
		cout << "The tree is not balanced." << endl;
	
}

//****************************************************************************************************

void displayoneStudent(Student s)
{
	cout << s;
}

//****************************************************************************************************

/*
========MENU=======
A:    Add a new Student
S:    Search a student Record
U:    Update a student Record
D:    Delete a student Record
P:    Display student Record
X:    Display list information
Q:    Quit

Enter your choice: p
=========================================
ID              NAME                 MAJO
=========================================
3930      Leibniz, Gottfried W       MATH
4454      Atanasoff, Eniac C         CPSC
4559      Shyster, Samuel D          SOCI
4777      Gauss, Carl F              MATH
5316      GotoDijkstra, Edgar G      CPSC
5430      Nightingale, Florence K    NURS
5710      Busch, Arch E              ENGR
5873      Psycho, II,  Prunella E    PSYC
7107      Shoemaker, Imelda M        POLS
7448      Roosevelt, Rose Y          POLS
7844      Aardvark, Anthony A        ENGR
7885      Fibonacci, Leonard O       MATH
9463      Hochschule, Hortense C     EDUC
9743      Johnson, James L           ENGR
10236     Andrews, Peter J           CPSC
10304     Deutsch, Sprechen Z        GERM
11688     Kronecker, Leo P           MATH
11749     Issacson, Jacob A          RELI
11951     Mouse, Michael E           EDUC
13511     Pitt, Stew                 GNED
14674     Rockne, Newton K           PE
14815     Tchaikovsky, Wolfgang A    MUSC
15052     Einstein, Alfred M         ENGR
15671     Rembrandt, Roberta E       ART
15755     VandenVander, Vanessa V    HIST
15802     Pascal, Blaze R            CPSC
15889     Gazelle, Gwendolyn D       PE
16183     Kuts, Cole                 FOOD
16540     Weerd, Dewey L             PHIL
16622     Issacson, Esau B           RELI
17376     Scrooge, Ebenezer T        SOCI
17424     Nakamura, Toky O           SOCI
18213     Marx, Karl Z               ECON
18264     Lucky, Lucy L              HIST
19077     Medes, Archie L            ENGR
19918     Virus, Vera W              CPSC
20454     Chicita, Juanita A         BIOL
20991     Augusta, Ada B             CPSC
21144     Pasteur, Louise A          BIOL
22277     Principal, Pamela P        EDUC
22447     Zylstra, Zelda A           ENGL
23314     Macdonald, Ronald B        CPSC
23497     Fault, Paige D             CPSC
23544     Gestalt, Gloria G          PSYC
23750     Vespucci, Vera D           GEOG
24237     Euler, Lennie L            MATH
25377     Porgy, Bess N              MUSI
25831     Santamaria, Nina P         HIST
26316     Custer, General G          HIST
27503     Fahrenheit, Felicia O      CHEM
28658     Cicero, Marsha             LATI
29583     Yewliss, Cal C             MATH
30268     Newmann, Alfred E          EDUC
30280     Dewey, Johanna A           EDUC
30381     Elba, Able M               SPEE
30655     Angelo, Mike L             ART
30749     Mendelssohn, Mozart W      MUSC
30878     Lewis, Clark N             GEOG
31631     Aristotle, Alice A         PHIL
32598     Xerxes, Art I              GREE
32631     Freud, JR, Fred E          PSYC
========MENU=======
A:    Add a new Student
S:    Search a student Record
U:    Update a student Record
D:    Delete a student Record
P:    Display student Record
X:    Display list information
Q:    Quit

Enter your choice: x

 List Information
The tree is not empty.
The tree is not full.
Number of elements is 61
The height of the tree is 12.
The tree is not complete.
The tree is not balanced.
*/