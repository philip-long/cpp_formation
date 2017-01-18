#include <iostream>
#include "Compte.h"

using namespace std;

static int cptNumero = 10000; // variabile globale statica ma limitata a questo file
// approche C (piuttosto che C++ che farebbe definire questa variabile nel .h)

Compte::Compte(float depotInitial) : solde(depotInitial), decouvertAutorise(depotInitial), numero(cptNumero++){
 cout << "Construction d'un compte" << endl;
}

Compte::~Compte(){
    cout << "Destruction d'un compte" << endl;
    for (int i = 0; i < operations.size(); i++)  //   for (auto i : operations)
        delete operations[i];
}

void::Compte::crediter(float montant){
    solde += montant;
    operations.push_back(new Operation(montant, Operation::typeOperation::credit));
}

void::Compte::debiter(float montant){
if (montant <= solde + decouvertAutorise){
        solde -= montant;
        operations.push_back(new Operation(montant, Operation::typeOperation::debit));
        return;
    }
    cout << "Debit impossible." << endl;
}


void::Compte::editerReleve() const{
    cout << toString() << endl;
    for (auto i :operations)  //   for (auto i : operations)
        //cout << operations[i]->toString() << endl;
        i->toString();
}

std::string Compte::toString() const {
    return "Compte[numero =" + to_string(numero) + " solde=" + to_string(solde) + " decouvert autorise=" + to_string(decouvertAutorise) + "]";
}
