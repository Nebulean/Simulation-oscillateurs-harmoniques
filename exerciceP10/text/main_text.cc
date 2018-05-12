#include "textviewer.h"
#include <iostream>
#include "pendule.h"
#include "ressort.h"
#include "systeme.h"
#include "chariot.h"
#include "eulercromer.h"
#include "penduledouble.h"
using namespace std;

/* Ce main est une reproduction de exerciceP9.
 */

int main(){
  TextViewer ecran(cout);
  Eulercromer IEC;
  Systeme syst1(0.1, &ecran, &IEC);
  Pendule pendule(1, 1, 0, &ecran);
  Ressort ressort(0.25, 0.33, 0.15, &ecran);
  Torsion torsion(1, 0.33, 0, &ecran);
  Chariot chariot(1, 1, 1, 0.33, 0.1, 0.1, &ecran);
  PenduleDouble pdouble(1, 1, 1, 1, &ecran);

  syst1 += pendule;
  syst1 += ressort;
  syst1 += torsion;
  syst1 += chariot;
  syst1 += pdouble;
  cout << "Système 1:" << endl;
  cout << "ÉTAT INITIAL" << endl;
  syst1.dessine();

  for (size_t i = 0; i < 3; ++i) {
    cout << "ÉTAPE " << i+1 << endl;
    syst1.evolue();
    syst1.dessine();
  };

  Systeme syst2(0.01, &ecran, &IEC);

  syst2 += pendule;
  syst2 += ressort;
  syst2 += torsion;
  syst2 += chariot;
  syst2 += pdouble;
  cout << "********" << endl;
  cout << "Système 2:" << endl;
  cout << "ÉTAT INITIAL" << endl;
  syst2.dessine();

  for (size_t i = 0; i < 3; ++i) {
    cout << "ÉTAPE " << i+1 << endl;
    syst2.evolue();
    syst2.dessine();
  };
  return 0;
}
