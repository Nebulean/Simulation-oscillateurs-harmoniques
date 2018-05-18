#include "pendule.h"
#include <cmath> // pour sin
#include <initializer_list>
#include "vecteur.h"
#include "oscillateur.h"
#include <iostream>
#include "dessinable.h"
#include "supportadessin.h"
#include <vector>
#include "qglobal.h" // pour Q_UNUSED

using namespace std;

Pendule::Pendule(double m, double L, double lambda, SupportADessin* support, Vecteur P, Vecteur Q, Vecteur O)
 : Oscillateur(P, Q, O, {1.0, 0.0, 0.0}, support), _m(m), _L(L), _lambda(lambda)
 {
   if (m <= 0 or L <= 0 or lambda < 0) {
     cout << "Pendule: une ou plusieurs des valeurs entrées sont interdites." << endl;
     settodefault();
     cout << "Paramètres à valeurs interdites fixés à la valeur par défaut: 1.0." << endl;
   }
 }

/*!
 * Équation d'évolution du pendule pesant, définie de cette manière:
 * f(t,P,Q) = (-g/L)sin(P1)-(lambda/(m*L^2))Q1
 */
Vecteur Pendule::f(double t) {
  return f(t, P(), Q());
}

Vecteur Pendule::f(double temps, Vecteur const& p, Vecteur const& q){
  Q_UNUSED(temps);
  return {(-9.81/_L) * sin(p[0]) - _lambda/(_m*_L*_L) * q[0]};
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

//! Applique la valeur par défaut de 1.0 à tous les paramètres qui ont une valeur physiquement impossible.
void Pendule::settodefault() {
  vector<double*> param {&_m, &_L};
  for (auto el : param) {
    if (*el <= 0) *el = 1.0;
  }
  if (_lambda < 0) _lambda = 1.0;
}
