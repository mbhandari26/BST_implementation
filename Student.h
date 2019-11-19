//****************************************************************************************************
//
//		File:					Student.h
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

#ifndef STUDENT_H
#define STUDENT_H

//*****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	friend ostream  & operator << (ostream & out, const Student & data);
	bool operator == (const Student & rhs) const;
	bool operator == (int val) const;
	bool operator != (const Student & rhs) const;
	bool operator != (int val) const;
	bool operator < (const Student & rhs) const;
	bool operator < (int val) const;
	bool operator > (const Student & rhs) const;
	bool operator > (int val) const;
	bool operator <= (const Student & rhs) const;
	bool operator <= (int val) const;
	bool operator >= (const Student & rhs) const;
	bool operator >= (int val) const;
	Student & operator = (int value);
};

//*****************************************************************************************************

Student::Student()
{
	id = 0;
}

//*****************************************************************************************************

ostream & operator << (ostream & out, const Student & data)
{
	out << left << setw(10) << data.id
		<< left << setw(27) << data.name
		<< left << setw(10) << data.major
		<< setprecision(2) << fixed <<  data.gpa << endl;

	return out;
}
//*****************************************************************************************************

bool Student::operator == (const Student & rhs) const
{
	return (this->id == rhs.id);
}

//*****************************************************************************************************

bool Student::operator == (int val) const
{
	return (this->id == val);
}

//*****************************************************************************************************

bool Student::operator != (const Student & rhs) const
{
	return (this->id != rhs.id);
}

//*****************************************************************************************************

bool Student::operator != (int val) const
{
	return (this->id != val);
}

//*****************************************************************************************************

bool Student::operator < (const Student & rhs) const
{
	return (this->id < rhs.id);
}

//*****************************************************************************************************

bool Student::operator < (int val) const
{
	return (this->id < val);
}

//*****************************************************************************************************

bool Student::operator > (const Student & rhs) const
{
	return (this->id > rhs.id);
}

//*****************************************************************************************************

bool Student::operator > (int val) const
{
	return (this->id > val);
}

//*****************************************************************************************************

bool Student::operator <= (const Student & rhs) const
{
	return (this->id <= rhs.id);
}

//*****************************************************************************************************

bool Student::operator <= (int val) const
{
	return (this->id <= val);
}

//*****************************************************************************************************

bool Student::operator >= (const Student & rhs) const
{
	return (this->id >= rhs.id);
}

//*****************************************************************************************************

bool Student::operator >= (int val) const
{
	return (this->id >= val);
}

//*****************************************************************************************************

Student & Student::operator = (int value)
{
	this->id = value;
	return * this;

}

//*****************************************************************************************************

#endif
