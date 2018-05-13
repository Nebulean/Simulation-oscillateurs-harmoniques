#ifndef H_CHUTE
#define H_CHUTE

#include "oscillateur.h"
#include <memory>
#include <iostream>

// C'est un copier-coller modifié. ;)
class Chute : public Oscillateur
{
public:
  //! Constructeur de Chute.
  Chute(double const& m, SupportADessin* vue) : Oscillateur({0,1}, {1,2}, {0,1}, {0,1}, vue), _m(m) {};

  //! Méthode retournant simplement le vecteur g.
  virtual Vecteur f(double t) override;

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

  virtual void settodefault() override { if (_m <= 0) _m = 1.0;}
};

#endif // H_CHUTE
