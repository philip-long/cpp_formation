#include <iostream>
#include <ctime>
#include "Date.h"

using namespace std;


Date::Date() : date(time(nullptr))
{
	cout << "instanciation d'une Date ... " << endl;
	struct tm * timeinfo;
	timeinfo = localtime(&date);
	strftime(buf, sizeof(buf), "%d/%m/%Y", timeinfo);
}

Date::Date(Date&& date) {
	cout << "Date::Date(Date&& date)" << endl;
	this->date = date.date;
}
/*
Date::Date(const Date & date) {
	cout << "Date(const Date &)" << endl;
	this->date = date.date;
}*/

Date& Date::operator=(Date&& date) {
	cout << "Date::operator=(Date&& date) " << endl;
	return *this;
}

Date::~Date()
{
	cout << "destruction d'une Date ... " << endl;

}

