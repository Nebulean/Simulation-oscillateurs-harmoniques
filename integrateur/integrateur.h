#ifndef H_INTEGRATEUR
#define H_INTEGRATEUR

#include "../oscillateur/oscillateur.h"

class Integrateur{
public:
  // Integrateur() {}; // l'intégrateur n'a pas d'argument "pas de temps" et "temps courant". C'est la méthode evolue qui les prend en paramètres.
  // méthode qui fait évoluer l'oscillateur donné en argument.
  virtual void evolue(Oscillateur&, double, double) = 0;
};

#endif // H_INTEGRATEUR
