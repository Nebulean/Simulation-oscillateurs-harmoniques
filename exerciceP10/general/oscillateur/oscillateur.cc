#include "oscillateur.h"
#include "vecteur.h"
#include "dessinable.h"
#include "supportadessin.h"
#include <initializer_list>
#include <iostream>
#include "phase.h"

using namespace std;

/*!
 * Peut-être initialisé avec une liste d'initialisation, car Vecteur possède
 * un constructeur qui le permet.
 */
Oscillateur::Oscillateur(Vecteur const& p, Vecteur const& q, Vecteur const& o, Vecteur const& a, SupportADessin* support)
 : Dessinable(support), _P(p), _Q(q), _O(o), _a(a), _phase(nullptr)
{}

void Oscillateur::setP(Vecteur const& p)
{
  _P = p;
}

void Oscillateur::setQ(Vecteur const& q)
{
  _Q = q;
}


void Oscillateur::updatePhase()
{
  if(_phase != nullptr){
    _phase->ajoute_point(*this);
  }
}

// double P(size_t i) const {
//   return _P.get_coord(i);
// }
//
// double Q(size_t i) const {
//   return _Q.get_coord(i);
// }
//
// double O(size_t i) const {
//   return _O.get_coord(i);
// }
//
// double a(size_t i) const {
//   return _a.get_coord(i);
// }
