/*
 * CompteEpargne.cpp
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */

#include <iostream>
#include "CompteEpargne.h"

using namespace std;

CompteEpargne::~CompteEpargne() {
	cout << "Destruction d'un CompteEpargne" << endl;
}

CompteEpargne::CompteEpargne(float depotInitial, float taux, const Titulaire & titulaire)
: Compte(depotInitial, titulaire) , taux(taux), cumulDesBeneficesFinanciers(0) {
	const_cast<float&>(decouvertAutorise)= 0;
	cout << "Construction d'un CompteEpargne" << endl;
}
void CompteEpargne::produireInterets()  {
	float benefices = taux * solde;
	crediter(benefices);
	cumulDesBeneficesFinanciers+=benefices;
}

std::string CompteEpargne::toString() const {
	return "CompteEpargne[numero=" + to_string(numero)
			+ " solde=" + to_string(solde)
			+ " taux=" + to_string(taux)
			+ " cumulDesInterets=" + to_string(cumulDesBeneficesFinanciers);
}

