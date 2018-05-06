#include "contenu.h"

// ======================================================================
void Contenu::evolue(double dt)
{
  constexpr double omega(100.0);
  angle += omega * dt;
}
