#ifndef RESSORT_H
#define RESSORT_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"

class Ressort : public Oscillateur {
public:

// constructeurs
  Ressort(double, double, double);

// méthode d'évolution
  Vecteur f(double);

private:
  double _m;
  double _k;
  double _lambda;
};

#endif // RESSORT_H
