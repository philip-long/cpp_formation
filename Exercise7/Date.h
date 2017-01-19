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
		Date(const Date &);
		Date( Date &&) ;
		Date& operator = (const Date &) = default;
		Date& operator = ( Date &&) ;
		const char * toString() const { return buf; }
	};

#endif /*DATE_H_*/
