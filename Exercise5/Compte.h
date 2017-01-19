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
#include "titulaire.h"

class Compte {
protected:
	const int numero;
	float solde;
	const float decouvertAutorise;

	std::vector<Operation *> operations;
    const Titulaire& titulaire;

public:
    Compte(float depotInitial, const Titulaire& titulaire);
    virtual ~Compte(); // the destructor of compte does not destroy
                        // titiluaire therefore not a true composition
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

};

#endif /* COMPTE_H_ */
