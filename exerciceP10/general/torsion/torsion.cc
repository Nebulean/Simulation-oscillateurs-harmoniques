#include "torsion.h"
#include <initializer_list>
#include "vecteur.h"
#include "oscillateur.h"
#include <iostream>
#include "dessinable.h"
#include "supportadessin.h"

using namespace std;

Torsion::Torsion(double I, double C, double lambda, SupportADessin* support, Vecteur P, Vecteur Q, Vecteur O, Vecteur a)
 : Oscillateur(P, Q, O, a, support), _I(I), _C(C), _lambda(lambda), _positionInitiale(P)
 {}

   /*!
    * Équation d'évolution du pendule de torsion, définie de cette manière:
    * f(t,P,Q) = -(C*P1 + lambda*Q1)/I
    */
Vecteur Torsion::f(double t){
  return {-(_C*P(0)+_lambda*Q(0))/_I};
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
