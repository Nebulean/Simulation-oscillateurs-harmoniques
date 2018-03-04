#include "vecteur.h"
#include <cmath>
// #include <vector> // Faut-il le noter ?
using namespace std;

// ======================================================================
void Vecteur::augmente(double x)
{
  /* Augmente la dimension du vecteur en y ajoutant une case dans le vector _coord.
   * De plus, on affecte dans cette nouvelle case la valeur du paramètre x.
   */
  _coord.push_back(x);
}


// ======================================================================
void Vecteur::set_coord(size_t i, double x)
{
  /* Le but est de changer une coordonnée du vecteur.
   * Ainsi, on affecte la valeur du paramètre x à la case i du vecteur.
   *
   * Probleme: Si la case i de _coord n'existe pas, alors on obtient un segmentation fault.
   */
  if (i >= dim()) { // on teste si la coordonnée qu'on veut modifier existe bien
    throw 3;
  }
  _coord[i] = x;
}


// ======================================================================
void Vecteur::affiche() const
{
  /* Affiche le vecteur courant.
   * Un vecteur (1,2,3) sera simplement affiché 1 2 3.
   */
  for (size_t i = 0; i < dim(); i++) {
    cout << _coord[i] << " ";
  }
  cout << endl;
}


// ======================================================================
bool Vecteur::compare(Vecteur const& v) const
{
  /* Compare deux vecteur.
   * Si ils sont pareils, alors la méthode retourne true, sinon, elle retourne false.
   */
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


// ======================================================================
Vecteur Vecteur::addition(Vecteur v) const
{
  /* Additionne deux vecteurs.
   * Soient trois instances de Vecteur: v1, v2 et v3 (qu'importe leur valeurs)
   * Pour les additionner, on utilise: v3 = v1.addition(v) pour obtenir le résultat de v1 + v2.
   *
   * Probleme: Dans la cas ou les deux vecteurs ont une dimension différente, on lance une exception.
   *           En effet, additionner deux vecteurs de dimensions différentes n'a aucun sens mathématiquement.
   */

  if (v.dim() != dim()) { // on teste si les vecteurs ont la même dimension.
    throw 2; // erreur 2: les dimensions des deux vecteurs ne sont pas égales.
  }

    // si les deux dimensions sont identiques, alors on procède à l'addition.
  for (size_t i = 0; i < v.dim(); i++) {
    v._coord[i] += _coord[i]; // on ajoute la valeur de a
  }
  return v;
}


// ======================================================================
Vecteur Vecteur::soustraction(Vecteur const& v) const
{
  /* Soustrait deux vecteurs.
   * Soit trois instances quelconques de Vecteur: v1, v2, v3.
   * Alors v1 - v2 sera donné par v3 = v1.soustraction(v2)
   *
   * Probleme: Dans la cas ou les deux vecteurs ont une dimension différente, on lance une exception.
   *           En effet, soustraire deux vecteurs de dimensions différentes n'a aucun sens mathématiquement.
   */
  Vecteur result; // la variable de retour
  result = *this; // on y applique les valeurs de l'instance courante.

    // on teste si les vecteurs ont la même dimension.
  if (v.dim() != dim()) {
    throw 2; // erreur 2: les dimensions des deux vecteurs ne sont pas égales.
  }

  // si les deux dimensions sont identiques, alors on procède à la soustraction.
  for (size_t i = 0; i < v.dim(); i++) {
    result._coord[i] -= v._coord[i]; // on ajoute la valeur de a
  }
  return result;
}


// ======================================================================
Vecteur Vecteur::oppose() const
{
  /* Inverse le vecteur, en inversant son sens.
   * Ainsi, l'inverse d'un vecteur v1=(1,2,3) est -v1=(-1,-2,-3).
   */
  Vecteur result(*this); // on copie l'instance courante
  for (size_t i = 0; i < dim(); i++) {
    result._coord[i] = -1*result._coord[i]; // on multiplie chaque coordonnée par -1
  }
  return result;
}


// ======================================================================
Vecteur Vecteur::mult(double const& a) const
{
  /* Multiplication d'un vecteur par un scalaire.
   * Ainsi, pour v1=(1,2,3), on obtient: a*v1=(a*1,a*2,a*3).
   */
  Vecteur result(*this); // on copie l'instance courante
  for (size_t i = 0; i < dim(); ++i) {
    result._coord[i] = a*result._coord[i]; // on multiplie chaque coordonnée par a
  }
  return result;
}


// ======================================================================
double Vecteur::prod_scal(Vecteur const& v) const
{
  /* Applique un produit scalaire entre deux vecteurs.
   * Ainsi, le produit scalaire de deux vecteurs v1=(1,2,3) et v2=(3,2,1) donne:
   * v1*v2 = 1*3 + 2*2 + 3*1 = 10
   *
   * Probleme: Si la dimension des deux vecteurs est différente, alors on lance une exception.
   *           En effet, faire un produit scalaire entre deux vecteurs de dimensions différentes
   *           n'a aucun sens mathématiquement.
   */
  if (v.dim() != dim()) { // on teste si les vecteurs ont la même dimension.
    throw 2; // erreur 2: les dimensions des deux vecteurs ne sont pas égales.
  }

  double result(0.0); // on initialise la variable du résultat

  for (size_t i = 0; i < dim(); ++i) {
    result += v._coord[i]*_coord[i]; // on ajoute le produit de chaque couple de coordonnées
  }
  return result;
}


// ======================================================================
double Vecteur::norme2() const
{
  /* Retourne la norme au carré du vecteur courant.
   * Cette fonction a un interet par rapport à norme(). En effet, elle est beaucoup
   * plus rapide à calculer, car elle ne requiert pas l'utilisation de la racine carré.
   * Dans la mesure du possible, elle doit donc être favorisée à norme().
   */
  double result(0);
  for (size_t i = 0; i < dim(); i++) {
    result += _coord[i]*_coord[i];
  }
  return result;
}


// ======================================================================
double Vecteur::norme() const
{
  /* Retourne la norme du vecteur courant.
   * Cette fonction est plus lente que norme2(), car elle requiert une opération,
   * couteuse, supplémentaire: la racine carrée.
   * Lorsque c'est possible, préférer norme2().
   */
  return sqrt(norme2());
}


// ======================================================================
// calcule le produit vectoriel
Vecteur Vecteur::prod_vect(Vecteur const& v) const
{
  /* Calcul le produit vectoriel de deux vecteurs dans R3.
   *
   * Problèmes:
   *      - Si les vecteurs ne sont pas de dimension 3, alors le produit vectoriel
   *        n'est pas défini. Il faut ainsi signaler une erreur.
   *      - Cette opération est une opération qui requiert des conditions très
   *        particulières. Il faudrait peut-être la dissocier de la classe Vecteur.
   */
  if (dim() != 3 or v.dim() != 3) { // on vérifie que les deux vecteurs sont bien de dimension 3
    throw 4;
  }
  Vecteur result;
  result.augmente(_coord[1]*v._coord[2] - _coord[2]*v._coord[1]);
  result.augmente(_coord[2]*v._coord[0] - _coord[0]*v._coord[2]);
  result.augmente(_coord[0]*v._coord[1] - _coord[1]*v._coord[0]);
  return result;
}

// ======================================================================
size_t Vecteur::dim() const
{
  /* Retourne la dimension du vecteur courant.
   *
   * Il s'agit d'une méthode que l'on utilise pour rendre plus lisible certaines
   * parties du code. En effet, _coord.size() est assez lourd, et peu visible,
   * alors que dim() est assez clair. D'où sa définition.
   */
  return _coord.size();
}
