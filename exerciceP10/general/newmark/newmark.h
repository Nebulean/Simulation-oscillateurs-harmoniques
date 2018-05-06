#ifndef H_NEWMARK
#define H_NEWMARK

#include "integrateur.h"
#include "vecteur.h"
#include "oscillateur.h"

/*!
 * Intégrateur de Newmark.
 *
 * Il est plus précis que l'intégrateur d'Euler-Cromer, mais il est plus
 * compliqué à implémenter.
 *
 */
class Newmark : public Integrateur{
public:
  Newmark(double precision = 0.000001) // précision par défaut: 1e-6
   : _precision(precision) {}

  virtual void evolue(Oscillateur& oscillateur, double pas_de_temps, double temps)  override;

private:
  double _precision;
};

#endif // H_NEWMARK
