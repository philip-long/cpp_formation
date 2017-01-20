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
// This is the functor
struct compte_predicate {
    float seuil;
    compte_predicate(float seuil) :seuil(seuil){}
    bool operator() (std::pair<int,Compte*> const& p)
    {
         return p.second->getSolde()>=seuil;
    }
};

bool compte_predicate2(std::pair<int,Compte*> const& p1,
                        std::pair<int,Compte*> const& p2)
{
    return p1.second->getSolde()>p2.second->getSolde();
}

void Banque::visualiserCompteParSolde(float seuil) const
{
    std::vector<std::pair<int,Compte*>> output(comptes.size());



    // Pay attention with the copy_if
    // lambda function more efficient
//    auto fin=std::copy_if(comptes.begin(),
//                 comptes.end(),
//                 output.begin(),
//                 [seuil] (std::pair<int,Compte *> const& p)->bool
//    {
//        return p.second->getSolde()>=seuil;
//    }
//    );

    // functors version
    // Then the comptepredicate is called by copy_if
    auto fin=std::copy_if(comptes.begin(),
                           comptes.end(),
                           output.begin(),
                           compte_predicate(seuil) // initialise anoymous object
                           );

    // Cant do a sort if the container is half empty so we need to limit the
    // sort to the elements that have been filled, copy_if returns an iterator.
    // we can use this iterator to limit
//    std::sort(output.begin(),
//              fin,
//              [] (std::pair<int,Compte *> const& p1,
//                  std::pair<int,Compte *> const& p2)
//            {
//                return p1.second->getSolde()>p2.second->getSolde();
//            }
//            );

    // Version functor
    std::sort(output.begin(),
              fin,
              compte_predicate2
            );

    std::for_each(output.begin(),
                  fin,
                  [](std::pair<int,Compte *> const& p)
                  {
                  std::cout<<"Titulaire "<<p.second->getTitulaire().getIdentity();
                  std::cout<<" No= "<<p.second->getNumero();
                  std::cout<<" Solde= "<<p.second->getSolde()<<std::endl;
                  }
                  );


}


float Banque::produireBilanFinancierParCompte(Compte & cpt)
{
    float result=0;
    for(auto & o : cpt.getOperations())
    {
        result+=o->getMontant();
    }
    return result;
}

float Banque::produireBilanFinancier() const{
    std::vector<std::future<float>> futures;
    for(auto& o : comptes)
    {
        // std::aynsc is by default sync
        // to force it to be asynch need to
        // std::
        futures.push_back(
                    std::async(std::launch::async,
                               produireBilanFinancierParCompte,
                               *this,
                               std::ref(*o.second)
                               )
                          );
    }
}









