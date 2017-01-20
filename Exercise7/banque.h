#ifndef BANQUE_H
#define BANQUE_H

#include <iostream>
#include <functional>
#include "string"
#include "Compte.h"
#include "CompteEpargne.h"
#include "map"
#include "SpecificAllocator.h"
#include "algorithm"
#include "future"


class Banque
{
private:

    std::string nom;
    std::string code;

    //std::map<int,Compte *,std::less<int>,std::allocator<std::pair<int,Compte*>>> aa;
    std::map<int,Compte*,std::less<int>,SpecificAllocator<std::pair<int,Compte*>>> comptes;

    int rangerCompte(Compte * c);

public:
    Banque(std::string nom, std::string code);
    ~Banque()
    {
     std::cout<<" The bank is closed"<<std::endl;
    }
    int ouvrirCompte(float depotInitial,
                     const Titulaire& titulaire);
    int ouvrirCompteEpargne(float depotInitial,
                            float taux,
                            const Titulaire& titulaire);
    Compte * getCompte(int n);
    float clotureCompte(int n);
    void produireBeneficesFinaciers();
    void editerReleves() const;
    void visualiserCompteParSolde(float seuil) const;
    void visualiserCompteParCrieteria(float seuil) const;
    float produireBilanFinancier() const;
    float produireBilanFinancierParCompte(Compte  & cpt);
};

#endif // BANQUE_H
