#ifndef PENDULE_H
#define PENDULE_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"


class Pendule : public Oscillateur {
public:
  // constructeurs de pendule
  Pendule(double masse, double longueur, double viscosite, SupportADessin* support);

  // destructeur de pendule
  virtual ~Pendule() {};

  // substitution de la méthode d'évolution
  Vecteur f(double temps) override;

  // méthode de dessin qui DOIT être implémenté dans toutes les sous-classes de Dessinable.
  virtual void dessine() override
  { _support->dessine(*this); }

private:
  double _m; // masse
  double _L; // longueur
  double _lambda; // coefficient de viscosité
};

#endif // PENDULE_H
