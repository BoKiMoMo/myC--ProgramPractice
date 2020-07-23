#include"AHACounter.h"
using namespace std;

HeartRate::HeartRate(string name)
{
	setName(name);
}

HeartRate::~HeartRate()
{
	cout << "\n\nGoodBye " << getName()<<endl;
}

const int HeartRate::getOld()
{
	int old = getDate() - birthyear;
	return old;
}

const int HeartRate::getDate()
{
	return date;
}

const int HeartRate::getBirthday()
{
	
	return birthyear;
}

const int HeartRate::getMaxiuminHeartRate()
{
	int MaxiumuHeartRate = 220 - getOld();

	return MaxiumuHeartRate;
}

void HeartRate::setBirthday(int Month,int Day,int year)
{
	birthyear = year;
	birthmonth = Month;
	birthday = Day;
}

void HeartRate::setDate(int date)
{
	this->date = date;
}

std::string HeartRate::getName()
{
	return name;
}

void HeartRate::setName(string name)
{
	this->name = name;
}

const double HeartRate::getRegulationHighHeartRate()
{
	return getMaxiuminHeartRate() * 0.85;
}

const double HeartRate::getRegulationLowHeartRate()
{
	return getMaxiuminHeartRate() * 0.5;
}

void HeartRate::print()
{
	cout << "\n\nHello " << getName() << endl;
	cout << "Your Birthday is " << birthmonth <<"."<<birthday<<"."<<birthyear << endl;
	cout << "Your yearsOld is " << getOld() << "\nYour MaximumHeartRate is " << getMaxiuminHeartRate()
		<< "\nYour RegulationHeartRate is " << getRegulationHighHeartRate() << " ~ " << getRegulationLowHeartRate() << endl;

}

