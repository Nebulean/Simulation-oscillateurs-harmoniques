#include <iostream>
#include "oscillateur.h"
#include "../vecteur/vecteur.h"
using namespace std;

int main() {
  Oscillateur o1({1,2,3},{4,5,6});

  cout << o1 << endl;

  return 0;
}
