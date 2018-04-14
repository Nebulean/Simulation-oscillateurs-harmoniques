#ifndef OSCILLATEUR_H
#define OSCILLATEUR_H

#include "../vecteur/vecteur.h"
// #include <initializer_list>
#include <iostream>
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"

class Oscillateur : public Dessinable{
public:
  // constructeurs d'oscillateur.
  // Oscillateur(std::initializer_list<double> const&, std::initializer_list<double> const&, std::initializer_list<double> const&, std::initializer_list<double> const&, SupportADessin*);
  Oscillateur(Vecteur const& position, Vecteur const& vitesse, Vecteur const& origine, Vecteur const& direction_principale, SupportADessin* support);
  /* méthode d'évolution propre à chaque oscillateur. On ne peut pas la définir
   * ici, et on force la substitution dans les sous-classes. Donc cette méthode
   * est virtuelle pure.
   */
  virtual Vecteur f(double temps) = 0;

  // accesseurs
  Vecteur P() const {return _P;};
  Vecteur Q() const {return _Q;};
  Vecteur a() const {return _a;};

  // manipulateurs
  void setP(Vecteur const& position); // utilisé pour l'évolution
  void setQ(Vecteur const& vitesse); // utilisé pour l'évolution

  /* on prolonge la "pureté" de cette méthode virtuelle.
   * Elle doit être redéfinie ailleurs, dans les sous-classes, donc.
   */
  virtual void dessine() = 0;


private:
  Vecteur _P; // Vecteur des n paramètres du système.
  Vecteur _Q; // Vecteur de dérivée de _P.
  Vecteur _O; // Vecteur de l'origine de l'oscillateur
  Vecteur _a; // Vecteur de direction principale
};

// surcharge externe de l'opérateur d'affichage.
std::ostream& operator<<(std::ostream& flot_de_sortie, Oscillateur const& oscillateur_a_afficher);

#endif // OSCILLATEUR_H
