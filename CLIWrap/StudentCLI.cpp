#include "stdafx.h"
#include "Student.h"

public ref class StudentWrapper
{
private:
	Student *_student;
public :
	StudentWrapper(System::String ^fullname, double gpa)
	{
		_student = new Student((char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(fullname)
			.ToPointer(), gpa);
	}
	~StudentWrapper()
	{
		delete _student;
		_student = 0;
	}

	property System::String ^Name
	{
		System::String ^get()
		{
			return gcnew System::String(_student->getName());
		}
	}

	property double Gpa
	{
		double get()
		{
			return _student->getGpa();
		}
	}
};