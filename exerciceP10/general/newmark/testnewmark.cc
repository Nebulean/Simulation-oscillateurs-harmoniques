#include "newmark.h"
#include "vecteur.h"
#include "chute.h"
#include "textviewer.h"

/* Correctif du 27.05.18
 * Ce test n'est plus compilable. Il lui manque des dépendances.
 */

/* Correctif du 27.05.18
 * Ce test n'est plus compilable. Il lui manque des dépendances.
 */

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

  // on fait évoluer l'instance de Chute un certain nombre de fois.
  for(size_t i(0); i < 69; ++i){
    vue.dessine(c);
    INM.evolue(c, dt, t);
  }

  return 0;
}
