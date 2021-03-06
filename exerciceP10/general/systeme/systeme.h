#ifndef H_SYSTEME
#define H_SYSTEME

#include <vector>
#include <memory> // pour les unique_ptr
#include "oscillateur.h"
#include <initializer_list>
#include "dessinable.h"
#include "supportadessin.h"
#include <iostream>
#include "integrateur.h"

/*!
 * Système regroupant tous les éléments sur l'écran, et pas que...
 */
class Systeme : public Dessinable{
public:
  /*!
   * Destructeur de systeme. N'est pas forcément utile pour le moment, car nous
   * utilisons des unique_ptr qui se désallouent tout seuls. Cependant, le
   * déclarer ici nous rappelle qu'il faut le modifier au cas où nous utilisons
   * autre chose que des pointeurs intelligents.
   */
  virtual ~Systeme();

  //! Constructeurs de Systeme.
  Systeme(double pas_de_temps, SupportADessin* support, Integrateur* integrateur);

  //! Méthode de dessin qui DOIT être implémenté.
  virtual void dessine() override
  { _support->dessine(*this); }

  //! Accesseur retournant le temps courant.
  double temps() const {return _t;}

  //! Manipulateur du pas de temps
  void setdt(double nouveau_pas_de_temps);

  //! Manipulateur d'intégrateur, utilisé pour le changement d'intégrateur pendant l'execution.
  void changeIntegrateur(Integrateur* integrateur_a_appliquer);

  //! Change la liaison à un espace des phases d'un oscillateur.
  void setPhase(Phase* phase_a_lier, size_t oscillateur_a_appliquer);

  //! Utilise l'intégrateur pour faire évoluer le système d'un pas de temps dt
  void evolue();

  //! Affichage graphique du Systeme.
  void affiche() const;

  //! Accesseur retournant le nombre d'oscillateurs actuellement dans le système.
  size_t sizeOsc() const { return _oscillateurs.size(); }

  //! Surchage de l'opérateur d'auto-affectation pour l'addition, qui permet d'ajouter un oscillateur au système.
  Systeme& operator+=(Oscillateur const& nouvel);

private:
  //! Collection hétérogène d'Oscillateur.
  /*!
   * Nous utilisons des unique_ptr pour éviter un grand nombre de problèmes
   * liés aux pointeurs.
   *
   * Attention: est vide lors de l'initialisation.
   */
  std::vector<std::unique_ptr<Oscillateur>> _oscillateurs;

  //! Pas de temps utilisé pour la simulation.
  double _dt;

  //! Temps courant.
  /*!
   * Utilisé par les oscillateurs, il est utilisé comme le temps courant du
   * système.
   */
  double _t;

  //! Integrateur servant à faire évoluer le système d'un pas de temps.
  Integrateur* _integr;

  // Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& out) const override;
};

#endif // H_SYSTEME
