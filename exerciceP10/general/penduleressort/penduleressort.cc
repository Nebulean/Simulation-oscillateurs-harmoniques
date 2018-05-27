#include "penduleressort.h"
#include "vecteur.h"
#include "qglobal.h" // pour Q_UNUSED
#include <memory>

using namespace std;

PenduleRessort::PenduleRessort(double m, double l, double k, SupportADessin* s, Vecteur p, Vecteur v, Vecteur o )
 : Oscillateur(p, v, o, {1.0, 0.0, 0.0}, s), _m(m), _L(l), _k(k)
{
  // vérification des cas interdits.
  if (m <= 0 or l <=0 or k <= 0) {
     cout << "PenduleRessort: une ou plusieurs des valeurs entrées sont interdites." << endl;
     settodefault();
     cout << "Paramètres à valeurs interdites fixés à la valeur par défaut: 1.0." << endl;
   }
}


Vecteur PenduleRessort::f(double t)
{
  return f(t, P(), Q());
}


Vecteur PenduleRessort::f(double t, Vecteur const& p, Vecteur const& q)
{
  Q_UNUSED(q);
  Q_UNUSED(t);
  Vecteur g({0, -9.81});

  return g - _k/_m * (1 - _L/p.norme()) * p;
}


unique_ptr<PenduleRessort> PenduleRessort::clone() const
{
  return unique_ptr<PenduleRessort>(new PenduleRessort(*this));
}


 unique_ptr<Oscillateur> PenduleRessort::copie() const
 {
   return clone();
 }


 // Affiche textuellement le penduleressort courant.
 void PenduleRessort::affiche(ostream& out) const {
   out << "*** Pendule-Ressort ***" << endl;
   // on affiche simplement les informations du ressort.
   out << P() << " # parametre" << endl;
   out << Q() << " # vitesse" << endl;
 }

//! Applique la valeur par défaut de 1.0 à tous les paramètres qui ont une valeur physiquement impossible.
void PenduleRessort::settodefault() {
  vector<double*> param {&_m, &_L, &_k};
  for (auto el : param) {
    if (*el <= 0) *el = 1.0;
  }
}
