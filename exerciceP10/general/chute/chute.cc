#include "chute.h"
#include <memory>
#include <iostream>
#include "qglobal.h" // pour Q_UNUSED
using namespace std;



unique_ptr<Chute> Chute::clone() const {
  return unique_ptr<Chute>(new Chute(*this));
}

unique_ptr<Oscillateur> Chute::copie() const {
  return clone();
}

void Chute::affiche(std::ostream& out) const {
  out << "Chute" << endl;
  out << P() << " # position" << endl;
  out << Q() << " # vitesse" << endl;
}


Vecteur Chute::f(double t) {
  return f(t, P(), Q());
}


Vecteur Chute::f(double temps, Vecteur const& p, Vecteur const& q){
  Q_UNUSED(temps);
  Q_UNUSED(p);
  Q_UNUSED(q);

  return Vecteur({0, -9.81});
}
