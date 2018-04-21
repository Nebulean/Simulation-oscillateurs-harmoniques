#include "systeme.h"
#include "../textviewer/textviewer.h"
#include "../pendule/pendule.h"
#include "../eulercromer/eulercromer.h"
#include <memory>

using namespace std;

int main() {

  TextViewer ecran(cout);
  Eulercromer IEC;
  Systeme syst(0.1, &ecran, &IEC);
  Pendule pendule(1, 1, 0, &ecran);

  syst.ajoute(new Pendule(pendule));
  syst.affiche();

  syst.evolue();
  syst.affiche();

  return 0;
}
