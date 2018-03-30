#ifndef PENDULE_H
#define PENDULE_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"

class Pendule : public Oscillateur, public Dessinable {
public:

  // constructeurs
  Pendule(double, double, double, SupportADessin* = nullptr);

  // destructeur
  virtual ~Pendule();

  // méthode d'évolution
  Vecteur f(double) override;

  // méthode de dessin qui DOIT être implémenté dans toutes les sous-classes de Dessinable.
  virtual void dessine() override
  { _support->dessine(*this); }

  // la méthode de dessin.
  // void dessine();
  /* Cette méthode n'est pas ici ! Elle se situera dans, par exemple,
   * les fichers de simulation en mode texte ou graphique.
   */


private:
  double _m; // masse
  double _L; // longueur
  double _lambda; // coefficient de viscosité
};

#endif // PENDULE_H
