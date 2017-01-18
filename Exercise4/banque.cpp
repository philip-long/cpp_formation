#include "banque.h"

// How to identify if the object is a savings account or a normal account


Banque::Banque(std::string nom, std::string code)
    :nom(nom),code(code)
{
    std::cout<<" The bank is open"<<std::endl;
}

int Banque::ouvrirCompte(float depotInitial,
                         const Titulaire& titulaire)
{
    return rangerCompte(new Compte(depotInitial,titulaire));
}

int Banque::ouvrirCompteEpargne(float depotInitial, float taux, const Titulaire &titulaire)
{
    return rangerCompte(new CompteEpargne(depotInitial,taux,titulaire));
}

int Banque::rangerCompte(Compte * c)
{
    comptes[c->getNumero()]=c;
    return c->getNumero();
}

Compte * Banque::getCompte(int n)
{
    const auto& iter= comptes.find(n);
    return iter !=comptes.end() ? iter->second : nullptr;
}

float Banque::clotureCompte(int n){
    Compte * c=getCompte(n);
    if(c!=nullptr && c->getSolde()>0)
    {
        float balance=c->getSolde();
        return balance;
        comptes.erase(n);
    }
    return 0;
}

void Banque::editerReleves() const
{
    for (auto& i : comptes) {
        i.second->editerReleve();
    }
}


void Banque::produireBeneficesFinaciers()
{
    for(auto& p: comptes)
    {
        // RTTI this is a type id
        // type info is a date structure that exist for each
        // class
        //std::type_info *info=typeid(int); // a returns a sturcture called typeinfo
        //std::type_info *info=typeid(1); // a returns a sturcture called typeinfo

        std::type_info const&  info=typeid(int);
        std::type_info const&  info2=typeid(3);

        if(typeid(CompteEpargne) == typeid(*p.second))
        {
            CompteEpargne * cpt=static_cast<CompteEpargne*>(p.second);
            cpt->produireInterets();
            std::cout<<"type id"<<std::endl;
        }
    }

    // A dynamic cast will do the same thing
    // but we have to check for the null_ptr
    for(auto& p: comptes)
    {
         CompteEpargne * cpt=dynamic_cast<CompteEpargne*>(p.second);
         if(cpt!=nullptr)
         {
             cpt->produireInterets();
             std::cout<<"type id dynamic cast"<<std::endl;
         }
    }
}







