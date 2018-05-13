#include "rungekutta.h"
#include "vecteur.h"
#include "oscillateur.h"
using namespace std;

/*!
 * Implémentation de la méthode d'évolution de l'intégrateur de Runge-Kutta à
 * l'ordre 4.
 *
 * Dans cette implémentation, nous avons appellés k' par l pour simplifier la
 * notation. Sinon, l'implémentation suit la méthode donnée dans le complément
 * mathématique.
 */
void RungeKutta::evolue(Oscillateur& osc, double dt, double t)
{
  // on initialise tous les vecteurs dont on a besoin.
  Vecteur k1, k2, k3, k4, l1, l2, l3, l4;
  // on garde également des valeurs initiales pour P, Q et pour le temps T(n-1).
  Vecteur p(osc.P());
  Vecteur q(osc.Q());

  // on leur donne une valeur
  k1 = q; // k1 = Q(n-1)
  l1 = osc.f(t); // l1 = f(t(n-1))
  k2 = q + dt/2.0 * l1; // k2 = Q(n-1) + dt/2 * l1
  l2 = osc.f(t + dt/2.0, p + dt/2.0 * k1, k2); // // f(T(n-1) + dt/2, P(n-1) + dt/2 * k1, Q(n-1) + dt/2 * l1)
  k3 = q + dt/2 * l2; // Q(n-1) + dt/2 * l2
  l3 = osc.f(t + dt/2.0, p + dt/2.0 * k2, k3); // f(T(n-1) + dt/2, P(n-1) + dt/2 * k2, Q(n-1) + dt/2 * l2)
  k4 = q + dt*l3; // Q(n-1) + dt * l3
  l4 = osc.f(t + dt, p + dt * k3, k4); // f(T(n), P(n-1) + dt * k3, Q(n-1) + dt * l3)

  // on calcul le nouveau P.
  osc.setP( osc.P() + dt/6 * (k1 + 2*k2 + 2*k3 + k4) );
  // on calcul le nouveau Q.
  osc.setQ( osc.Q() + dt/6 * (l1 + 2*l2 + 2*l3 + l4) );
}
