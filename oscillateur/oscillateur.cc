#include "oscillateur.h"
#include "../vecteur/vecteur.h"
#include <initializer_list>
#include <iostream>

using namespace std;

// ============== CONSTRUCTEURS ===============
Oscillateur::Oscillateur(initializer_list<double> const& p, initializer_list<double> const& q, initializer_list<double> const& o)
 : _P(p), _Q(q), _O(o)
{}


// ========== SURCHARGES D'OPERATEURS =========
ostream& operator<<(ostream& out, Oscillateur const& osci)
{
  out << "*** Oscillateur ***" << endl;
  out << osci.P() << " # parametre" << endl;
  out << osci.Q() << " # vitesse" << endl;

  return out;
}


// ============== MANIPULATEURS ===============
void Oscillateur::setP(Vecteur const& p) // utilisé pour l'évolution
{
  _P = p;
}
void Oscillateur::setQ(Vecteur const& q) // utilisé pour l'évolution
{
  _Q = q;
}
