#ifndef H_INTEGRATEUR
#define H_INTEGRATEUR

#include "../oscillateur/oscillateur.h"

class Integrateur{
public:
  // Integrateur() {}; // l'intégrateur n'a pas d'argument "pas de temps" et "temps courant". C'est la méthode evolue qui les prend en paramètres.
  void evolue(Oscillateur&, double, double);
};

#endif // H_INTEGRATEUR
