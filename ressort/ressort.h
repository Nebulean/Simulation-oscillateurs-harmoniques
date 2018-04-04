#ifndef RESSORT_H
#define RESSORT_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include "../supportadessin/supportadessin.h"

class Ressort : public Oscillateur {
public:

  // constructeurs
  Ressort(double, double, double, SupportADessin*);

  // méthode d'évolution
  Vecteur f(double);

  // méthode de dessin qui DOIT être implémenté dans toutes les sous-classes de Dessinable.
  virtual void dessine() override
  { _support->dessine(*this); }

private:
  double _m;
  double _k;
  double _lambda;
};

#endif // RESSORT_H
