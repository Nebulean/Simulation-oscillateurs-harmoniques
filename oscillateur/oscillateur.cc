#include "oscillateur.h"
#include "../vecteur/vecteur.h"
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"
#include <initializer_list>
#include <iostream>

using namespace std;

// ============== CONSTRUCTEURS ===============
Oscillateur::Oscillateur(initializer_list<double> const& p, initializer_list<double> const& q, initializer_list<double> const& o, initializer_list<double> const& a, SupportADessin* support)
 : Dessinable(support), _P(p), _Q(q), _O(o), _a(a)
{}


// ========== SURCHARGES D'OPERATEURS =========
ostream& operator<<(ostream& out, Oscillateur const& osci)
{
  // on affiche simplement les informations de l'oscillateur.
  // out << "*** Oscillateur ***" << endl; // plus besoin maintenant qu'on a dessine()
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
