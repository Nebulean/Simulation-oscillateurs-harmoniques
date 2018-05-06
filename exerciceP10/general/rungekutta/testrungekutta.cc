#include "rungekutta.h"
#include "chute.h"
#include "textviewer.h"
using namespace std;

int main(){
  double t(0);
  double dt(0.01);

  // création de l'écran
  TextViewer vue(cout);

  // on crée une instance de Chute.
  Chute c(0.127, &vue);

  // on initialise un intégrateur Newmark
  RungeKutta IRK;

  // on fait évoluer l'instance de Chute un certain nombre de fois.
  for(size_t i(0); i < 69; ++i){
    vue.dessine(c);
    IRK.evolue(c, dt, t);
  }

  return 0;
}
