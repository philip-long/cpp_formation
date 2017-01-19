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
#include  "Operation.h"
#include <stdexcept>
#include "titulaire.h"
#include <memory>

class Compte {
public :

    struct DebitException : public std::logic_error{
        Compte * cpt;
        float montant;
        DebitException(Compte * cpt, float montant)
                        :std::logic_error("DebitException : montant à debiter trop important...!"),
                         cpt(cpt),
                         montant(montant)
        {}

    };
protected:
	const int numero;
	float solde;
	const float decouvertAutorise;

    std::vector<std::unique_ptr<Operation>> operations;
    const Titulaire& titulaire;

public:

    Compte(float depotInitial, const Titulaire& titulaire);
    virtual ~Compte(); // the destructor of compte does not destroy
                        // titiluaire therefore not a true composition
	void crediter(float montant);
    virtual void debiter(float montant);
	void editerReleve() const ;
	virtual std::string toString() const;
    void traiterDebitNonAuthorise(DebitException const & e);

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



};

#endif /* COMPTE_H_ */
