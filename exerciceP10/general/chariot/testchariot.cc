#include "chariot.h"
#include <iostream>
#include "eulercromer.h"
#include "textviewer.h"

using namespace std;

int main() {

  /* Correctif du 27.05.18
   * Ce fichier test n'est plus compilable, il lui manque des dépendances et
   * il faudrait lui apporter quelques corrections.
   */

  TextViewer ecran(cout);
  Eulercromer IEC;
  Chariot chariot(1, 1, 1, 0.33, 0.1, 0.1, &ecran);
  cout << chariot << endl;

  for (size_t i = 0; i<3; ++i) {
    IEC.evolue(chariot, 0.1, 0); //dt = 0.1 ; t = 0 (arbitraire)
    cout << chariot << endl;
  }

  return 0;
}
