/*
 * CompteEpargne.cpp
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */

#include <iostream>
#include "CompteEpargne.h"

using namespace std;

/*
 * This is a classic case of imprefect inheritance
 *
 *
 * */


CompteEpargne::~CompteEpargne() {

    cout << "Destruction d'un CompteEpargne" << endl;
}

CompteEpargne::CompteEpargne(float depotInitial, float taux,const Titulaire& titulaire)
: Compte(depotInitial,titulaire) , taux(taux), cumulDesBeneficesFinanciers(0) {

    //decouvertAutorise=0; // this is a const in Compte thus read only
                           // and it is logical as a const
                           // but we need to change it temporailiy
                           // for a savings account must use a const


    // Again this is about rvalues lvalues the case allows
    // the const_cast<float> generates a float of decouvert_athorise
    // like writing 100=0
    //const_cast<float>(decouvertAutorise)=0;

    // It must be a lvalue thus a reference
    const_cast<float&>(decouvertAutorise)=0;

    cout << "Construction d'un CompteEpargne" << endl;
}
void CompteEpargne::produireInterets()  {
	float benefices = taux * solde;
	crediter(benefices);
	cumulDesBeneficesFinanciers+=benefices;
}

std::string CompteEpargne::toString() const {
    return "Compte Epargne [numero=" + to_string(numero) + " solde=" + to_string(solde) + " taux=" + to_string(taux) + " cumulDesInterets=" + to_string(cumulDesBeneficesFinanciers)+" ]";
}

