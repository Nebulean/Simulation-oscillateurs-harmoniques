#include "phase.h"
#include "pendule.h"
#include "textviewer.h"
#include "rungekutta.h"
using namespace std;

int main(){
  TextViewer vue(cout);
  RungeKutta IRK;

  Pendule p(2, 2, 0, &vue, {M_PI/3}, {0.0}, {0.0, 0.0, 0.0});
  Phase phase(&vue);
  for (size_t i = 0; i < 10000; i++) {
    IRK.evolue(p, 0.1, 1);
    phase.ajoute_point(p);
  }
  phase.dessine();
  return 0;
}
