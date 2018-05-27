#include "ressort.h"
#include <iostream>
#include "../eulercromer/eulercromer.h"

using namespace std;

/* Correctif du 27.05.18
 * Ce test n'est plus fonctionnel, pour des questions de dépendances et de
 * changements de conception.
 */

int main() {

  Ressort ressort(0.25, 0.33, 0.15);
  Eulercromer IEC;
  cout << ressort << endl;

  for (size_t i=0; i<3; ++i) {
    IEC.evolue(ressort, 0.01, 0);
    cout << ressort << endl;
  }

  return 0;
}
