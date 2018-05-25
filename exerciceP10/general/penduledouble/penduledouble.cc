#include <penduledouble.h>
#include <cmath> // pour cos et sin
#include <initializer_list>
#include "vecteur.h"
#include "oscillateur.h"
#include <iostream>
#include "dessinable.h"
#include "supportadessin.h"
#include <vector>
#include "qglobal.h" // pour Q_UNUSED


using namespace std;

PenduleDouble::PenduleDouble(double m1, double m2, double L1, double L2, SupportADessin* support, Vecteur P, Vecteur Q, Vecteur O)
 : Oscillateur(P, Q, O, {1.0, 0.0, 0.0}, support), _m1(m1), _m2(m2), _L1(L1), _L2(L2)
 {
   if (m1 <= 0 or m2 <=0 or L1 <= 0 or L2 <= 0) {
     cout << "PenduleDouble: une ou plusieurs des valeurs entrées sont interdites." << endl;
     settodefault();
     cout << "Paramètres à valeurs interdites fixés à la valeur par défaut: 1.0." << endl;
   }
 }

/*!
 * Équation d'évolution du pendule double, définie comme dans le complément mathématique
 */
Vecteur PenduleDouble::f(double t) {
  return f(t, P(), Q());
}

Vecteur PenduleDouble::f(double temps, Vecteur const& p, Vecteur const& q){
  Q_UNUSED(temps);
  double M(_m1 + _m2);
  double dP(p[0]-p[1]);
  double A(_m1 + _m2*sin(dP)*sin(dP));
  double B(cos(dP)*sin(dP));
  double g(9.81);

  return 1/A * Vecteur({(_m2*g*cos(dP)*sin(p[1]) - M*g*sin(p[0]) - _m2*_L1*q[0]*q[0]*B - _m2*_L2*q[1]*q[1]*sin(dP))/_L1, (M*g*cos(dP)*sin(p[0])
    - M*g*sin(p[1]) + _m2*_L2*q[1]*q[1]*B + M*_L1*q[0]*q[0]*sin(dP))/_L2});
}

// affiche textuellement le pendule double courant.
void PenduleDouble::affiche(ostream& out) const {
  out << "*** Pendule double ***" << endl;
  // on affiche simplement les informations du penduledouble.
  out << P() << " # parametre" << endl;
  out << Q() << " # vitesse" << endl;
}

unique_ptr<PenduleDouble> PenduleDouble::clone() const {
  return unique_ptr<PenduleDouble>(new PenduleDouble(*this));
}

unique_ptr<Oscillateur> PenduleDouble::copie() const {
  return clone();
}

//! Applique la valeur par défaut de 1.0 à tous les paramètres qui ont une valeur physiquement impossible.
void PenduleDouble::settodefault() {
  vector<double*> param {&_m1, &_m2, &_L1, &_L2};
  for (auto el : param) {
    if (*el <= 0) *el = 1.0;
  }
}
