#ifndef H_EULERCROMER
#define H_EULERCROMER

#include "../integrateur/integrateur.h"
#include "../oscillateur/oscillateur.h"

class Eulercromer : public Integrateur {
public:
  // Eulercromer() {}; // voir constructeur de integrateur

  // méthode qui fait évoluer le stade de l'oscillateur donné en argument.
  void evolue(Oscillateur&, double, double);
};

#endif // H_EULERCROMER
