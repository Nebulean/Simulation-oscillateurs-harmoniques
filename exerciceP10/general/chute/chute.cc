#include "chute.h"
#include <memory>
#include <iostream>
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
  return Vecteur({0, -9.81});
}
