#include "chariot.h"
#include <cmath> // pour cos et sin
#include <initializer_list>
#include "vecteur.h"
#include "oscillateur.h"
#include <iostream>
#include "dessinable.h"
#include "supportadessin.h"
#include "qglobal.h" // pour Q_UNUSED

using namespace std;

Chariot::Chariot(double m1, double m2, double L, double k, double lambda, double mu, SupportADessin* support, Vecteur P, Vecteur Q, Vecteur O, Vecteur a)
 : Oscillateur(P, Q, O, a, support), _m1(m1), _m2(m2), _L(L), _k(k), _lambda(lambda), _mu(mu)
 {}

/*!
 * Équation d'évolution du chariot avec pendule amorti par un ressort
 * défini de cette manière:
 * f(t,P,Q) = 1/A{-B+m2*C*cos(P2), (B*cos(P2)-M*C)/L}
 * avec M, A, B, C définis comme ci-dessous
 */
Vecteur Chariot::f(double t) {
  return f(t, P(), Q());
}

Vecteur Chariot::f(double temps, Vecteur const& p, Vecteur const& q) {
  Q_UNUSED(temps);
  double M(_m1 + _m2);
  double A(_m1 + _m2*sin(p[1])*sin(p[1]));
  double B(_k*p[0] + _lambda*q[0] - _m2*_L*q[1]*q[1]*sin(p[1]));
  double C(9.81*sin(p[1]) + _mu*q[1]);
  return 1/A * Vecteur({-B + _m2*C*cos(p[1]), (B*cos(p[1]) - M*C)/_L});
}

// affiche textuellement le chariot courant.
void Chariot::affiche(ostream& out) const {
  out << "*** Chariot avec pendule ***" << endl;
  // on affiche simplement les informations du chariot.
  out << P() << " # parametre" << endl;
  out << Q() << " # vitesse" << endl;
}

unique_ptr<Chariot> Chariot::clone() const {
  return unique_ptr<Chariot>(new Chariot(*this));
}

unique_ptr<Oscillateur> Chariot::copie() const {
  return clone();
}
