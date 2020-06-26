#include<array>
#include "ArrayGradeBook.h"

using namespace std;

int main()
{
	const array<int, GradeBook::students> grades
		= { 87,68,94,100,83,78,85,91,76,87 };
	string courseName = "CS101 Introduction to C++ Programming";

	GradeBook myGradeBook(courseName, grades);
	myGradeBook.setCourseName("CS201 Introduction to C++ Programming");
	myGradeBook.displayMessage();
	myGradeBook.processGrades();


	//CS101 Introduction to C++ Programming [] ={ 87,68,94,100,83,78,85,91,76,87 } ;
}