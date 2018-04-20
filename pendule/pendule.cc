#include "pendule.h"
#include <cmath> // pour sin
#include <initializer_list>
#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include <iostream>
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"

using namespace std;

Pendule::Pendule(double m, double L, double lambda, SupportADessin* support, Vecteur P, Vecteur Q, Vecteur O, Vecteur a)
 : Oscillateur(P, Q, O, a, support), _m(m), _L(L), _lambda(lambda)
 {}

/*!
 * Équation d'évolution du pendule pesant, définie de cette manière:
 * f(t,P,Q) = (-g/L)sin(P1)-(lambda/(m*L^2))Q1
 */
Vecteur Pendule::f(double t) {
  return {(-9.81/_L) * sin(P().get_coord(0)) - _lambda/(_m*_L*_L) * Q().get_coord(0)};
}


// affiche textuellement le pendule courant.
void Pendule::affiche(ostream& out) const {
  out << "*** Pendule ***" << endl;
  // on affiche simplement les informations du pendule.
  out << P() << " # parametre" << endl;
  out << Q() << " # vitesse" << endl;
}


unique_ptr<Pendule> Pendule::clone() const {
  return unique_ptr<Pendule>(new Pendule(*this));
}

unique_ptr<Oscillateur> Pendule::copie() const {
  return clone();
}
