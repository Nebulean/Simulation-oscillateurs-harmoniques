#include "oscillateur.h"
#include "../vecteur/vecteur.h"
#include <initializer_list>
#include <iostream>

using namespace std;

// ============== CONSTRUCTEURS ===============
Oscillateur::Oscillateur(initializer_list<double> const& p, initializer_list<double> const& q)
 : _P(p), _Q(q)
{}


// ========== SURCHARGES D'OPERATEURS =========
ostream& operator<<(ostream& out, Oscillateur const& osci)
{
  out << "--- Oscillateur" << endl;
  out << "- P: " << osci.P() << endl;
  out << "- Q: " << osci.Q() << endl;

  return out;
}
