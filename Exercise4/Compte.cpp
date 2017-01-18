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
	for(auto o  : operations)
		delete o;
}

void Compte::crediter(float montant) {
	solde+=montant;
	operations.push_back(new Operation(montant, Operation::typeOperation::credit));

}
void Compte::debiter(float montant) {
	if(montant <= solde+decouvertAutorise) {
		solde-=montant;
		operations.push_back(new Operation(montant, Operation::typeOperation::debit));
		return;
	}
	cout << "Débit impossible ..."  << endl;
}

void Compte::editerReleve() const {
	cout << toString() << endl;

/*	for(int i = 0; i < operations.size(); i++)
		cout << operations[i]->toString() << endl;*/

    // Before editerReleve we display the titulaire

	for(    vector<Operation*>::const_iterator iter = operations.begin();
			iter != operations.end();
			iter++)
		cout << (*iter)->toString() << endl;
}

std::string Compte::toString() const {
	return "Compte[numero=" + to_string(numero) + " solde=" + to_string(solde) + " decouvertAutorise=" + to_string(decouvertAutorise) +"]";
}


