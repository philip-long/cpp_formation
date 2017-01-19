/*
 * Personne.h
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */

#ifndef RORBOT_H_
#define RORBOT_H_

#include <iostream>
#include  "Employe.h"

namespace exemple {

class Robot : public Employe {
public:
	~Robot() override {}
	void travailler() override {
		std::cout << "je travaille comme un ROBOT  ..." << std::endl;
	}
	void faireMaintenance();

};

} /* namespace exemple */

#endif /* RORBOT_H_ */
