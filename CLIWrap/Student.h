#ifndef H_STUDENT
#define H_STUDENT

class Student
{
private:
	char *_fullname;
	double _gpa;
public:
	Student(char *name, double gpa);
	~Student();
	double getGpa();
	char *getName();
};
#endif
