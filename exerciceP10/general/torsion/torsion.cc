#include "torsion.h"
#include <initializer_list>
#include "vecteur.h"
#include "oscillateur.h"
#include <iostream>
#include "dessinable.h"
#include "supportadessin.h"
#include <vector>
#include "qglobal.h"

using namespace std;

Torsion::Torsion(double I, double C, double lambda, SupportADessin* support, Vecteur P, Vecteur Q, Vecteur O)
 : Oscillateur(P, Q, O, {1.0, 0.0, 0.0}, support), _I(I), _C(C), _lambda(lambda), _positionInitiale(P)
 {
   if (I <= 0 or C < 0 or lambda < 0) {
     cout << "Torsion: une ou plusieurs des valeurs entrées sont interdites." << endl;
     settodefault();
     cout << "Paramètres à valeurs interdites fixés à la valeur par défaut: 1.0." << endl;
   }
 }

   /*!
    * Équation d'évolution du pendule de torsion, définie de cette manière:
    * f(t,P,Q) = -(C*P1 + lambda*Q1)/I
    */
Vecteur Torsion::f(double t){
  return f(t, P(), Q());
}

Vecteur Torsion::f(double temps, Vecteur const& p, Vecteur const& q){
  Q_UNUSED(temps);
  return {-(_C*p[0]+_lambda*q[0])/_I};
}

// affiche textuellement le pendule de torsion courant.
void Torsion::affiche(ostream& out) const {
  out << "*** Pendule de torsion ***" << endl;
  // on affiche simplement les informations du pendule.
  out << P() << " # parametre" << endl;
  out << Q() << " # vitesse" << endl;
}

unique_ptr<Torsion> Torsion::clone() const {
  return unique_ptr<Torsion>(new Torsion(*this));
}

unique_ptr<Oscillateur> Torsion::copie() const {
  return clone();
}

//! Applique la valeur par défaut de 1.0 à tous les paramètres qui ont une valeur physiquement impossible.
void Torsion::settodefault() {
  if (_I <= 0) _I = 1.0;
  vector<double*> param {&_C, &_lambda};
  for (auto el : param) {
    if (*el < 0) *el = 1.0;
  }
}
