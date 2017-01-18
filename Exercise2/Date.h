#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <string>

class Date
	{
		time_t date;
		char buf[20];

	public:
		Date();
		~Date();
		Date(const Date &) = default;
		Date& operator = (const Date &) = default;
		const char * toString() const { return buf; }
	};

#endif /*DATE_H_*/
