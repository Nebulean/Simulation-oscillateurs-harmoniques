#include "ressort.h"
#include <iostream>
#include "../eulercromer/eulercromer.h"

using namespace std;

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
