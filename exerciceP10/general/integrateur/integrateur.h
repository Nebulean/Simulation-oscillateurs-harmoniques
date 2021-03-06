#ifndef H_INTEGRATEUR
#define H_INTEGRATEUR

#include "oscillateur.h"

/*!
 * Classe de base des Intégrateurs.
 */
class Integrateur{
public:
  /* Le constructeur par défaut est suffisent, car il n'y a
   * rien à initialiser dans cette classe.
   */
   virtual ~Integrateur() {}

  //! Méthode qui fait évoluer l'oscillateur donné en argument.
  /*!
   * Elle est virtuelle pure, car on ne peut pas la définir ici, et ça force la
   * substitution dans les autres intégrateurs.
   */
  virtual void evolue(Oscillateur& oscillateur, double pas_de_temps, double temps) = 0;
};

#endif // H_INTEGRATEUR
