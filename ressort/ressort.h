#ifndef RESSORT_H
#define RESSORT_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include "../supportadessin/supportadessin.h"
#include "../dessinable/dessinable.h"
#include <iostream>
#include <memory>

/*!
 * Class Ressort - un oscillateur particulier.
 */
class Ressort : public Oscillateur {
public:

  //! Constructeurs de ressort.
  Ressort(double masse, double elasticite, double viscosite, SupportADessin* support);

  //! Destructeur de ressort.
  virtual ~Ressort() {}

  //! Méthode d'évolution propre à l'oscillateur.
  Vecteur f(double temps) override;

  //! Méthode de dessin qui DOIT être implémenté.
  virtual void dessine() override
  { _support->dessine(*this); }

  //! Requis pour la copie polymorphique de Ressort (pour les unique_ptr, voir cours).
  virtual std::unique_ptr<Ressort> clone() const;
  //! Copie polymorphique
  virtual std::unique_ptr<Oscillateur> copie() const override;


private:
  double _m; //!< masse
  double _k; //!< elasticité
  double _lambda; //!< viscosité

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot) const override;
};

#endif // RESSORT_H
