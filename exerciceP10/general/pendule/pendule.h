#ifndef PENDULE_H
#define PENDULE_H

#include "vecteur.h"
#include "oscillateur.h"
#include "dessinable.h"
#include "supportadessin.h"
#include <iostream>
#include <memory>
#include <cmath> // pour M_PI

/*!
 * Class Pendule - un oscillateur particulier.
 */
class Pendule : public Oscillateur {
public:
  //! Constructeurs de pendule.
  Pendule(double masse, double longueur, double viscosite, SupportADessin* support, Vecteur P = {M_PI/2}, Vecteur Q = {0.0}, Vecteur O = {0.0}, Vecteur a = {1.0, 0.0});

  //! Destructeur de pendule.
  virtual ~Pendule() {}

  //! Substitution de la méthode d'évolution.
  Vecteur f(double temps) override;

  //! Méthode de dessin qui DOIT être implémenté.
  virtual void dessine() override
  { _support->dessine(*this); }

  //! Requis pour la copie polymorphique de Pendule (pour les unique_ptr, voir cours).
  virtual std::unique_ptr<Pendule> clone() const;
  //! Copie polymorphique
  virtual std::unique_ptr<Oscillateur> copie() const override;


private:
  double _m; //!< masse
  double _L; //!< longueur
  double _lambda; //!< coefficient de viscosité

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot_de_sortie) const override;
};

#endif // PENDULE_H