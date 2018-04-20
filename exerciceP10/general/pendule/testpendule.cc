#include "pendule.h"
#include <iostream>
#include "../eulercromer/eulercromer.h"
#include "../supportadessin/supportadessin.h"

using namespace std;

int main(){

  // test avant P8.
  Pendule pendule(1, 1, 0);
  Eulercromer IEC;
  cout << pendule << endl;

  for (size_t i = 0; i<3; ++i) {
    IEC.evolue(pendule, 0.1, 0); //dt = 0.1 ; t = 0 (arbitraire)
    cout << pendule << endl;
  }

  return 0;
}
