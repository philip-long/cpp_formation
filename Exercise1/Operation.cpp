#include <iostream>
#include <string>
#include "Operation.h"

using namespace std;

	static const char * stringType[2] = { "credit", "debit" };

    Operation::Operation(float montant,const typeOperation type) : montant(montant), type(type)
	{
		cout << "instanciation d'une operation" << endl;
	}

	Operation::~Operation()
	{
		cout << "destruction d'une operation" << endl;
	}


    string Operation::toString() const  {
        return "type=" + string(stringType[static_cast<int>(type)]) + " montant=" + to_string(montant) + " date=" + date.toString();
    }


    /*	// equivalent à fonction précédente
     * string Operation::toString() const  {
            ostringstream result;
            result << "type=" << stringType[static_cast<int>(type)] << " montant=" << montant << " date=" << date.toString();
            return result.str();
        }
    */
