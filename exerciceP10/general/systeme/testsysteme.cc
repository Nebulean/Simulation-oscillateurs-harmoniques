#include "systeme.h"
#include "textviewer.h"
#include "pendule.h"
#include "eulercromer.h"
#include <memory>

using namespace std;

int main() {

  TextViewer ecran(cout);
  Eulercromer IEC;
  Systeme syst(0.1, &ecran, &IEC);
  Pendule pendule(1, 1, 0, &ecran);

  syst.ajoute(pendule);
  cout << syst << endl;

  syst.evolue();
  cout << syst << endl;

  return 0;
}
