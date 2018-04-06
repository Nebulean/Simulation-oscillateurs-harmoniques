#include "textviewer.h"
#include <iostream>
#include "../pendule/pendule.h"
#include "../ressort/ressort.h"
#include "../systeme/systeme.h"
using namespace std;


int main(){
  // j'écris en pseudocode
  // initialisation du support textuel
  // ostream flot;
  // TextViewer* support = new TextViewer(flot);

  TextViewer ecran(cout);

  // création d'un pendule.
  Pendule p1(1,1,1, &ecran);
  ecran.dessine(p1);

  // création d'un ressort.
  Ressort r1(1,1,1, &ecran);
  ecran.dessine(r1);

  // création d'un systeme.
  Systeme syst(0.1, 1, &ecran);
  syst.ajoute(new Pendule(p1));
  syst.ajoute(new Ressort(r1));
  ecran.dessine(syst);

  cout << "dank" << endl;

  // il faudrait:
  // Systeme sys(0.1, 0, support);
  // sys.ajouter(p1); // et que ajouter aloue un unique_ptr de son côté.
  // Systeme sys(0.1, 0, {unique_ptr<Oscillateur>(new Oscillateur(p1))}, support); // je crois que l'on alloue comme ça un unique_ptr...

  // sys.ajoute(plein d oscillateurs)


  return 0;
}
