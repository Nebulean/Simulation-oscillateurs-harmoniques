#include "textviewer.h"
#include <iostream>
#include "../pendule/pendule.h"


int main(){
  // j'écris en pseudocode
  // initialisation du support textuel
  ostream flot;
  TextViewer* support = new TextViewer(flot);

  // création d'un pendule.
  Pendule p1(1,1,1, support);

  // il faudrait:
  // Systeme sys(0.1, 0, support);
  // sys.ajouter(p1); // et que ajouter aloue un unique_ptr de son côté.
  // Systeme sys(0.1, 0, {unique_ptr<Oscillateur>(new Oscillateur(p1))}, support); // je crois que l'on alloue comme ça un unique_ptr...

  // sys.ajoute(plein d oscillateurs)


  return 0;
}
