#include <iostream>
#include <string>

using namespace std;

class GradeBook{
	public:
		void displayMessage(string courseName) const
		{
			cout<<"Welcome to the GradeBook for "<<courseName<<"!"<<endl;
		}
};

int main(){
	
	string nameOfCourse;
	GradeBook myGradeBook;
	
	cout<<"Please enter the course name: "<<endl;
	getline(cin, nameOfCourse);//read a course name with blanks
	cout<<endl;
	
	myGradeBook.displayMessage(nameOfCourse);


return 0;                   
} 					
