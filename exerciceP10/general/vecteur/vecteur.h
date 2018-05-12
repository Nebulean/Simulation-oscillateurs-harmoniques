#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>
#include <initializer_list>

/*!
 * Classe appliquant les opérations classiques des vecteurs dans Rn.
 *
 * De plus, on y retrouve quelques méthodes appliquées dans R3 uniquement.
 */
class Vecteur{
public:
  //=================== Constructeurs
  Vecteur() = default; //!< Constructeur par défaut, utile si on veux créer un Vecteur complétement vide.
  explicit Vecteur(size_t dimension); //!< Constructeur de Vecteur vide et de dimension donnée en paramètre. Ce constructeur est explicite pour éviter les écriture du type 5 * v.
  Vecteur(double x, double y, double z); //!< Constructeur de Vecteur en 3 dimensions.
  Vecteur(std::vector<double> const&); //!< Constructeur de Vecteur à partir du vector donné en paramètre.
  Vecteur(std::initializer_list<double> const& coordonnees); //!< constructeur de Vecteur à partir d'une liste d'initialisation.

  //=================== Surcharge d'opérateurs internes
  Vecteur& operator+=(Vecteur const& operande2); //!< Operateur d'addition: a += b.
  Vecteur& operator-=(Vecteur const& operande2); //!< Operateur de soustraction: a -= b.
  bool operator==(Vecteur const& vecteur_auquel_comparer) const; //!< Operateur de comparaison: a == b.
  Vecteur& operator*=(double const& operande2); //!< Operateur de multiplication par un scalaire: a *= b.
  Vecteur& operator^=(Vecteur const& operande2); //!< Operateur de produit vectoriel pour vecteur de dimension 3: a ^= b.
  double operator[](size_t position) const; //!< Surcharge de []. Retourne la valeur se trouvant à la position demandée.

  // ================== Méthodes
  void augmente(double coordonnee); //!< Augmente la dimension du Vecteur courant en y ajoutant une coordonnée.
  double get_coord(size_t position_de_la_coordonnee) const; //!< Accesseur de la coordonnée demandée en paramètre.
  double prod_scal(Vecteur const& operande2) const; //!< Produit scalaire entre deux Vecteurs.
  double norme2() const; //!< Calcule le carré de la norme euclidienne. Est moins coûteux en calcul que la norme classique, car elle évite la racine carrée.
  double norme() const; //!< Calcule la norme euclidienne.
  size_t dim() const; //!< Méthode renvoyant la taille de _coord, c'est un raccourci qui rend le code plus lisible.

private:
  std::vector<double> _coord; //!< Coordonnées du Vecteurs.
  void dimCheck(Vecteur const& vecteur2) const; //!< Méthode qui lance une exception en cas de dimension différentes.
  void set_coord(size_t position, double valeur); //!< Applique une valeur à une coordonnée particulière.
};


//===================SURCHARGES D'OPERATEUR EXTERNES
std::ostream& operator<<(std::ostream& flot_de_sortie, Vecteur const& veceur_a_afficher); //!< Surcharge de l'affichage de Vecteur.
const Vecteur operator+(Vecteur operande1, Vecteur const& operande2); //!< Surcharge d'addition vectorielle.
const Vecteur operator-(Vecteur operande1, Vecteur const& operande2); //!< Surcharge de soustraction vectorielle.
const Vecteur operator-(Vecteur const& vecteur); //!< Surcharge de l'opérateur "opposé", qui inverse le Vecteur donné en paramètre.
const Vecteur operator*(double const& scalaire, Vecteur vecteur_a_multiplier); //!< Surcharge de la multiplication à gauche par un scalaire. a*v <=> operator*(a,v)
const Vecteur operator*(Vecteur const& vecteur_a_multiplier, double const& scalaire); //!< Surcharge de la multiplication à droite par un scalaire. v*a <=> operator*(v,a)
double operator*(Vecteur const& operande1, Vecteur const& operande2); //!< Surcharge du produit scalaire standard pour un espace Euclidien.
bool operator!=(Vecteur const& operande1, Vecteur const& operande2); //!< Surcharge de comparaison. Retourne true si les deux vecteurs sont différents.
const Vecteur operator^(Vecteur operande1, Vecteur const& operande2); //!< Surcharge du produit vectoriel pour des vecteurs de dimension 3.

#endif // VECTEUR_H
