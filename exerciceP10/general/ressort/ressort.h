#ifndef RESSORT_H
#define RESSORT_H

#include "vecteur.h"
#include "oscillateur.h"
#include "supportadessin.h"
#include "dessinable.h"
#include <iostream>
#include <memory>
#include <cmath>

/*!
 * Class Ressort - un oscillateur particulier.
 */
class Ressort : public Oscillateur {
public:

  //! Constructeurs de ressort.
  Ressort(double masse, double elasticite, double viscosite, SupportADessin* support, Vecteur P = {0.18}, Vecteur Q = {0.0}, Vecteur O = {0.0, 0.0, 0.0}, Vecteur a = {0.8, 0.0, 0.6});

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

  //! Accesseur de la masse.
  double m() const {return _m; }

private:
  double _m; //!< masse
  double _k; //!< elasticité
  double _lambda; //!< viscosité

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot) const override;

  //! Méthode pour éviter les valeurs impossibles pour les paramètres des oscillateurs
  virtual void settodefault() override;
};

#endif // RESSORT_H
