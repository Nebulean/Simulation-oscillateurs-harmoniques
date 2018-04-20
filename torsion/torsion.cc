#include "torsion.h"
#include <initializer_list>
#include <cmath> //pour M_PI
#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include <iostream>
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"

using namespace std;

Torsion::Torsion(double I, double C, double lambda, SupportADessin* support)
 : Oscillateur({M_PI/4}, {0.0}, {0.0}, {1.0, 0.0}, support), _I(I), _C(C), _lambda(lambda)
 {}

   /*!
    * Équation d'évolution du pendule de torsion, définie de cette manière:
    * f(t,P,Q) = -(C*P1 + lambda*Q1)/I
    */
Vecteur Torsion::f(double t){
  return {-(_C*P().get_coord(0)+_lambda*Q().get_coord(0))/_I};
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
