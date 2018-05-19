#ifndef H_PHASE
#define H_PHASE

#include "dessinable.h"
#include <forward_list> // pour stocker les points.
#include "vecteur.h"
#include <array>
#include "oscillateur.h"

typedef std::forward_list<std::array<double, 2>> ListePoints;

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

  //! Ajouter le point actuel de l'oscilateur à la collection de positions.
  void ajoute_point(Oscillateur const& osc);

  //! Accesseur pour la liste de points
  ListePoints pts() const {return _pts;}

private:
  //! Stocke les points de l'espace de phase.
  /*! Liste chaînée sur une pair de double. Stocke tous les points de l'espace
   * de phase d'un oscillateur particulier.
   */
  ListePoints _pts;
};

#endif // H_PHASE
