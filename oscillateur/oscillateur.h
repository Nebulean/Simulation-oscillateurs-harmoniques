#ifndef OSCILLATEUR_H
#define OSCILLATEUR_H

#include "../vecteur/vecteur.h"
#include <initializer_list>
#include <iostream>

class Oscillateur{
public:
  // constructeurs
  Oscillateur(std::initializer_list<double> const&, std::initializer_list<double> const&, std::initializer_list<double> const&);
  virtual Vecteur f(double t) = 0; // marquer toute les fonctions substituées à celle-ci en utilisant override.

  // getters
  Vecteur P() const {return _P;}; // pas très optimisé, non ?
  Vecteur Q() const {return _Q;}; // pas très optimisé, non ?

  // manipulateurs
  void setP(Vecteur const&); // utilisé pour l'évolution
  void setQ(Vecteur const&); // utilisé pour l'évolution


private:
  Vecteur _P;
  Vecteur _Q; // dérivée de _P
  Vecteur _O; // origine de l'oscillateur
};

// surcharge externe
std::ostream& operator<<(std::ostream&, Oscillateur const&);

#endif // OSCILLATEUR_H
