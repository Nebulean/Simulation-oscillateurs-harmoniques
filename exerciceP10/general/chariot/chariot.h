#ifndef CHARIOT_H
#define CHARIOT_H

#include "vecteur.h"
#include "oscillateur.h"
#include "dessinable.h"
#include "supportadessin.h"
#include <iostream>
#include <memory>
#include <cmath>

class Chariot : public Oscillateur{
public:
  //!Constructeur du chariot avec pendule amorti par un ressort
  Chariot(double masse1, double masse2, double longueur_pendule, double elasticite, double friciton1, double friction2, SupportADessin* support, Vecteur P = {1.0, M_PI/3}, Vecteur Q = {0.0, 0.0}, Vecteur O = {0.0, 0.0, 0.0}, Vecteur a = {1.0, 0.0, 0.0});

  //!Destructeur de Chariot
  virtual ~Chariot() {}

  //! Substitution de la méthode d'évolution.
  Vecteur f(double temps) override;

  //! Méthode de dessin qui DOIT être implémentée.
  virtual void dessine() override
  { _support->dessine(*this); }

  //! Requis pour la copie polymorphique de Pendule (pour les unique_ptr, voir cours).
  virtual std::unique_ptr<Chariot> clone() const;
  //! Copie polymorphique
  virtual std::unique_ptr<Oscillateur> copie() const override;

  //! Accesseurs
  double m1() const {return _m1;}
  double m2() const {return _m2;}
  double L() const {return _L;}

private:
  double _m1; //!< masse du chariot
  double _m2; //!< masse du pendule
  double _L; //!< longueur du pendule
  double _k; //!< coefficient d'elasticite du ressort
  double _lambda; //!< coefficient de frottement du chariot
  double _mu; //!< coefficient de frottement du pendule

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot_de_sortie) const override;
};

#endif // CHARIOT_H
