#include "pendule.h"
#include <cmath> // pour sin
#include <initializer_list>
#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"

using namespace std;

Pendule::Pendule(double m, double L, double lambda)
 : Oscillateur({M_PI/2},{0.0},{0.0}), _m(m), _L(L), _lambda(lambda)
 {}

/* Équation d'évolution du pendule pesant:
 *f(t,P,Q) = (-g/L)sin(P1)-(lambda/(m*L²))Q1
 */

Vecteur Pendule::f(double t) {
  return {(-9.81/_L) * sin(P().get_coord(0)) - _lambda/(_m*_L*_L) * Q().get_coord(0)};
}
