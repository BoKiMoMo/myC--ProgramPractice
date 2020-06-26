#include <iostream>
#include <iomanip>
#include "ArrayGradebook.h"

using namespace std;

GradeBook::GradeBook(const std::string& name, const std::array<int, students>& gradesArray)
	:courseName(name),grades(gradesArray)
{
}

void GradeBook::setCourseName(const string& name)
{
	courseName = name;
}

string GradeBook::getCourseName() const
{
		return courseName;
}

void GradeBook::displayMessage() const
{
	cerr << "Welcome to the grade book for :\n" << getCourseName() << "!" << endl;
}

void GradeBook::processGrades() const
{
	outputGrades();

	cout << setprecision(2) << fixed;
	cout << "\nClass average is " << getAverage() << endl;

	cout<<"Lowest grade is " << getMinimum() << "\nHighest grade is " << getMaximum() << endl;

	outputBarChart();
}

int GradeBook::getMinimum() const
{
	int lowestGrade = 100;

	for (int grade : grades)
	{
		if (grade < lowestGrade)
		{
			lowestGrade = grade;
		}
	}

	return lowestGrade;
}

int GradeBook::getMaximum() const
{
	int highestGrade = 0;

	for (int grade : grades)
	{
		if (grade > highestGrade)
		{
			highestGrade = grade;
		}
	}

	return highestGrade;
}

double GradeBook::getAverage() const
{
	int total = 0;

	for (int grade : grades)
		total += grade;
	
	return static_cast<double>(total)/grades.size();
}

void GradeBook::outputBarChart() const
{
	cout << "\nGrade distribution : " << endl;

	const size_t frequencySize = 11;
	array<unsigned int, frequencySize > frequency = {};

	for (int grade : grades)
		++frequency[grade / 10];

	for (size_t count = 0; count < frequency.size(); ++count)
	{
		if (10 == count)
			cout << setw(12) << "100 : ";
		else
			cout << setw(3) << count * 10 << " ~ " << setw(3) << count * 10 + 9 << " : ";

		for (unsigned int star = 0; star < frequency[count]; ++star)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void GradeBook::outputGrades() const
{
	cout << "\nThe grades are :\n\n";

	for (size_t student = 0; student < grades.size(); ++student)
	{
		cout << "Student " << setw(2) << student + 1 << " : " << setw(3) << grades[student] << endl;
	}
}
