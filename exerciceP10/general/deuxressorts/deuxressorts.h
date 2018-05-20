#ifndef DEUXRESSORTS_H
#define DEUXRESSORTS_H

#include "vecteur.h"
#include "oscillateur.h"
#include "dessinable.h"
#include "supportadessin.h"
#include <iostream>
#include <memory>

class DeuxRessorts : public Oscillateur {
public:
  //! Constructeur du DeuxRessorts
  DeuxRessorts(double masse1, double masse2, double longeur1, double longeur2, double longeur3, double raideur1, double raideur2, double raideur3, double lambda, SupportADessin* support, Vecteur P = {0.18, -0.18}, Vecteur Q = {0.0, 0.0}, Vecteur O = {0.0, 0.0, 0.0});

  //! Destructeur de DeuxRessorts
  virtual ~DeuxRessorts() {}

  //! Substitution de la méthode d'évolution
  virtual Vecteur f(double temps) override;

  virtual Vecteur f(double temps, Vecteur const& position, Vecteur const& vitesse) override;


  //! Méthode de dessin qui DOIT être implémentée.
  virtual void dessine() override
  { _support->dessine(*this); }

  //! Requis pour la copie polymorphique de DeuxRessorts (pour les unique_ptr, voir cours).
  std::unique_ptr<DeuxRessorts> clone() const;
  //! Copie polymorphique
  virtual std::unique_ptr<Oscillateur> copie() const override;

  //!Accesseurs
  // double m1() const {return _m1;}
  // double m2() const {return _m2;}
  // double L1() const {return _L1;}
  // double L2() const {return _L2;}

private:
  double _m1; //!< masse du premier ressort
  double _m2; //!< masse du deuxième ressort
  double _L1; //!< longeur du premier ressort
  double _L2; //!< longeur du deuxième ressort
  double _L3; //!< longeur du troisième ressort
  double _k1; //!< Constante de raideur du premier ressort
  double _k2; //!< Constante de raideur du deuxième ressort
  double _k3; //!< Constante de raideur du troisième ressort
  double _lambda; //!< Variable interne de l'oscillateur deuxRessorts.

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot_de_sortie) const override;

  //! Méthode pour éviter les valeurs impossibles pour les paramètres des oscillateurs
  virtual void settodefault() override;
};

#endif // DEUXRESSORTS_H
