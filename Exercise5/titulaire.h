#ifndef TITULAIRE_H
#define TITULAIRE_H

#include <string>


// No data structure in an interface
// No .cpp in an interface
// No code in an interface
// Just like a template
// struct since everything is public
struct Titulaire
{
    virtual ~Titulaire() {};
    virtual std::string getIdentity() const=0;
    virtual std::string getAddress() const=0;
};

#endif // TITULAIRE_H
