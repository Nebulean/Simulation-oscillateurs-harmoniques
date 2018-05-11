#include <penduledouble.h>
#include <cmath> // pour cos et sin
#include <initializer_list>
#include "vecteur.h"
#include "oscillateur.h"
#include <iostream>
#include "dessinable.h"
#include "supportadessin.h"

using namespace std;

PenduleDouble::PenduleDouble(double m1, double m2, double L1, double L2, SupportADessin* support, Vecteur P, Vecteur Q, Vecteur O)
 : Oscillateur(P, Q, O, {1.0, 0.0, 0.0}, support), _m1(m1), _m2(m2), _L1(L1), _L2(L2)
 {}

/*!
 * Équation d'évolution du pendule double, définie comme dans le complément mathématique
 */
Vecteur PenduleDouble::f(double t) {
  double M(_m1 + _m2);
  double dP(P(0)-P(1));
  double A(_m1 + _m2*sin(dP)*sin(dP));
  double B(cos(dP)*sin(dP));
  double g(9.81);
  return 1/A * Vecteur({(_m2*g*cos(dP)*sin(P(1)) - M*g*sin(P(0)) - _m2*_L1*Q(0)*Q(0)*B - _m2*_L2*Q(1)*Q(1)*sin(dP))/_L1, (M*g*cos(dP)*sin(P(0))
    - M*g*sin(P(1)) + _m2*_L2*Q(1)*Q(1)*B + M*_L1*Q(0)*Q(0)*sin(dP))/_L2});
}

// affiche textuellement le pendule double courant.
void PenduleDouble::affiche(ostream& out) const {
  out << "*** Pendule double ***" << endl;
  // on affiche simplement les informations du chariot.
  out << P() << " # parametre" << endl;
  out << Q() << " # vitesse" << endl;
}

unique_ptr<PenduleDouble> PenduleDouble::clone() const {
  return unique_ptr<PenduleDouble>(new PenduleDouble(*this));
}

unique_ptr<Oscillateur> PenduleDouble::copie() const {
  return clone();
}
