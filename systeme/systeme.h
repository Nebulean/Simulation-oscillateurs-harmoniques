#ifndef H_SYSTEME
#define H_SYSTEME

#include <vector>
#include <memory> // pour les unique_ptr
#include "../oscillateur/oscillateur.h"
#include <initializer_list>
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"

class Systeme : public Dessinable{
public:
  /* Destructeur de systeme. N'est pas forcément utile pour le moment, car nous
   * utilisons des unique_ptr qui se désallouent tout seuls. Cependant, le
   * déclarer ici nous rappelle qu'il faut le modifier au cas où nous utilisons
   * autre chose que des pointeurs intelligents.
   */
  virtual ~Systeme();

  // constructeurs
  Systeme(double, double, std::initializer_list<unique_ptr<Oscillateur>>, SupportADessin*);

  // méthode de dessin qui DOIT être implémenté dans toutes les sous-classes de Dessinable.
  virtual void dessine() override
  { _support->dessine(*this); }

  // méthode(s)
  // méthode ajouter_oscillateur() ?
  // méthode vider_tableau() ?

protected:
  /* Collection hétérogène d'oscillateurs. Nous utilisons des unique_ptr pour
   * pour éviter un grand nombre de problèmes liés aux pointeurs.
   */
  std::vector<unique_ptr<Oscillateur>> _oscillateurs;

  /* Pas de temps. Il est utilisé à travers tout le projet pour savoir à quel
   * point il faut faire évoluer les oscillateurs.
   * Remarque: pour le moment, il s'agit d'une constante. Cependant, si dans
   * le futur nous voulons modifier le pas de temps lors de l'execution, pour
   * changer la vitesse de simulation par exemple, alors il suffit de retirer le
   * const et tout ira bien.
   */
   double const _dt;

   /* Temps courant. Utilisé par les oscillateurs, il est utilisé comme le temps
    * courant du système.
    */
    double _t;
};

#endif // H_SYSTEME
