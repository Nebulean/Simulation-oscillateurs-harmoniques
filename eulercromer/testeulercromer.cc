#include "eulercromer.h"
#include "../oscillateur/oscillateur.h"
#include "../vecteur/vecteur.h"
using namespace std;

class Chute : public Oscillateur
{
public:
  Chute(double const& m) : Oscillateur({0,1}, {1,2}, {0,1}, {0,1}), _m(m) {};

  Vecteur f(double t) override{
    // dans cet exemple, t n'est pas utilisé.
    return Vecteur({0, -9.81});
  }

  /* Correctif du 29.03.18
   * cette classe chute ne fonctionne PLUS depuis que Oscillateur est un
   * dessinable.
   **/


private:
  double _m;
};

int main(){
  double t(0);
  double dt(0.01);
  Chute c(0.127);
  Eulercromer IEC;
  for(size_t i(0); i < 100; ++i){
    cout << c << endl;
    IEC.evolue(c, dt, t);
  }

  cout << c << endl;
  // Chute c(0.127);
  // Eulercromer integrateurEC;
  // cout << c << endl;
  // integrateurEC.evolue(c, 0.01, 1);
  // cout << c << endl;

  return 0;
}
