#include "vecteur.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <initializer_list>

using namespace std;


/*!
 * Constructeur créant un vecteur de dimension donnée en paramètre. De plus, ce
 * vecteur est nul.
 */
Vecteur::Vecteur(size_t dim){
  for (size_t i = 0; i < dim; i++) {
    augmente(0);
  }
}


/*!
 * Constructeur d'un vecteur de dimension 3. On affecte les paramètres
 * à ce vecteur directement.
 */
Vecteur::Vecteur(double x, double y, double z){
   augmente(x);
   augmente(y);
   augmente(z);
}

/*!
 * Constructeur d'un vecteur à l'aide d'une liste d'initialisation.
 */
Vecteur::Vecteur(initializer_list<double> const& list) : _coord(list)
{ }



/*!
 * Méthode outil qui permet de vérifier que la dimension des deux vecteur est
 * bien égale. En cas de problèmes, un exception est lancée, qui arrête donc le programme.
 */
void Vecteur::dimCheck(Vecteur const& v) const
{
  if(dim() != v.dim()){
    throw 2; // erreur 2: problème de dimension
  }
}


/*!
 * Augmente la dimension du vecteur en y ajoutant une case dans le vector _coord.
 * De plus, on affecte dans cette nouvelle case la valeur du paramètre x.
 */
void Vecteur::augmente(double x)
{
  _coord.push_back(x);
}


/*!
 * Le but est de changer une coordonnée du vecteur.
 * Ainsi, on affecte la valeur du paramètre x à la case i du vecteur.
 *
 * Si la coordonnée donnée en paramètre n'existe pas, alors l'erreur 3 est
 * soulevée.
 */
void Vecteur::set_coord(size_t i, double x)
{
  if (i >= dim()) { // on teste si la coordonnée qu'on veut modifier existe bien
    throw 3;
  }
  _coord[i] = x;
}


/*!
 * Retourne la norme au carré du vecteur courant.
 *
 * Cette fonction a un interet par rapport à norme(). Elle est beaucoup
 * plus rapide à calculer, car elle ne requiert pas l'utilisation de la racine
 * carré. Dans la mesure du possible, elle doit donc être favorisée à norme().
 */
double Vecteur::norme2() const
{
  double result(0);
  for (size_t i = 0; i < dim(); i++) {
    result += _coord[i]*_coord[i];
  }
  return result;
}


/*!
 * Retourne la norme du vecteur courant.
 *
 * Cette fonction est plus lente que norme2(), car elle requiert une opération,
 * couteuse, supplémentaire: la racine carrée.
 * Lorsque c'est possible, préférer norme2().
 */
double Vecteur::norme() const
{
  return sqrt(norme2());
}


/*!
 * Retourne la dimension du vecteur courant.
 *
 * Il s'agit d'une méthode que l'on utilise pour rendre plus lisible certaines
 * parties du code. En effet, _coord.size() est assez lourd, et peu visible,
 * alors que dim() est assez clair. D'où sa définition.
 *
 * Méthode publique, car on en a besoin pour la surcharge externe.
 */
size_t Vecteur::dim() const
{

  return _coord.size();
}

/*!
 * Accesseur retournant la valeur contenue dans la case i de _coord.
 * Cet accesseur est requis pour les surcharges externes.
 */
double Vecteur::get_coord(size_t i) const
{
  return _coord[i];
}



/*!
 * Operateur du produit scalaire entre deux vecteurs.
 *
 * Nous utilisons prod_scal, car l'écriture utilisant le getter des coordonnées
 * est assez lourd au niveau écriture. Cette version simplifie donc le tout.
 */
double operator*(Vecteur const& v1, Vecteur const& v2)
{
  return v1.prod_scal(v2);
}


/*!
 * Applique un produit scalaire entre deux vecteurs.
 *
 * Par exemple, le produit scalaire de deux vecteurs v1=(1,2,3) et v2=(3,2,1) donne:
 * v1*v2 = 1*3 + 2*2 + 3*1 = 10
 *
 * Probleme: Si la dimension des deux vecteurs est différente, alors on lance une exception.
 *           En effet, faire un produit scalaire entre deux vecteurs de dimensions différentes
 *           n'a aucun sens mathématiquement.
 */
