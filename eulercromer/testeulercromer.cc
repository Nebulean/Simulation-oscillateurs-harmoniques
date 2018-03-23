#include "eulercromer.h"
#include "../oscillateur/oscillateur.h"
#include "../vecteur/vecteur.h"
using namespace std;

class Chute : public Oscillateur
{
public:
  Chute() : Oscillateur({0,0}, {0,0}, {0,0}) {};
  Chute(double const& m) : Oscillateur({0,0}, {0,0}, {0,0}), _m(m) {};

  Vecteur f(double t){
    // dans cet exemple, t n'est pas utilisé.
    return Vecteur({0, -9.81});
  }

private:
  double _m;
};

int main(){
  double t(0);
  Chute c;
  Eulercromer integrateurEC;
  cout << c << endl;
  
  // Chute c(0.127);
  // Eulercromer integrateurEC;
  // cout << c << endl;
  // integrateurEC.evolue(c, 0.01, 1);
  // cout << c << endl;

  return 0;
}
