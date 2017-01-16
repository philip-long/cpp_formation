#ifndef OPERATION_H_
#define OPERATION_H_

#include <string>
#include "Date.h"

class Operation
{

	public:
		enum class typeOperation { credit, debit };
	private:
		const typeOperation type;
		const float montant;
		const Date date;

	public:
        Operation(float montant = 0,const typeOperation type = typeOperation::credit);
		~Operation();
		std::string toString() const;

		const typeOperation getType() const { return type; }
		const float getMontant() const { return montant; }
		const Date& getDate() const { return date; }

};



#endif /*OPERATION_H_*/
