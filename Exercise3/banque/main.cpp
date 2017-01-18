/*
 * main.cpp
 *
 *  Created on: 16 janv. 2017
 *      Author: joel
 */
#include <iostream>
#include "Operation.h"
#include "Compte.h"
#include "CompteEpargne.h"
#include "Personne.h"
#include "Robot.h"
#include "Societe.h"
#include "GenericMemoryPool.h"

using namespace std;
using namespace exemple;

Date foo()  {
	Date d;
	return d;
}


int main(int argc, char **argv) {

    Personne p("Long","Philip","Bouguenais");
    Societe s("IRT","23225","Nantes");

    Compte *c1 = new Compte(100,p);
    CompteEpargne *c2 = new CompteEpargne(100,0.2f,s);
	c1->editerReleve();
	c2->editerReleve();
	c1->crediter(100);
	c1->debiter(300);
	c1->debiter(1); // --> débit impossible ....
	c2->crediter(100);
	c2->debiter(300);
	c2->debiter(1); // --> débit impossible ....
	c2->produireInterets();
    cout << "****************"<< endl;
	c1->editerReleve();
	c2->editerReleve();
	cout << "****************"<< endl;

	delete c1;
	delete c2;


/*Societe s;
s.embaucher(new Personne());
s.embaucher(new Robot());
s.faireDeFric();*/




}



