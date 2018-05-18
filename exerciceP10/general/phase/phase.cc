#include "phase.h"
#include "oscillateur.h"
#include <utility>

using namespace std;

Phase::Phase(SupportADessin* support)
 : Dessinable(support)
{}

void Phase::affiche(std::ostream& out) const {
 out << "Espace des phases" << endl;
}


void Phase::ajoute_point(Oscillateur const& osc)
{
  _pts.push_front();
}
