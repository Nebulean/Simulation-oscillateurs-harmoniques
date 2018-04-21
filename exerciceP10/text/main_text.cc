#include "textviewer.h"
#include <iostream>
#include "pendule.h"
#include "ressort.h"
#include "systeme.h"
#include "eulercromer.h"
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

  syst1.ajoute(pendule);
  syst1.ajoute(ressort);
  syst1.ajoute(torsion);
  cout << "Système 1:" << endl;
  cout << "ÉTAT INITIAL" << endl;
  syst1.dessine();

  for (size_t i = 0; i < 3; ++i) {
    cout << "ÉTAPE " << i+1 << endl;
    syst1.evolue();
    syst1.dessine();
  };

  Systeme syst2(0.01, &ecran, &IEC);

  syst2.ajoute(pendule);
  syst2.ajoute(ressort);
  syst2.ajoute(torsion);
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
