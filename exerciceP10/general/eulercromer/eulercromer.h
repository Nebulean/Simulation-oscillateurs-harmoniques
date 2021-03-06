#ifndef H_EULERCROMER
#define H_EULERCROMER

#include "integrateur.h"
#include "oscillateur.h"

/*!
 * Intégrateur d'Euler-Cromer.
 */
class Eulercromer : public Integrateur {
public:
  /* le constructeur et destructeur par défaut est suffisent, vu que l'on a
   * rien à initialiser.
   */

  //! Méthode qui fait évoluer l'oscillateur donné en argument.
  virtual void evolue(Oscillateur& oscillateur, double pas_de_temps, double temps) override;
};

#endif // H_EULERCROMER
