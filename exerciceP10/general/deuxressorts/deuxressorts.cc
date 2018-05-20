#include <deuxressorts.h>
#include <initializer_list>
#include "vecteur.h"
#include "oscillateur.h"
#include <iostream>
#include "dessinable.h"
#include "supportadessin.h"
#include <vector>
#include "qglobal.h" // pour Q_UNUSED


using namespace std;

DeuxRessorts::DeuxRessorts(double m1, double m2, double L1, double L2, double L3, double k1, double k2, double k3, double lambda, SupportADessin* support, Vecteur P, Vecteur Q, Vecteur O)
 : Oscillateur(P, Q, O, {1.0, 0.0, 0.0}, support), _m1(m1), _m2(m2), _L1(L1), _L2(L2), _L3(L3), _k1(k1), _k2(k2), _k3(k3), _lambda(lambda)
 {
   if (m1 <= 0 or m2 <=0 or L1 <= 0 or L2 <= 0 or L3 <= 0) {
     cout << "DeuxRessorts: une ou plusieurs des valeurs entrées sont interdites." << endl;
     settodefault();
     cout << "Paramètres à valeurs interdites fixés à la valeur par défaut: 1.0." << endl;
   }
 }

/*!
 * Équation d'évolution du DeuxRessorts, définie comme dans le complément mathématique.
 *
 * Version "simple" ne dépendant que du temps et le P et Q de l'oscillateur.
 */
Vecteur DeuxRessorts::f(double t) {
  return f(t, P(), Q());
}

/*!
 * Équation d'évolution du DeuxRessorts, définie comme dans le complément mathématique.
 *
 * Version "simple" ne dépendant d'un P et Q particulier.
 */
Vecteur DeuxRessorts::f(double temps, Vecteur const& p, Vecteur const& q){
  Q_UNUSED(temps);
  double nouveau1, nouveau2;

  nouveau1 = -(_k1+_k3)/_m1 * p[0] + _k3/_m1 * p[1] - _lambda/_m1 * q[0];
  nouveau2 = _k3/_m2 * p[0] - (_k2+_k3)/_m2 * p[1] - _lambda/_m2 * q[1];

  return Vecteur({nouveau1, nouveau2});
}

// affiche textuellement le DeuxRessorts courant.
void DeuxRessorts::affiche(ostream& out) const {
  out << "*** Deux-Ressorts ***" << endl;
  // on affiche simplement les informations du DeuxRessorts.
  out << P() << " # parametre" << endl;
  out << Q() << " # vitesse" << endl;
}

unique_ptr<DeuxRessorts> DeuxRessorts::clone() const {
  return unique_ptr<DeuxRessorts>(new DeuxRessorts(*this));
}

unique_ptr<Oscillateur> DeuxRessorts::copie() const {
  return clone();
}

//! Applique la valeur par défaut de 1.0 à tous les paramètres qui ont une valeur physiquement impossible.
void DeuxRessorts::settodefault() {
  vector<double*> param {&_m1, &_m2, &_L1, &_L2, &_L3};
  for (auto el : param) {
    if (*el <= 0) *el = 1.0;
  }
}
