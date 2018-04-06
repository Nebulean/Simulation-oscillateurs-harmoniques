#include "systeme.h"
#include "../textviewer/textviewer.h"
#include "../pendule/pendule.h"
#include <memory>

using namespace std;

int main() {

  TextViewer ecran(cout);
  Systeme syst(1, 0, &ecran);
  Pendule pendule(1, 1, 0, &ecran);

  syst.ajoute(new Pendule(pendule));
  syst.affiche();

  return 0;
}
