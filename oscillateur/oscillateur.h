#ifndef OSCILLATEUR_H
#define OSCILLATEUR_H

#include "../vecteur/vecteur.h"
#include <initializer_list>
#include <iostream>

class Oscillateur{
public:
  // constructeurs
  Oscillateur(std::initializer_list<double> const&, std::initializer_list<double> const&);
  void evolution(Vecteur& p, Vecteur& q, double const& t); // A REDEFINIR

  // accesseurs
  Vecteur P() const {return _P;}; // pas très optimisé, non ?
  Vecteur Q() const {return _Q;}; // pas très optimisé, non ?


private:
  Vecteur _P;
  Vecteur _Q; // dérivée de _P
};

// surcharge externe
std::ostream& operator<<(std::ostream&, Oscillateur const&);

#endif // OSCILLATEUR_H
