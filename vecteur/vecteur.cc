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
