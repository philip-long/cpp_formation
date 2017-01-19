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
#include "banque.h"
#include "Societe.h"
#include "GenericMemoryPool.h"

using namespace std;
using namespace exemple;

Date foo()  {
	Date d;
	return d;
}


int main(int argc, char **argv) {

    Personne n("Pedemonte","Nico","Italie");
    Societe e("Picard","Etienne","chez");
    Personne p("Long","Philip","Bouguenais");
    Personne d("Marquez","David","Venezuela");
    Societe s("IRT","23225","Nantes");

    //Compte *c1 = new Compte(100,p);
    //CompteEpargne *c2 = new CompteEpargne(100,0.2f,s);
    Banque b("my_bank","123");

    int nCPt=b.ouvrirCompte(100,n);
    b.ouvrirCompte(1000,p);
    b.ouvrirCompte(55,d);
    b.ouvrirCompte(1,e);
    b.ouvrirCompteEpargne(100,0.2f,s);
    //
    float seuil=10;
    std::cout<<"Visualise accounts greater than "<<seuil<<std::endl;
    b.visualiserCompteParSolde(seuil);


    //b.editerReleves();
    b.produireBeneficesFinaciers();

/*Societe s;
s.embaucher(new Personne());
s.embaucher(new Robot());
s.faireDeFric();*/




}



