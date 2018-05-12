#ifndef H_CHUTE
#define H_CHUTE

#include "oscillateur.h"
#include <memory>
#include <iostream>

/*!
 * Ce n'est pas à proprement parler un oscillateurs, mais c'est un bon exemple
 * pour tester les intégrateurs. Comme on en a besoin fréquemment, on en a
 * fait une classe à part entière.
 */
class Chute : public Oscillateur
{
public:
  //! Constructeur de Chute.
  Chute(double const& m, SupportADessin* vue, Vecteur const& position = {0, 1}, Vecteur const& vitesse = {1, 2}, Vecteur const& origine = {0, 1}, Vecteur const& direction_principale = {0, 1})
   : Oscillateur(position, vitesse, origine, direction_principale, vue), _m(m) {};

  //! Méthode retournant simplement le vecteur g.
  virtual Vecteur f(double t) override;

  virtual Vecteur f(double temps, Vecteur const& position, Vecteur const& vitesse) override;

  //! copie polymorphique
  std::unique_ptr<Oscillateur> copie() const override;
  //! utilisé pour la copie polymorphique
  std::unique_ptr<Chute> clone() const;


  //! Méthode de dessin qui DOIT être implémenté.
  virtual void dessine() override
  { _support->dessine(*this); }

private:
  //! Masse de l'objet en chute. Inutilisé.
  double _m;


  virtual void affiche(std::ostream& flot_de_sortie) const  override;
};

#endif // H_CHUTE
