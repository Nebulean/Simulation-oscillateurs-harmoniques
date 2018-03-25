#ifndef PENDULE_H
#define PENDULE_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"

class Pendule : public Oscillateur {
public:

// constructeurs
  Pendule(double, double, double);

// méthode d'évolution
  Vecteur f(double);

private:
  double _m; // masse
  double _L; // longueur
  double _lambda; // coefficient de viscosité
};

#endif // PENDULE_H
