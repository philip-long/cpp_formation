#include <iostream>
#include "Date.h"
#include "Operation.h"
#include "Compte.h"
#include "MemoryPool.h"

using namespace std;

int main(int argc, char *argv[])
{

/*    Operation o(100);
    cout << o.toString() << endl;

    Operation o2(1000, Operation::typeOperation::debit);
    cout << o2.toString() << endl;
  */

   Compte *c1 = new Compte(100);
   c1->editerReleve();
   c1->crediter(100);
   c1->debiter(62);
   c1->debiter(6);
   c1->editerReleve();

   delete c1;

}
