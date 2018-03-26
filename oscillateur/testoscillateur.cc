#include <iostream>
#include "oscillateur.h"
#include "../vecteur/vecteur.h"
using namespace std;

int main() {
  cout << "Tests de constructeurs" << endl;
  Oscillateur o1({1,2,3},{4,5,6},{0,0,0},{1,0,0});
  cout << o1 << endl;

  // Test getters
  cout << "Test getters:" << endl;
  cout << "P() - " << o1.P() << endl;
  cout << "Q() - " << o1.Q() << endl;
  cout << "a() - " << o1.a() << endl;

  return 0;
}
