/*
 * Banque.h
 *
 *  Created on: 18 janv. 2017
 *      Author: joel
 */

#ifndef BANQUE_H_
#define BANQUE_H_
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <future>
#include <mutex>
#include "Titulaire.h"
#include "Compte.h"
#include "CompteEpargne.h"
#include "SpecificAllocator.h"

template<int seuil>
bool compte_predicate_by_solde (std::pair<int, Compte*> const& p) {
	return p.second->getSolde() >= seuil;
}



class Banque {
	std::string nom;
	std::string code;

	//std::map<int, Compte*, std::less<int>, std::allocator<std::pair<int, Compte*>>> aa;

	std::map<int, Compte*, std::less<int>, SpecificAllocator<std::pair<int, Compte*>>> comptes;

	int rangerCompte(Compte * cpt) {
		comptes[cpt->getNumero()] = cpt;
			return cpt->getNumero();
	}
public:
	Banque(std::string const& nom, std::string const&  code) :
		nom(nom), code(code) {
	}
	~Banque() {
		std::cout << "Constructeur de Banque" << std::endl;
		for(auto& p : comptes)
			delete p.second;
	}

	int ouvrirCompte(float depotIntial, Titulaire const& titulaire) {
		return rangerCompte(new Compte(depotIntial,titulaire));
	}

	int ouvrirCompteEpargne(float depotIntial, float taux, Titulaire const& titulaire) {
		return rangerCompte(new CompteEpargne(depotIntial,taux, titulaire));
	}

	Compte * getCompte(int numero) const {
		const auto& iter = comptes.find(numero);
		return iter != comptes.end() ? iter->second : nullptr;
	}

	float fermerCompte(int numero) {
		Compte * cpt = getCompte(numero);
		if(cpt != nullptr && cpt->getSolde() >= 0)	 {
			float relicat = cpt->getSolde();
			comptes.erase(numero);
			delete cpt;
			return relicat;
		}
		return 0;
	}

	void editerLesReleves() const {
		for(auto& p : comptes)
			p.second->editerReleve();
	}

	void produireBeneficesFinanciers() {

/*		std::type_info  const& info = typeid(int);
		std::type_info const& info2 = typeid(1);
		info == info2;*/

		for(auto& p : comptes)
			if(typeid(CompteEpargne) == typeid(*p.second)) {
				CompteEpargne * ce = static_cast<CompteEpargne*>(p.second);
				ce->produireInterets();
			}

		for(auto& p : comptes)  {
			CompteEpargne * ce = dynamic_cast<CompteEpargne*>(p.second);
			if(ce != nullptr) ce->produireInterets();
		}
	}

	template<typename Criteria>
	//void visualiserComptesBySolde(float seuil) const {
	void visualiserComptesByCriteria(Criteria const & criteria) const {
		std::vector<std::pair<int, Compte*>> output(comptes.size());

		//std::copy_if(comptes.begin(), comptes.end(),output.begin(),compte_predicate(seuil));
		auto fin = std::copy_if(comptes.begin(), comptes.end(),output.begin(),criteria);

		/*auto fin = std::copy_if(comptes.begin(), comptes.end(),output.begin(),
						[seuil](std::pair<int, Compte*> const& p) {
							return p.second->getSolde()>= seuil;
				});*/

		std::sort(output.begin(), fin,
				[] (std::pair<int, Compte*> const& p1, std::pair<int, Compte*> const& p2) {
					return p1.second->getSolde() >p2.second->getSolde();

		});

		std::for_each(output.begin(), fin,
				[](std::pair<int, Compte*> const& p1) {
			std::cout << "Titulaire=" << p1.second->getTitulaire().getIdentite() << " N°="
					<<  p1.second->getNumero() << " solde = " << p1.second->getSolde() << std::endl;
		}
		);
	}

	static float produireBilanFinancierParCompte(Compte const & cpt)  {
		static std::mutex barrier;
		float result = 0;
		std::lock_guard<std::mutex> raii(barrier);
		std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
		barrier.unlock();
		for(auto & o : cpt.getOperations())
			result += o->getMontant();
		return result;
	}

	float produireBilanFinancier() const {
		float result = 0;
		std::vector<std::future<float>> futures;
		for(auto& cpt : comptes)
			futures.push_back(std::async(std::launch::async, produireBilanFinancierParCompte, std::ref(*cpt.second)));

		for(auto& f : futures)
			result += f.get();
		return result;
	}
};

#endif /* BANQUE_H_ */
