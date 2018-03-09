#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>
#include <initializer_list>

class Vecteur{
public:
  //=================== CONSTRUCTEURS
  Vecteur() = default; // constructeur par défaut, utile si on veux créer un vecteur complétement vide. Ne contient aucun code.
  Vecteur(size_t); // constructeur de vecteur vide, de dimension donnée en paramètre
  Vecteur(double, double, double); // constructeur de vecteur en 3 dimensions
  Vecteur(std::vector<double> const&); // constructeur de vecteur à partir de la liste donnée en paramètre
  Vecteur(std::initializer_list<double> const&);

  //=================== SURCHARGES D'OPERATEUR INTERNES
  Vecteur& operator+=(Vecteur const&);
  bool operator==(Vecteur const&) const;
  Vecteur& operator*=(double const&); // v*=a <=> v.operator*(a)


  void augmente(double); // augmente la dimension du vecteur courant
  void set_coord(size_t, double); // applique une valeur à une coordonnée
  double get_coord(size_t) const;
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

  size_t dim() const; // Méthode renvoyant la taille de _coord, c'est un raccourci qui rend le code plus lisible.

private:
  std::vector<double> _coord; // coordonnées du vecteurs
  void dimCheck(Vecteur const&) const; // méthode qui lance une exception en cas de dimension différentes.
};


//===================SURCHARGES D'OPERATEUR EXTERNES
std::ostream& operator<<(std::ostream&, Vecteur const&);
const Vecteur operator+(Vecteur, Vecteur const&);
const Vecteur operator*(double const&, Vecteur); // a*v <=> operator*(a,v)
const Vecteur operator*(Vecteur const&, double const&); // v*a <=> operator*(v,a)
// Vecteur& operator*=()
// a*v = operator(a, v)
// v*a = v.operator(a)

#endif // VECTEUR_H
