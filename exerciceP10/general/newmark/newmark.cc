#include "newmark.h"
using namespace std;

void Newmark::evolue(Oscillateur& osc, double dt, double t)
{
  // initialisation des éléments utilisés (mais sans valeur pour le moment)
  Vecteur q;
  Vecteur r;

  const Vecteur oldP( osc.P() );
  const Vecteur oldQ( osc.Q() );
  const Vecteur s( osc.f(t) );

  do {
    q = osc.P();

    r = osc.f(t);

    osc.setQ( oldQ + (dt/2.0)*(r + s) ); // Q(n) = Q(n-1) + dt/2 * (r + s)

    osc.setP( oldP +  dt * oldQ + ((dt*dt)/3.0)*(1.0/2.0 * r + s) ); // P(n) = P(n-1) + dt * Q(n-1) + (dt^2)/3 * (1/2*r + s)

    // cout << "précision: " << (osc.P() - q).norme() << endl;
  } while((osc.P() - q).norme() >= _precision); // on utilise la norme au carré car faire une multiplication est moins demandant en ressources que la racine.

  // met (potentiellement à jour l'espace des phases.)
  osc.updatePhase();
}
