#include "ressort.h"
#include <initializer_list>
#include "vecteur.h"
#include "oscillateur.h"
#include "supportadessin.h"
#include <iostream>
#include <vector>

using namespace std;

Ressort::Ressort(double m, double k, double lambda, SupportADessin* support, Vecteur P, Vecteur Q, Vecteur O, Vecteur a)
 : Oscillateur(P, Q, O, a, support), _m(m), _k(k), _lambda(lambda)
 {
   if (m <= 0 or k <= 0 or lambda < 0) {
     cout << "Ressort: une ou plusieurs des valeurs entrées sont interdites." << endl;
     settodefault();
     cout << "Paramètres à valeurs interdites fixés à la valeur par défaut: 1.0." << endl;
   }
 }

/*!
 * Méthode d'évolution substituée.
 */
Vecteur Ressort::f(double t) {
  Vecteur g({0.0, 0.0, -9.81});
  return {-(_k/_m)*P(0) - (_lambda/_m)*Q(0) + g*a()};
}

// Affiche textuellement le ressort courant.
void Ressort::affiche(ostream& out) const {
  out << "*** Ressort ***" << endl;
  // on affiche simplement les informations du ressort.
  out << P() << " # parametre" << endl;
  out << Q() << " # vitesse" << endl;
}



unique_ptr<Ressort> Ressort::clone() const {
  return unique_ptr<Ressort>(new Ressort(*this));
}

unique_ptr<Oscillateur> Ressort::copie() const {
  return clone();
}

//! Applique la valeur par défaut de 1.0 à tous les paramètres qui ont une valeur physiquement impossible.
void Ressort::settodefault() {
  vector<double*> param {&_m, &_k};
  for (auto el : param) {
    if (*el <= 0) *el = 1.0;
  }
  if (_lambda < 0) _m = 1.0;
}
