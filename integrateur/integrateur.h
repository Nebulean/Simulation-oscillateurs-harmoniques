#ifndef H_INTEGRATEUR
#define H_INTEGRATEUR

#include "../oscillateur/oscillateur.h"

class Integrateur{
public:
  /* Le constructeur et le destructeur par défaut sont suffisent, car il n'y a
   * rien à initialiser dans cette classe.
   */

  /* Méthode qui fait évoluer l'oscillateur donné en argument.
   * Elle est virtuelle pure, car on ne peut pas la définir ici, et ça force la
   * substitution dans les autres intégrateurs.
   */
  virtual void evolue(Oscillateur&, double, double) = 0;
};

#endif // H_INTEGRATEUR
