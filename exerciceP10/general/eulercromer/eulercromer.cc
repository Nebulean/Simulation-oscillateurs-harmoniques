#include "eulercromer.h"
#include "oscillateur.h"
using namespace std;


/*!
 * Méthode qui fait évoluer les oscillateurs.
 *
 * L'intégration d'Euler-Cromer est définie de cette manière.
 *
 * Q(T(n)) = Q(T(n-1)) + dt*f(P(T(n-1)))
 * P(T(n)) = P(T(n-1)) + dt*Q(T(n))
 *
 * avec T(n) = T(0) + n*dt et f la méthode d'évolution propre à chaque
 * oscillateur.
 *
 * Cette méthode reprend donc cette définition telle quelle.
 */
void Eulercromer::evolue(Oscillateur& osc, double dt, double t)
{
  osc.setQ( osc.Q() + dt * osc.f(t) ); // Q(T(n)) = Q(T(n-1)) + dt*f(P(T(n-1)))
  osc.setP( osc.P() + dt * osc.Q() ); // P(T(n)) = P(T(n-1)) + dt*Q(T(n))
}
