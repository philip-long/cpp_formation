#ifndef COMPTE_H_
#define COMPTE_H_

#include <string>
#include <vector>
#include "Operation.h"

class Compte
	{
    const int numero;
    float solde;
    const float decouvertAutorise;
    std::vector<Operation *> operations; // oppure std::vector<Operation> v; ma copiare indirizzi è meno penalizzante che copiare tutto un insieme di dati
    // par contre, l'interesse di passare i valori veri e non gli indirizzi è che quando distruggo il conto tutti i valori operazioni si cancellano automaticamente,
    // metre usando l'indirizzo dovrò andare a distruggere tutte le operazioni
    // con i * dovro poi usare dei new e dei delete


public:
    Compte(float depotInitial);
    ~Compte();

    int getNumero() const{return numero;}
    float getSolde() const {return solde;}
    float getDecouvertAutorise() const {return decouvertAutorise;}

    void crediter(float montant);
    void debiter(float montant);
    void editerReleve() const;

    std::string toString() const;

	};

#endif /*COMPTE_H_*/

