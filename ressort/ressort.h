#ifndef RESSORT_H
#define RESSORT_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include "../supportadessin/supportadessin.h"
#include "../dessinable/dessinable.h"

/*!
 * Class Ressort - un oscillateur particulier.
 */
class Ressort : public Oscillateur {
public:

  //! Constructeurs de ressort.
  Ressort(double masse, double elasticite, double viscosite, SupportADessin* support);

  //! Destructeur de ressort.
  virtual ~Ressort() {};

  //! Méthode d'évolution propre à l'oscillateur.
  Vecteur f(double temps) override;

  //! Méthode de dessin qui DOIT être implémenté.
  virtual void dessine() override
  { _support->dessine(*this); }

private:
  double _m; //!< masse
  double _k; //!< elasticité
  double _lambda; //!< viscosité
};

#endif // RESSORT_H
