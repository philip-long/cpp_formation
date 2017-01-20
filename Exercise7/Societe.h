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
#include "Titulaire.h"

namespace exemple {

class Societe : public Titulaire {
	std::string raisonSociale;
	std::string siret;
	std::string siege;

public:
	Societe(const std::string& raisonSociale, const std::string& siret, const std::string& siege)
	: raisonSociale(raisonSociale), siret(siret), siege(siege) {}
	std::vector<Employe *> employes;

	~Societe(){}

	std::string getIdentite() const override {
			return raisonSociale + " " + siret;
		}
	std::string getAdressePostale() const override {
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

} /* namespace exemple */

#endif /* SOCIETE_H_ */
