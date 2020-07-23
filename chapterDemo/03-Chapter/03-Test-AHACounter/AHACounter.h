#ifndef AHACOUNTER_H
#define AHACOUNTER_H
#include<iostream>
#include<string>


class HeartRate
{
public:
	HeartRate(std::string);
	~HeartRate();
	const int getOld();
	const int getDate();
	const int getBirthday();
	const int getMaxiuminHeartRate();
	void setBirthday(int,int,int);
	void setDate(int);
	std::string getName();
	void setName(std::string);
	const double getRegulationHighHeartRate();
	const double getRegulationLowHeartRate();

	void print();

private:
	int birthyear;
	int birthmonth;
	int birthday;
	int date;
	std::string name;
};


#endif
