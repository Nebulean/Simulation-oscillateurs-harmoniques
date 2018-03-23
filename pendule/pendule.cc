#include "pendule.h"
#include <cmath> // pour sin
#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"

using namespace std;

Pendule::Pendule(double m, double L, double lambda)
 : Oscillateur({0.0},{0.0},{0.0}), _m(m), _L(l), _lambda(lambda)
 {}

Pendule::Vecteur f(double t) {
  return (-9.81/_L) * sin(P().get_coord(0)) - _lambda/(_m*_L*_L) * Q().get_coord(0);
}
