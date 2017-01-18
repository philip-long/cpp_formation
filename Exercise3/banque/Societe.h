/*
 * Societe.h
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */

#ifndef SOCIETE_H_
#define SOCIETE_H_
#include <vector>
#include  "Employe.h"
#include "titulaire.h"
//namespace exemple {

class Societe : public Titulaire{
	std::vector<Employe *> employes;
    std::string raisonSocial;
    std::string siret;
    std::string siege;

public:
    Societe(const std::string& raisonSociale, const std::string& siret,const std::string& siege);
	~Societe();

    std::string getIdentity() const override {
     return raisonSocial+" "+siret;
    }
    std::string getAddress() const override {
     return siege;
    }
	void faireDeFric() {
		for(auto e : employes)
			e->travailler();

	}
	void embaucher(Employe *e) {
		employes.push_back(e);
	}
};

//} /* namespace exemple */

#endif /* SOCIETE_H_ */
