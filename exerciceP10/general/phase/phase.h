#ifndef H_PHASE
#define H_PHASE

#include "dessinable.h"
#include <forward_list> // pour stocker les points.
// #include <utility> // utilisé pour pair.
#include "vecteur.h"

/*!
 * Classe décrivant l'espace des phases
 */
class Phase : public Dessinable {
public:
  //! Constructeur de phase
  Phase(SupportADessin* support);

  //! Méthode de dessin qui DOIT être implémenté.
  virtual void dessine() override
  { _support->dessine(*this); }

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot_de_sortie) const override;

  //! Permet d'ajouter le point actuel de l'oscilateur
  void ajoute_point(Oscillateur const& osc);

private:
  //! Stocke les points de l'espace de phase.
  /*! Liste chaînée sur une pair de vecteurs. Stocke tous les points de l'espace
   * de phase d'un oscillateur particulier.
   */
  std::forward_list<std::vector<Vecteur>> _pts;
};

#endif // H_PHASE
