
#include <sstream>
#include <iostream>
#include <string>
#include "Operation.h"
#include "MemoryPool.h" //
#include "GenericMemoryPool.h"

using namespace std;


	static const char * stringType[2] = { "credit", "debit" };
    //static MemoryPool pool(sizeof(Operation), 100000);

    // Now, the fundamental gain here is we have removed
    // dynamic allocation of memory.This is the preallocated
    // memory
    //
    static GenericMemoryPool<Operation,100000> pool;

	void * Operation::operator new (size_t size) {
		cout << "Operation::operator new " << endl;
		return pool.allocate();
	}

	void Operation::operator delete (void * p) {
		cout << "Operation::operator delete " << endl;
		pool.release(p);

	}

	Operation::Operation(float montant,  typeOperation type) : type(type), montant(montant)
	{
		cout << "instanciation d'une operation" << endl;
	}


	Operation::~Operation()
	{
		cout << "destruction d'une operation" << endl;
	}

	string Operation::toString() const  {
		return "type=" + string(stringType[static_cast<int>(type)]) + " montant=" +  to_string(montant) + " date=" + date.toString();
	}



