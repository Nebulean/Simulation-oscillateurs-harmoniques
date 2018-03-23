#include "eulercromer.h"
using namespace std;


/* On a les calculs suivants à effectuer.
 * Q(T(n)) = Q(T(n-1)) + dt*f(P(T(n-1)))
 * P(T(n)) = P(T(n-1)) + dt*Q(T(n))
 * avec T(n) = T(0) + n*dt et f === evolution
 */

void Eulercromer::evolue(Oscillateur& osc, double dt, double t)
{
  // Vecteur v({0,-9.81});
  osc.setQ( osc.Q() + dt * osc.f(t) ); // Q(T(n)) = Q(T(n-1)) + dt*f(P(T(n-1)))
  osc.setP( osc.P() + dt * osc.Q() ); // P(T(n)) = P(T(n-1)) + dt*Q(T(n))
}
