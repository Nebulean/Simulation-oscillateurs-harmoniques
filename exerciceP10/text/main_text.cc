#include <iostream>
#include "text_viewer.h"
#include "contenu.h"
using namespace std;

int main()
{
  TextViewer ecran(cout);
  Contenu c(&ecran);

  cout << "Au départ :" << endl;
  c.dessine();

  c.evolue(0.1);
  cout << "Après un pas de calcul :" << endl;
  c.dessine();

  c.evolue(0.1);
  cout << "Après deux pas de calcul :" << endl;
  c.dessine();

  return 0;
}
