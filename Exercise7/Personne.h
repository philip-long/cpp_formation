/*
 * Personne.h
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_
#include <iostream>
#include  "Employe.h"
#include  "titulaire.h"

//namespace exemple {

class Personne : public Employe, public Titulaire {
private:
    std::string nom;
    std::string prenom;
    std::string address_postal;
public:
    Personne(const std::string& nom, const std::string& prenom,const std::string& address_postal);
	~Personne();
	void travailler() override {
		std::cout << "je travaille comme une personne ..." << std::endl;
	}
	void FaireDuSport();
	void JouerMusic();
    std::string getIdentity() const override {
     return nom+" "+prenom;
    }
    std::string getAddress() const override {
     return address_postal;
    }

};

//} /* namespace exemple */

#endif /* PERSONNE_H_ */
