#ifndef H_RUNGEKUTTA
#define H_RUNGEKUTTA
#include "integrateur.h"
#include "oscillateur.h"

/*!
 * Intégrateur de Runge-Kutta à l'ordre 4.
 *
 * Suit l'implémentation du complément mathématique.
 */
class RungeKutta : public Integrateur{
public:
  virtual void evolue(Oscillateur& oscillateur, double pas_de_temps, double temps)  override;
};

#endif // H_RUNGEKUTTA
