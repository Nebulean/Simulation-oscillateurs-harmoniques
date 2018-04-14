#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>
#include <initializer_list>

class Vecteur{
public:
  //=================== CONSTRUCTEURS
  Vecteur() = default; // constructeur par défaut, utile si on veux créer un vecteur complétement vide. Ne contient aucun code.
  explicit Vecteur(size_t dimension); // constructeur de vecteur vide, de dimension donnée en paramètre. Explicite est utilisé pour éviter les écriture du type 5 * v.
  Vecteur(double x, double y, double z); // constructeur de vecteur en 3 dimensions
  // Vecteur(std::vector<double> const&); // constructeur de vecteur à partir de la liste donnée en paramètre
  Vecteur(std::initializer_list<double> const& coordonnees); // constructeur à partir d'une initializer_list

  //=================== SURCHARGES D'OPERATEUR INTERNES
  Vecteur& operator+=(Vecteur const& operande2);
  Vecteur& operator-=(Vecteur const& operande2);
  bool operator==(Vecteur const& vecteur_auquel_comparer) const;
  Vecteur& operator*=(double const& operande2); // v*=a <=> v.operator*(a)
  Vecteur& operator^=(Vecteur const& operande2);


  void augmente(double coordonnee); // augmente la dimension du vecteur courant en y ajoutant une coordonnée
  double get_coord(size_t position_de_la_coordonnee) const;
  // void affiche() const; // affiche le vecteur courant
  // bool compare(Vecteur const&) const; // compare deux vecteurs

  // Vecteur addition(Vecteur) const; // additionne deux vecteurs
  // Vecteur soustraction(Vecteur const&) const; // soustrait deux vecteurs
  // Vecteur oppose() const; // inverse un vecteur (-coordonnées)
  // Vecteur mult(double const&) const; // multiplie un vecteur par un scalaire
  double prod_scal(Vecteur const& operande2) const; // produit scalaire entre deux vecteurs
  double norme2() const; // calcule le carré de la norme
  double norme() const; // calcule la norme
  // Vecteur prod_vect(Vecteur const&) const; // produit vectoriel entre deux vecteurs

  size_t dim() const; // Méthode renvoyant la taille de _coord, c'est un raccourci qui rend le code plus lisible.

private:
  std::vector<double> _coord; // coordonnées du vecteurs
  void dimCheck(Vecteur const& vecteur2) const; // méthode qui lance une exception en cas de dimension différentes.
  void set_coord(size_t position, double valeur); // applique une valeur à une coordonnée
};


//===================SURCHARGES D'OPERATEUR EXTERNES
std::ostream& operator<<(std::ostream& flot_de_sortie, Vecteur const& veceur_a_afficher);
const Vecteur operator+(Vecteur operande1, Vecteur const& operande2);
const Vecteur operator-(Vecteur operande1, Vecteur const& operande2);
const Vecteur operator-(Vecteur const& vecteur); // surcharge de l'opérateur "opposé"
const Vecteur operator*(double const& scalaire, Vecteur vecteur_a_multiplier); // a*v <=> operator*(a,v)
const Vecteur operator*(Vecteur const& vecteur_a_multiplier, double const& scalaire); // v*a <=> operator*(v,a)
double operator*(Vecteur const& operande1, Vecteur const& operande2);
bool operator!=(Vecteur const& operande1, Vecteur const& operande2);
const Vecteur operator^(Vecteur operande1, Vecteur const& operande2);
// Vecteur& operator*=()
// a*v = operator(a, v)
// v*a = v.operator(a)

#endif // VECTEUR_H
