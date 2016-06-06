#include "stdafx.h"
#include <cstring>
#include <string.h>
#include "Student.h"

Student::Student(char *name, double gpa)
{
	_fullname = new char[strlen(name + 1)];
	strcpy(_fullname, name);
	_gpa = gpa;
}

Student::~Student()
{
	delete[] _fullname;
}

double Student::getGpa()
{
	return _gpa;
}

char *Student::getName()
{
	return _fullname;
}