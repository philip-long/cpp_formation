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

Date::~Date()
{
	cout << "destruction d'une Date ... " << endl;

}

