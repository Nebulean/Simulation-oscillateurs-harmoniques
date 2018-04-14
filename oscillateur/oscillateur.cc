#include "oscillateur.h"
#include "../vecteur/vecteur.h"
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"
#include <initializer_list>
#include <iostream>

using namespace std;

/*!
 * Peut-être initialisé avec une liste d'initialisation, car Vecteur possède
 * un constructeur qui le permet.
 */
Oscillateur::Oscillateur(Vecteur const& p, Vecteur const& q, Vecteur const& o, Vecteur const& a, SupportADessin* support)
 : Dessinable(support), _P(p), _Q(q), _O(o), _a(a)
{}


/*!
 * Surcharge de l'opérateur d'affichage.
 */
ostream& operator<<(ostream& out, Oscillateur const& osci)
{
  // on affiche simplement les informations de l'oscillateur.
  out << osci.P() << " # parametre" << endl;
  out << osci.Q() << " # vitesse" << endl;

  return out;
}


void Oscillateur::setP(Vecteur const& p)
{
  _P = p;
}
void Oscillateur::setQ(Vecteur const& q)
{
  _Q = q;
}
