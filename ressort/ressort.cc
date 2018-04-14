#include "ressort.h"
#include <initializer_list>
#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include "../supportadessin/supportadessin.h"

Ressort::Ressort(double m, double k, double lambda, SupportADessin* support)
 : Oscillateur({0.18},{0.0},{0.0, 0.0, 0.0},{0.8, 0.0, 0.6}, support), _m(m), _k(k), _lambda(lambda)
 {}

Vecteur Ressort::f(double t) {
  Vecteur g({0.0, 0.0, -9.81});
  return Vecteur{-(_k/_m)*P().get_coord(0) - (_lambda/_m)*Q().get_coord(0) + g*a()};
}
