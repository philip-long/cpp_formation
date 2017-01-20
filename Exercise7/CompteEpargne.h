/*
 * CompteEpargne.h
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */

#ifndef COMPTEEPARGNE_H_
#define COMPTEEPARGNE_H_
#include <string>
#include "Compte.h"

class CompteEpargne : public Compte {
protected :
	float taux;
	float cumulDesBeneficesFinanciers;
public:
	virtual ~CompteEpargne();
	CompteEpargne(float depotInitial, float taux, const Titulaire & titulaire);
	void produireInterets();
	std::string toString() const;
	/*void debiter (float montant) override {
		if(montant<=solde) {
			solde -= montant;
			operations.push_back(new Operation(montant, Operation::typeOperation::debit));
		}
	}*/

};

#endif /* COMPTEEPARGNE_H_ */
