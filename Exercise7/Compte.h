/*
 * Compte.h
 *
 *  Created on: 16 janv. 2017
 *      Author: joel
 */

#ifndef COMPTE_H_
#define COMPTE_H_

#include  <string>
#include  <vector>
#include  <memory>
#include  <iostream>
#include  <stdexcept>
#include  "Operation.h"
#include  "Titulaire.h"

class Compte {
public:
	struct DebitException : public std::logic_error {
		Compte * cpt;
		float montant;
		DebitException(Compte * cpt, float montant)
		: std::logic_error("DebitException : montant à débiter trop important ...!"), cpt(cpt), montant(montant) {}
	};
protected:
	const int numero;
	float solde;
	const float decouvertAutorise;

	std::vector<std::unique_ptr<Operation>> operations;
	const Titulaire & titulaire;

public:
	Compte(float depotInitial, const Titulaire & titulaire);
	virtual ~Compte();

	void crediter(float montant);
	virtual void debiter(float montant);
	void editerReleve() const ;
	virtual std::string toString() const;


	float getDecouvertAutorise() const {
		return decouvertAutorise;
	}

	int getNumero() const {
		return numero;
	}

	float getSolde() const {
		return solde;
	}

	const Titulaire& getTitulaire() const {
		return titulaire;
	}

	void traiterDebitNonAutorise(DebitException const & e) {
		std::cerr<<e.what() << std::endl;
		std::cout << "Entrez un nouveau montant max=["<<solde+decouvertAutorise << "] : ";
		float nouveauMontant;
		std::cin>>nouveauMontant;
		try {
			debiter(nouveauMontant);
		} catch (DebitException const & e) {
			traiterDebitNonAutorise(e);
		}
	}

	std::vector<std::unique_ptr<Operation>> const & getOperations() const  {
			return operations;
	}



};

#endif /* COMPTE_H_ */
