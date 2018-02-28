#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>

class Vecteur{
public:
  void augmente(double); // augmente la dimension du vecteur courant
  void set_coord(size_t, double); // applique une valeur à une coordonnée
  void affiche() const; // affiche le vecteur courant
  bool compare(Vecteur const&) const; // compare deux vecteurs

  Vecteur addition(Vecteur) const; // additionne deux vecteurs
  Vecteur soustraction(Vecteur const&) const; // soustrait deux vecteurs
  Vecteur oppose() const; // inverse un vecteur (-coordonnées)
  Vecteur mult(double const&) const; // multiplie un vecteur par un scalaire
  double prod_scal(Vecteur const&) const; // produit scalaire entre deux vecteurs
  double norme2() const; // calcule le carré de la norme
  double norme() const; // calcule la norme
  Vecteur prod_vect(Vecteur const&) const; // produit vectoriel entre deux vecteurs

  size_t taille() const; // Méthode renvoyant la taille de _coord, c'est un raccourci qui rend le code plus lisible.

private:
  std::vector<double> _coord; // coordonnées du vecteurs
};

#endif // VECTEUR_H
