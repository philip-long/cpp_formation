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
#include "Banque.h"

using namespace std;
using namespace exemple;

Date foo()  {
	Date d;
	return d;
}

bool compteBySocieteFilter (std::pair<int, Compte*> const& p) {
	return typeid(p.second->getTitulaire()) == typeid(Societe const &);
}

int main(int argc, char **argv) {



	Personne p("Long","Philip", "Bouguenais");
	Societe s("IRT Jule Verne","23123123", "Nantes");

	Banque b("LCL", "123123");

	int nCpt1 = b.ouvrirCompte(100, p);
	b.ouvrirCompte(10, p);
	b.ouvrirCompte(50, p);
	b.ouvrirCompte(100, p);
	b.ouvrirCompte(200, p);
	b.ouvrirCompte(150, p);
	b.ouvrirCompte(2000, p);

	int nCpt2 = b.ouvrirCompteEpargne(100,0.2f, s);
	b.editerLesReleves();
	Compte * c1 = b.getCompte(nCpt1);
	Compte * c2 = b.getCompte(nCpt2);

	try {
		c1->crediter(100);
		c1->debiter(300);
		c1->debiter(1);// --> débit impossible ....
	}
	catch(Compte::DebitException const & e) {
		e.cpt->traiterDebitNonAutorise(e);
	}

	try {
			c2->crediter(100);
			c2->debiter(300);
			c2->debiter(1);// --> débit impossible ....
		}
		catch(Compte::DebitException const & e) {
				e.cpt->traiterDebitNonAutorise(e);
		}
	b.produireBeneficesFinanciers();
	b.editerLesReleves();

	cout << "******** visualiserComptesBySolde ********"<< endl;

	b.visualiserComptesByCriteria(compte_predicate_by_solde<150>);

	cout << "******** visualiserComptesBySociete ********"<< endl;

	b.visualiserComptesByCriteria(compteBySocieteFilter);

	cout << "******** Bilan fonancier ********"<< endl;
	cout << "bilan financier de la banque :" << b.produireBilanFinancier() << endl;

	cout << "******** Fin ********"<< endl;

/*Societe s;
s.embaucher(new Personne());
s.embaucher(new Robot());
s.faireDeFric();*/




}



