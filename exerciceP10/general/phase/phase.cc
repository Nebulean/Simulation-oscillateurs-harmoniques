#include "phase.h"
#include "oscillateur.h"
#include <array>
#include <cmath> // pour abs

using namespace std;

Phase::Phase(SupportADessin* support)
 : Dessinable(support), _max(2.0)
{}


void Phase::ajoute_point(Oscillateur const& osc)
{
  // array<double, 2> tmp;
  // tmp[0] = osc.P(0);
  // tmp[1] = osc.Q(0);
  // _pts.push_front(tmp);
  _pts.push_front({osc.P(0), osc.Q(0)});
  if (abs(osc.P(0)) > _max) _max = abs(osc.P(0));
  if (abs(osc.Q(0)) > _max) _max = abs(osc.Q(0));
}


void Phase::affiche(ostream& out) const
{
  out << "L'ensemble des points actuels de l'espace des phases" << endl;
  for(auto const& point : _pts){
    out << point[0] << " " << point[1] << endl;
  }
}
