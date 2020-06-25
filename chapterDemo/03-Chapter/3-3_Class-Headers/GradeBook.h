#include <iostream>
#include <string>

using namespace std;

class GradeBook{
	public:
		explicit GradeBook(string name): courseName(name)
		{
		}
		
		void setCourseName (string name)
		{
			courseName = name;
		}
		
		string getCourseName() const
		{
			return courseName;
		}
		
		void displayMessage(string courseName) const
		{
			cout<<"Welcome to the GradeBook for "<<getCourseName()<<"!"<<endl;
		}
		
	private:
		string courseName;
};				
