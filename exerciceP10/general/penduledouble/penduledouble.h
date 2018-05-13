#ifndef PENDULEDOUBLE_H
#define PENDULEDOUBLE_H

#include "vecteur.h"
#include "oscillateur.h"
#include "dessinable.h"
#include "supportadessin.h"
#include <iostream>
#include <memory>
#include <cmath>

class PenduleDouble : public Oscillateur {
public:
  //!Constructeur du pendule double
  PenduleDouble(double masse1, double masse2, double longueur1, double longueur2, SupportADessin* support, Vecteur P = {M_PI/3, M_PI/3}, Vecteur Q = {0.0, 0.0}, Vecteur O = {0.0, 0.0, 0.0});

  //!Destructeur de PenduleDouble
  virtual ~PenduleDouble() {}

  //! Substitution de la méthode d'évolution
  virtual Vecteur f(double temps) override;

  virtual Vecteur f(double temps, Vecteur const& position, Vecteur const& vitesse) override;


  //! Méthode de dessin qui DOIT être implémentée.
  virtual void dessine() override
  { _support->dessine(*this); }

  //! Requis pour la copie polymorphique de Pendule (pour les unique_ptr, voir cours).
  virtual std::unique_ptr<PenduleDouble> clone() const;
  //! Copie polymorphique
  virtual std::unique_ptr<Oscillateur> copie() const override;

  //!Accesseurs
  double m1() const {return _m1;}
  double m2() const {return _m2;}
  double L1() const {return _L1;}
  double L2() const {return _L2;}

private:
  double _m1; //!< masse du premier pendule
  double _m2; //!< masse du deuxième pendule
  double _L1; //!< longueur du premier pendule
  double _L2; //!< longueur du deuxième pendule

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot_de_sortie) const override;
};

#endif // PENDULEDOUBLE_H
