#include "newmark.h"
#include "vecteur.h"
#include "chute.h"
#include "textviewer.h"
#include "eulercromer.h" // pour des tests.

using namespace std;

int main(){
  // on initialise le temps et le pas de temps.
  double t(0);
  double dt(0.01);

  // création de l'écran
  TextViewer vue(cout);

  // on crée une instance de Chute.
  Chute c(0.127, &vue);

  // on initialise un intégrateur Newmark
  Newmark INM;
  Eulercromer IEC;

  // on fait évoluer l'instance de Chute un certain nombre de fois.
  for(size_t i(0); i < 69; ++i){
    vue.dessine(c);
    IEC.evolue(c, dt, t);
  }

  return 0;
}
