#ifndef H_EULERCROMER
#define H_EULERCROMER

#include "../integrateur/integrateur.h"
#include "../oscillateur/oscillateur.h"

class Eulercromer : public Integrateur {
public:
  /* le constructeur et destructeur par défaut est suffisent, vu que l'on a
   * rien à initialiser.
   */

  // méthode qui fait évoluer l'oscillateur donné en argument.
  void evolue(Oscillateur& oscillateur, double pas_de_temps, double temps) override;
};

#endif // H_EULERCROMER
