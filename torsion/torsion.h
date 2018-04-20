#ifndef TORSION_H
#define TORSION_H

#include "../vecteur/vecteur.h"
#include "../oscillateur/oscillateur.h"
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"
#include <iostream>
#include <memory>
#include <cmath>

class Torsion : public Oscillateur {
public:
  //! Constructeur de pendule de torsion
  Torsion(double moment_inertie, double constante_torsion, double friction, SupportADessin* support, Vecteur P = {M_PI/4}, Vecteur Q = {0.0}, Vecteur O = {0.0}, Vecteur a = {1.0, 0.0});

  //! Destructeur de pendule de torsion
  virtual ~Torsion() {}

  //! Substitution de la méthode d'évolution.
  Vecteur f(double temps) override;

  //! Méthode de dessin qui DOIT être implémenté.
  virtual void dessine() override
  { _support->dessine(*this); }

  //! Requis pour la copie polymorphique de Torsion (pour les unique_ptr, voir cours).
  virtual std::unique_ptr<Torsion> clone() const;
  //! Copie polymorphique
  virtual std::unique_ptr<Oscillateur> copie() const override;

private:
  double _I; //!< moment d'inertie
  double _C; //!< constante de torsion
  double _lambda; //!< coefficient de friction radiale

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot_de_sortie) const override;
};

#endif // TORSION_H
