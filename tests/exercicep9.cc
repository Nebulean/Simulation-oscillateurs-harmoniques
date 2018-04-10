#include "../systeme/systeme.h"
#include "../eulercromer/eulercromer.h"
#include "../pendule/pendule.h"
#include "../ressort/ressort.h"
#include "../textviewer/textviewer.h"
#include "../oscillateur/oscillateur.h"
#include "../vecteur/vecteur.h"
#include "../dessinable/dessinable.h"

using namespace std;

int main() {

  TextViewer ecran(cout);
  Eulercromer IEC;
  Systeme syst1(0.1, 0, &ecran, &IEC);
  Pendule pendule(1, 1, 0, &ecran);
  Ressort ressort(0.25, 0.33, 0.15, &ecran);

  syst1.ajoute(new Pendule(pendule));
  syst1.ajoute(new Ressort(ressort));
  cout << "Système 1:" << endl;
  cout << "ÉTAT INITIAL" << endl;
  syst1.affiche();

  for (size_t i = 0; i < 3; ++i) {
    cout << "ÉTAPE " << i+1 << endl;
    syst1.evolue();
    syst1.affiche();
  };

  Systeme syst2(0.01, 0, &ecran, &IEC);

  syst2.ajoute(new Pendule(pendule));
  syst2.ajoute(new Ressort(ressort));
  cout << "********" << endl;
  cout << "Système 2:" << endl;
  cout << "ÉTAT INITIAL" << endl;
  syst2.affiche();

  for (size_t i = 0; i < 3; ++i) {
    cout << "ÉTAPE " << i+1 << endl;
    syst2.evolue();
    syst2.affiche();
  };

  return 0;
}
