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
        Operation(float montant = 0,
                  const typeOperation type = typeOperation::credit);
		~Operation();
		std::string toString() const;

		const typeOperation getType() const { return type; }
		const float getMontant() const { return montant; }
		const Date& getDate() const { return date; }
        // returns a pointer towards a block of memory
        // one parameter that is the size of the block
        // we would like to get
        void * operator new(size_t size);
        // Delete needs at least one parameter
        // which is the address
        void operator delete(void * p);

};



#endif /*OPERATION_H_*/
