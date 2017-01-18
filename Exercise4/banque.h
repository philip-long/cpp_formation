#ifndef BANQUE_H
#define BANQUE_H

#include <iostream>
#include "string"
#include "Compte.h"
#include "CompteEpargne.h"
#include "map"

class Banque
{
private:

    std::string nom;
    std::string code;
    std::map<const int,Compte*> comptes;
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

};

#endif // BANQUE_H
