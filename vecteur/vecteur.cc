#include "vecteur.h"
#include <cmath>
// #include <vector> // Faut-il le noter ?
using namespace std;

void Vecteur::augmente(double x)
{
  _coord.push_back(x);
}

void Vecteur::set_coord(size_t i, double x)
{
  try {
    //on teste si la coordonnée qu'on veut modifier existe bien
    if (i > _coord.size()) {
      throw 3;
    }
    _coord[i] = x;
  }
  catch (int const& err) {
    cerr << "Erreur " << err << ": le vecteur est de dimension inférieure à la coordonnée spécifiée." << endl;
  }
}

void Vecteur::affiche() const
{
  for (size_t i = 0; i < _coord.size(); i++) {
    cout << _coord[i] << " ";
  }
  cout << endl;
}

bool Vecteur::compare(Vecteur const& v) const
{
  if (v._coord.size() != _coord.size()) {
    return false;
  }
  for (size_t i = 0; i < _coord.size(); i++) {
    if (_coord[i] != v._coord[i]) {
      return false;
    }
  }
  return true;
}


/*---* Utilisation *---*
  Soient trois instances de Vecteur: v1, v2 et v3 (qu'importe leur valeurs)
  Pour les additionner, on utilise: v3 = v1.addition(v) pour obtenir le résultat de v1 + v2.
*/
Vecteur Vecteur::addition(Vecteur v) const
{
  try{
    // on teste si les vecteurs ont la même dimension.
    if (v._coord.size() != _coord.size()) {
      throw 2; // erreur 2: les dimensions des deux vecteurs ne sont pas égales.
    }

    // si les deux dimensions sont pareilles, alors on procède à l'addition.
    for (size_t i = 0; i < v._coord.size(); i++) {
      v._coord[i] += _coord[i]; // on ajoute la valeur de a
    }
  }
  catch(int const& err){
    cerr << "Erreur " << err << ": les dimensions des deux vecteurs sont différentes." << endl; // il y a qu'une erreur ici, donc on peut se contenter de ça.
    return *this;
  }

  return v; // si il y a une erreur, alors on retourne v, sans modification. Sinon, ça fait l'addition.
}


// comme l'addition, mais pour la soustraction.
Vecteur Vecteur::soustraction(Vecteur const& v) const
{
  Vecteur result; // la variable de retour
  result = *this; // on y applique les valeurs de l'instance courante.

  try{
    // on teste si les vecteurs ont la même dimension.
    if (v._coord.size() != _coord.size()) {
      throw 2; // erreur 2: les dimensions des deux vecteurs ne sont pas égales.
    }

    // si les deux dimensions sont pareilles, alors on procède à la soustraction.
    for (size_t i = 0; i < v._coord.size(); i++) {
      result._coord[i] -= v._coord[i]; // on ajoute la valeur de a
    }
  }
  catch(int const& err){
    cerr << "Erreur " << err << ": les dimensions des deux vecteurs sont différentes." << endl; // il y a qu'une erreur ici, donc on peut se contenter de ça.
  }

  return result; // si il y a une erreur, alors on retourne l'instance courante. Sinon, ça fait la soustraction.
}

// inverse un vecteur.
Vecteur Vecteur::oppose() const
{
  Vecteur result(*this); // on copie l'instance courante
  for (size_t i = 0; i < _coord.size(); i++) {
    result._coord[i] = -1*result._coord[i]; // on multiplie chaque coordonnée par -1
  }
  return result;
}


// multiplie un vecteur par un scalaire
Vecteur Vecteur::mult(double const& a) const
{
  Vecteur result(*this); // on copie l'instance courante
  for (size_t i = 0; i < _coord.size(); ++i) {
    result._coord[i] = a*result._coord[i]; // on multiplie chaque coordonnée par a
  }
  return result;
}


// applique un produit scalaire entre deux vecteurs.
double Vecteur::prod_scal(Vecteur const& v) const
{
  try {
    // on teste si les vecteurs ont la même dimension.
    if (v._coord.size() != _coord.size()) {
      throw 2; // erreur 2: les dimensions des deux vecteurs ne sont pas égales.
    }

    double result(0.0); // on initialise la variable du résultat

    for (size_t i = 0; i < _coord.size(); ++i) {
      result += v._coord[i]*_coord[i]; // on ajoute le produit de chaque couple de coordonnées
    }
    return result;
  }
  catch(int const& err){
    cerr << "Erreur " << err << ": les dimensions des deux vecteurs sont différentes." << endl;
    return 2.0; // retourne 2 arbitrairement en cas d'erreur
  }
}


// calcule la norme au carré (sans la racine)
double Vecteur::norme2() const
{
  double result(0);
  for (size_t i = 0; i < _coord.size(); i++) {
    result += _coord[i]*_coord[i];
  }
  return result;
}

// Calcul la norme
double Vecteur::norme() const
{
  return sqrt(norme2());
}

// calcule le produit vectoriel
Vecteur Vecteur::prod_vect(Vecteur const& v) const
{
  try {
    if (_coord.size() != 3 or v._coord.size() != 3) { // on vérifie que les deux vecteurs sont bien de dimension 3
      throw 4;
    }
    Vecteur result;
    result.augmente(_coord[1]*v._coord[2] - _coord[2]*v._coord[1]);
    result.augmente(_coord[2]*v._coord[0] - _coord[0]*v._coord[2]);
    result.augmente(_coord[0]*v._coord[1] - _coord[1]*v._coord[0]);
    return result;
  }
  catch (int const& err){
    cerr << "Erreur " << err << ": au moins un des vecteurs n'est pas de dimension 3." << endl;
    return v; // s'il y a une erreur, on retourne v sans modification
  }
}
