#include "textviewer.h"
#include <iostream>
#include "pendule.h"
#include "ressort.h"
#include "systeme.h"
#include "chariot.h"
#include "eulercromer.h"
#include "penduledouble.h"
#include "newmark.h"
#include "rungekutta.h"
#include "chute.h"
#include "torsion.h"
#include "penduledouble.h"
#include "penduleressort.h"
using namespace std;

/* Ce main est une reproduction de exerciceP9.
 */

int main(){

  // main utilisé pour la création des graphiques
  // TextViewer ecran(cout);
  // Eulercromer IEC;
  // Newmark IEC;
  // RungeKutta IEC; // -->  celui utilisé
  // Systeme sys(0.1, &ecran, &IEC);
  // Pendule pendule(1, 2, 0.1, &ecran); // Fonctionnel: EC, NM, RK
  // sys += pendule;
  // Chute chute(1, &ecran); // Fonctionnel: EC, NM, RK
  // sys += chute;
  // Torsion torsion(1,1,0.05, &ecran);
  // sys += torsion;
  // Ressort ressort(0.25, 0.5, 0.02, &ecran);
  // sys += ressort;
  // Chariot chariot(1, 1, 1.5, 0.1, 0.1, 0.1, &ecran);
  // sys += chariot;
  // PenduleDouble penduledouble(0.5, 0.5, 1, 1, &ecran);
  // sys += penduledouble;
  //
  // sys.dessine();
  // for (size_t i = 0; i < 100; i++) {
  //   sys.evolue();
  //   sys.dessine();
  // }


  TextViewer ecran(cout);
  Eulercromer IEC;
  Systeme syst1(0.1, &ecran, &IEC);
  Pendule pendule(1, 1, 0, &ecran);
  Ressort ressort(0.25, 0.33, 0.15, &ecran);
  Torsion torsion(1, 0.33, 0, &ecran);
  Chariot chariot(1, 1, 1, 0.33, 0.1, 0.1, &ecran);
  PenduleDouble pdouble(1, 1, 1, 1, &ecran);
  PenduleRessort pressort(1, 1, 0.33, &ecran);

  syst1 += pendule;
  syst1 += ressort;
  syst1 += torsion;
  syst1 += chariot;
  syst1 += pdouble;
  syst1 += pressort;
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
  syst2 += pressort;
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
