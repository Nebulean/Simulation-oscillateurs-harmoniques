#ifndef TORSION_H
#define TORSION_H

#include "vecteur.h"
#include "oscillateur.h"
#include "dessinable.h"
#include "supportadessin.h"
#include <iostream>
#include <memory>
#include <cmath>

class Torsion : public Oscillateur {
public:
  //! Constructeur de pendule de torsion
  Torsion(double moment_inertie, double constante_torsion, double friction, SupportADessin* support, Vecteur P = {M_PI/4}, Vecteur Q = {0.0}, Vecteur O = {0.0, 0.0, 0.0}, Vecteur a = {1.0, 0.0, 0.0});

  //! Destructeur de pendule de torsion
  virtual ~Torsion() {}

  //! Substitution de la méthode d'évolution.
  virtual Vecteur f(double temps) override;

  virtual Vecteur f(double temps, Vecteur const& position, Vecteur const& vitesse) override;


  //! Méthode de dessin qui DOIT être implémentée.
  virtual void dessine() override
  { _support->dessine(*this); }

  //! Requis pour la copie polymorphique de Torsion (pour les unique_ptr, voir cours).
  std::unique_ptr<Torsion> clone() const;
  //! Copie polymorphique
  virtual std::unique_ptr<Oscillateur> copie() const override;

  //! Accesseur du moment d'inertie.
  double I() const {return _I; }

  //! Retourne la valeur maximal (ou une valeur haute) de la torsion du pendule.
  double getMaxAngle() const {return _positionInitiale.get_coord(0);}

private:
  double _I; //!< moment d'inertie
  double _C; //!< constante de torsion
  double _lambda; //!< coefficient de friction radiale

  Vecteur _positionInitiale; //!< Position initiale du pendule. Utile pour les couleurs du pendule pour OpenGL.

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot_de_sortie) const override;
};

#endif // TORSION_H
