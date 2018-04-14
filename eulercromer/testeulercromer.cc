#include "eulercromer.h"
#include "../oscillateur/oscillateur.h"
#include "../vecteur/vecteur.h"
using namespace std;

/* Correctif du 29.03.18
 * La classe Chute ne fonctionne PLUS depuis que Oscillateur est un
 * dessinable. Donc ce test n'est plus fonctionnel.
 **/


/*!
 * Classe d'exemple définit dans ce fichier test uniquement pour deux raisons.
 *    - Ce n'est pas réellement un oscillateur, mais on l'utilise juste pour
 *     savoir si nos implémentations sont fonctionnelles.
 *    - Elle n'a rien à voir avec le projet, donc nous la définissons que ici
 *      pour ne pas avoir plein de code "inutile" éparpillé dans le projet.
 */
class Chute : public Oscillateur
{
public:
  //! Constructeur de Chute.
  Chute(double const& m) : Oscillateur({0,1}, {1,2}, {0,1}, {0,1}), _m(m) {};

  //! Méthode retournant simplement le vecteur g.
  Vecteur f(double t) override{
    return Vecteur({0, -9.81});
  }

private:
  //! Masse de l'objet en chute. Inutilisé.
  double _m;
};

int main(){
  // on initialise le temps et le pas de temps.
  double t(0);
  double dt(0.01);

  // on crée une instance de Chute.
  Chute c(0.127);

  // on initialise un intégrateur EulerCromer
  Eulercromer IEC;

  // on fait évoluer l'instance de Chute un certain nombre de fois.
  for(size_t i(0); i < 100; ++i){
    cout << c << endl;
    IEC.evolue(c, dt, t);
  }

  cout << c << endl;

  return 0;
}
