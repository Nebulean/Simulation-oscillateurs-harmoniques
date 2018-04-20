#include "textviewer.h"
#include <iostream>
#include "../pendule/pendule.h"
#include "../ressort/ressort.h"
#include "../systeme/systeme.h"
using namespace std;


int main(){
  // création d'un TextViewer.
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
  
  return 0;
}
