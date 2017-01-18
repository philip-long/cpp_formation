/*
 * essai.cpp
 *
 *  Created on: 17 janv. 2017
 *      Author: joel
 */
#include <iostream>
#include <string>
#include "Operation.h"
using namespace std;

template<typename T> class Vector {
			T *v;
			int taille;
		public:
			Vector (int t) { v = new T[taille = t]; }
			~Vector (void) { delete v; }
			Vector(const Vector&) = delete;
			Vector& operator = (const Vector&) = delete;
			T& operator [] (int i) { return v[i]; }
			int size (void) const { return taille; }
	};


            // pay attention to where the const is
            // and how it applies.To avoid this apply directly
            // to
template <class T> //fonction générique
bool greaterThan (  T const & a,  T const & b){ return a < b; }

template<> //spécialisation complète du générique pour les Position *
bool greaterThan( Operation * const& o1, Operation * const& o2) {
	return o1->getMontant() > o2->getMontant() ? true:false;
}

template<class T> void sort (Vector<T>& v)
{
	int n = v.size();
	for (int i=0; i<n-1; i++)
		for (int j=n-1; i<j; j--)
			if(greaterThan(v[j], v[j-1])){
				T temp = v[j];
				v[j] = v[j-1];
				v[j-1] = temp;
			}
}

template<typename T> // Comparator générique (functor)
struct comparator {
	bool operator () ( T const &a,  T  const &b) {return a>b;}
};

// The academic way to do it , create an object Operation
// is a functor () by overloading
// then it returns
// A functor is pretty much just a class which defines the operator().
// That lets you create objects which "look like" a function:
struct OperationComparator {
	bool operator () ( Operation * o1,  Operation * o2) {
		return o1->getMontant() > o2->getMontant() ? true:false;
	}
};

// This is simply a function
bool operationComparator ( Operation * o1,  Operation * o2) {
		return o1->getMontant() > o2->getMontant() ? true:false;
}

// This template is much better as the user can define a
// type a comparion. A functor is an object that behaves
// like a function. This class c is generic. It behaves like
// a functor it takes two parameters. A default function is used
// which is a struct or a class. So the object comparator is created
// for type T and contains a function (). The comparator is a generic
// type which we define. The only thing that is requried is the
// fact it has a function ()
template<typename  T, typename Comparator>
void sortWithFunctor (Vector<T>& v, Comparator c =comparator<T>() )
{
	int n = v.size();
	for (int i=0; i<n-1; i++)
		for (int j=n-1; i<j; j--)
			if(c(v[j], v[j-1])){
				T temp = v[j];
				v[j] = v[j-1];
				v[j-1] = temp;
			}
}


int mainn(int argc, char **argv) {
	Vector<Operation*> v(3);
	v[0] = new Operation(10);
	v[1] = new Operation(5);
	v[2] = new Operation(15);

	sort(v);
	cout << v[0]->toString() << " " << v[1]->toString() << " "<< v[2]->toString() << endl;

	v[0] = new Operation(10);
	v[1] = new Operation(5);
	v[2] = new Operation(15);

    // Here we pass a vector and the class ( an object that defines a functor)
    // This is an anonymous object (Academic approach)
	sortWithFunctor(v,OperationComparator());
	cout << v[0]->toString() << " " << v[1]->toString() << " "<< v[2]->toString() << endl;

	v[0] = new Operation(10);
	v[1] = new Operation(5);
	v[2] = new Operation(15);

    // 2nd approach, no longer a functor but simply a function
    // Simply an address of a function, which however must take two objects
    // and return a bool
    // sortWithFunctor is a generic function defined by a template
	sortWithFunctor(v,operationComparator);
	cout << v[0]->toString() << " " << v[1]->toString() << " "<< v[2]->toString() << endl;

	v[0] = new Operation(10);
	v[1] = new Operation(5);
	v[2] = new Operation(15);

    // If we only have to use it once. Why then define a function ?
    // Since it is only used once, this is the definition of a lambda
    // expression. We define the semantic of a function without the name
    //
    sortWithFunctor(
                v,  [](Operation * const& o1, Operation * const& o2)->bool
    {
		return o1->getMontant() < o2->getMontant() ? true:false;
    }
    );


	cout << v[0]->toString() << " " << v[1]->toString() << " "<< v[2]->toString() << endl;

	Vector<int> v2(3);
	v2[0] = 10;
	v2[1] = 5;
	v2[2] = 15;

	sort(v2);
	cout << v2[0] << " " << v2[1] << " "<< v2[2] << endl;

	v2[0] = 10;
	v2[1] = 5;
	v2[2] = 15;

	sortWithFunctor(v2, comparator<int>());
	cout << v2[0] << " " << v2[1] << " "<< v2[2] << endl;

}





