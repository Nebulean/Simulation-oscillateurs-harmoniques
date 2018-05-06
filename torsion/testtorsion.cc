#include "torsion.h"
#include <iostream>
#include "../eulercromer/eulercromer.h"
#include "../textviewer/textviewer.h"

using namespace std;

int main() {

  TextViewer ecran(cout);
  Eulercromer IEC;
  Torsion torsion(1, 0.33, 0, &ecran);
  cout << torsion << endl;

  for (size_t i = 0; i<3; ++i) {
    IEC.evolue(torsion, 0.1, 0); //dt = 0.1 ; t = 0 (arbitraire)
    cout << torsion << endl;
  }

  return 0;
}
