#include "vecteur.h"
// #include <vector> // Faut-il le notter ?
using namespace std;

void Vecteur::augmente(double x)
{
  _coord.push_back(x);
}

void Vecteur::set_coord(size_t i, double x)
{
  _coord[i] = x;
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
      if (v._coord.size() != _coord.size()) {
        throw 2; // erreur 2: les dimensions des deux vecteurs ne sont pas égales.
      }
  }
  catch(int const& err){
    cerr << "Erreur " << err << ": la dimension des deux vecteurs sont différentes." << endl; // il y a qu'une erreur ici, donc on peut se contenter de ça.
    return v; // si il y a une erreur, alors on retourne v, sans modification.
  }
  //
  for (size_t i = 0; i < v._coord.size(); i++) {
    v._coord[i] += _coord[i]; // on ajoute la valeur de a
  }
  return v;
}
