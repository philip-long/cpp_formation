/*
 * Personne.h
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_
#include <iostream>
#include <string>
#include  "Employe.h"
#include  "Titulaire.h"

namespace exemple {

class Personne : public Employe, public Titulaire {
	std::string nom;
	std::string prenom;
	std::string adresse;

public:
	Personne(const std::string& nom, const std::string& prenom, const std::string& adresse)
	: nom(nom), prenom(prenom), adresse(adresse) {}
	~Personne(){}
	void travailler() override {
		std::cout << "je travaille comme une personne ..." << std::endl;
	}
	void FaireDuSport();
	void JouerMusic();

	std::string getIdentite() const override {
		return nom + " " + prenom;
	}
	std::string getAdressePostale() const override {
		return adresse;
	}

};

} /* namespace exemple */

#endif /* PERSONNE_H_ */