double Vecteur::prod_scal(Vecteur const& v) const
{
  // on teste si les vecteurs ont la même dimension.
  dimCheck(v);

  double result(0.0); // on initialise la variable du résultat

  for (size_t i = 0; i < dim(); ++i) {
    result += v._coord[i]*_coord[i]; // on ajoute le produit de chaque couple de coordonnées
  }
  return result;
}




/*!
 * Opérateur d'auto-affectation pour la multiplication par un scalaire d'un vecteur.
 *
 * Attention: il est utilisé que dans le sens: v *= a avec v un vecteur et a un double.
 */
Vecteur& Vecteur::operator*=(double const& a)
{
   for(auto& val : _coord){
     val *= a;
   }
   return *this;
}



/*!
 * Opérateur pour la multiplication par un scalaire d'un vecteur.
 *
 * Attention: il est utilisé dans le cas: a*v où v est un vecteur et a un double.
 */
const Vecteur operator*(double const& a, Vecteur v)
{
   return v *= a;
}



 /* Opérateur de multiplication pour la multiplication par un scalaire d'un vecteur.
 *
 * Attention: il est utilisé dans le cas: v*a où v est un vecteur et a un double.
 */
const Vecteur operator*(Vecteur const& v, double const& a)
{
   return a * v;
}

/*!
 * Opérateur d'auto-affectation pour l'addition de deux vecteurs.
 */
Vecteur& Vecteur::operator+=(Vecteur const& v)
{
  dimCheck(v);
  for (size_t i = 0; i < dim(); ++i) {
    _coord[i] += v._coord[i];
  };
  return *this;
}

/*!
 * Opérateur d'addition entre deux vecteurs.
 */
const Vecteur operator+(Vecteur v1, Vecteur const& v2)
{
  return v1 += v2;
}


/*!
 * Opérateur d'auto-affectation pour la soustraction de deux vecteurs.
 *
 * On soustrait l'instance courante avec l'argument.
 */
Vecteur& Vecteur::operator-=(Vecteur const& v)
{
  dimCheck(v); // on teste si les vecteurs ont la même dimension
  for (size_t i =0; i < dim(); i++) {
    _coord[i] -= v._coord[i];
  };
  return *this;
}


/*!
 * Opérateur de soustraction entre deux vecteurs.
 */
const Vecteur operator-(Vecteur v1, Vecteur const& v2)
{
  return v1 -= v2;
}


/*!
 * Calcule l'opposé du vecteur
 */
const Vecteur operator-(Vecteur const& v)
{
  return -1*v;
}


/*!
 * Affiche le vecteur courant.
 * Un vecteur (1,2,3) sera simplement affiché 1 2 3.
 */
ostream& operator<<(ostream& output, Vecteur const& v)
{
  for (size_t i = 0; i < v.dim(); i++) {
    output << v.get_coord(i) << " ";
  }

  return output;
}



/* Compare deux vecteur.
 * Si ils sont pareils, alors la méthode retourne true, sinon, elle retourne false.
 */
bool Vecteur::operator==(Vecteur const& v) const
{
  if (v.dim() != dim()) {
    return false;
  }
  for (size_t i = 0; i < dim(); i++) {
    if (_coord[i] != v._coord[i]) {
      return false;
    }
  }
  return true;
}


/*!
 * Compare deux vecteurs.
 * Si ils sont différents, alors la méthode retourne true, sinon, elle retourne false.
 */
bool operator!=(Vecteur const& v1, Vecteur const& v2)
{
  return !(v1 == v2);
}

/*!
 * Opérateur d'auto-affection pour le produit vectoriel.
 */
Vecteur& Vecteur::operator^=(Vecteur const& v)
{
  if (dim() != 3 or v.dim() != 3) { // on vérifie que les deux vecteurs sont bien de dimension 3
    throw 4;
  }
  double x(_coord[1]*v._coord[2] - _coord[2]*v._coord[1]);
  double y(_coord[2]*v._coord[0] - _coord[0]*v._coord[2]);
  double z(_coord[0]*v._coord[1] - _coord[1]*v._coord[0]);

  set_coord(0, x);
  set_coord(1, y);
  set_coord(2, z);
  return *this;
}


/*!
 * Opérateur de produit vectoriel.
 */
const Vecteur operator^(Vecteur v1, Vecteur const& v2)
{
  return v1 ^= v2;
}
