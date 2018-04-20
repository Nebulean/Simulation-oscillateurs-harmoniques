#include "ressort.h"
#include <initializer_list>
#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include "../supportadessin/supportadessin.h"
#include <iostream>

using namespace std;

Ressort::Ressort(double m, double k, double lambda, SupportADessin* support)
 : Oscillateur({0.18},{0.0},{0.0, 0.0, 0.0},{0.8, 0.0, 0.6}, support), _m(m), _k(k), _lambda(lambda)
 {}

/*!
 * Méthode d'évolution substituée.
 */
Vecteur Ressort::f(double t) {
  Vecteur g({0.0, 0.0, -9.81});
  return {-(_k/_m)*P().get_coord(0) - (_lambda/_m)*Q().get_coord(0) + g*a()};
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
