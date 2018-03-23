#ifndef PENDULE_H
#define PENDULE_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"

class Pendule : public Oscillateur {
public:

// constructeurs
  Pendule(double m, double L, double _lambda);

private:
  double _m;
  double _L;
  double _lambda;
};

#endif // PENDULE_H
