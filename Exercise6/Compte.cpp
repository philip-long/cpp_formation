/*
 * Compte.cpp
 *
 *  Created on: 16 janv. 2017
 *      Author: joel
 */

#include <iostream>
#include "Compte.h"


using namespace std;

static int cptNumero = 10000;

Compte::Compte(float depotInitial,const Titulaire& titulaire) :
    numero(cptNumero++), solde(depotInitial),
    decouvertAutorise(depotInitial), titulaire(titulaire) {
	cout << "Construction d'un Compte" << endl;
}

Compte::~Compte() {
	cout << "Destruction d'un Compte" << endl;
/*	for(int i = 0; i < operations.size(); i++)
			delete operations[i];*/
//	for(auto o  : operations)
//		delete o;
}

void Compte::crediter(float montant) {
	solde+=montant;
    // Resource allocation is the new
    // RAII -> Resource Allocation Is Initialisation
    std::unique_ptr<Operation> p(new Operation(montant, Operation::typeOperation::credit));
    operations.push_back(std::move(p));

}
void Compte::debiter(float montant) {
	if(montant <= solde+decouvertAutorise) {
		solde-=montant;
            //std::unique_ptr<Operation> p(new Operation(montant, Operation::typeOperation::credit));
        // Why use move
        // unique_ptr must be the only owner the resource, if we use a simple push_back
        // but stl creates a copy but we want a transfer.
        // the move is necessary as only the rvalue constructor is available.
            //operations.push_back(std::move(p));
        // instead of using a named object. we use a temporary object
        operations.push_back(std::unique_ptr<Operation>(new Operation(montant, Operation::typeOperation::credit)));
        // Only the constructor by rvalue is possible not the others in unique_ptr which have been deleted.
        //operations.push_back(std::unique_ptr<new Operation(montant, Operation::typeOperation::debit)> );
		return;
	}
    // Up until now we just have a cout.
    throw DebitException(this,montant);
	cout << "Débit impossible ..."  << endl;
}

void Compte::editerReleve() const {
	cout << toString() << endl;

/*	for(int i = 0; i < operations.size(); i++)
		cout << operations[i]->toString() << endl;*/

    // Before editerReleve we display the titulaire

    for(    vector<unique_ptr<Operation>>::const_iterator iter = operations.begin();
			iter != operations.end();
			iter++)
		cout << (*iter)->toString() << endl;
}

std::string Compte::toString() const {
	return "Compte[numero=" + to_string(numero) + " solde=" + to_string(solde) + " decouvertAutorise=" + to_string(decouvertAutorise) +"]";
}

// If in the catch we generate another exception we use recursion to
// treat the new exception.
void Compte::traiterDebitNonAuthorise(DebitException const & e)
{
    std::cerr<<e.what()<<std::endl;
    std::cout<<"Enter a nouveau montant : max value = [ "<<solde+decouvertAutorise<<" ]"<<endl;
    float nouveauMontant;
    std::cin>>nouveauMontant;
    try{
        debiter(nouveauMontant);
    }catch(Compte::DebitException const & e) {
        traiterDebitNonAuthorise(e);
    }
}
