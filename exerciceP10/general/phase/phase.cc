#include "phase.h"
#include "oscillateur.h"
#include <array>

using namespace std;

Phase::Phase(SupportADessin* support)
 : Dessinable(support), _max(2.0)
{}


void Phase::ajoute_point(Oscillateur const& osc)
{
  _pts.push_front({osc.P(0), osc.Q(0)});
  if (osc.P(0) > _max) _max = osc.P(0);
  if (osc.Q(0) > _max) _max = osc.Q(0);
}


void Phase::affiche(ostream& out) const
{
  out << "L'ensemble des points actuels de l'espace des phases" << endl;
  for(auto const& point : _pts){
    out << point[0] << " " << point[1] << endl;
  }
}
