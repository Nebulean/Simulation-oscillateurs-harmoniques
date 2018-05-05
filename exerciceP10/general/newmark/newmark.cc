#include "newmark.h"
using namespace std;

void Newmark::evolue(Oscillateur& osc, double dt, double t)
{
  // initialisation des éléments utilisés (mais sans valeur pour le moment)
  Vecteur q;
  Vecteur r;
  // Vecteur s;
  Vecteur oldP( osc.P() );
  Vecteur oldQ( osc.Q() );
  Vecteur s( osc.f(t) );
  // initialisation
  // q = osc.P();
  // r = osc.Q();
  // Vecteur P(osc.P());
  // Vecteur Q(osc.Q());
  // s = osc.f(t);

  do {
    q = osc.P();

    r = osc.f(t);

    osc.setQ( oldQ + (dt/2)*(r + s) ); // Q(n) = Q(n-1) + dt/2 * (r + s)

    osc.setP( oldP +  dt * oldQ + ((dt*dt)/3)*(1/2 * r + s) ); // P(n) = P(n-1) + dt * Q(n-1) + (dt^2)/3 * (1/2*r + s)

    // cout << "précision: " << (osc.P() - q).norme() << endl;
  } while((osc.P() - q).norme() >= _precision); // on utilise la norme au carré car faire une multiplication est moins demandant en ressources que la racine.
}
