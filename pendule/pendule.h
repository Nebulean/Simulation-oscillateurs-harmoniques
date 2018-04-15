#ifndef PENDULE_H
#define PENDULE_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"

/*!
 * Class Pendule - un oscillateur particulier.
 */
class Pendule : public Oscillateur {
public:
  //! Constructeurs de pendule.
  Pendule(double masse, double longueur, double viscosite, SupportADessin* support);

  //! Destructeur de pendule.
  virtual ~Pendule() {};

  //! Substitution de la méthode d'évolution.
  Vecteur f(double temps) override;

  //! Méthode de dessin qui DOIT être implémenté.
  virtual void dessine() override
  { _support->dessine(*this); }

private:
  double _m; //!< masse
  double _L; //!< longueur
  double _lambda; //!< coefficient de viscosité
};

#endif // PENDULE_H
