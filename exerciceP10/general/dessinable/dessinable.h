#ifndef H_DESSINABLE
#define H_DESSINABLE

#include "supportadessin.h"
#include <iostream>


class SupportADessin;

/*!
 * Classe regroupant tous les éléments requis pour dessiner un objet.
 */
class Dessinable{
public:
  //! constructeur de Dessinable
  Dessinable(SupportADessin* support);

  //! Destructeur virtuel vide
  virtual ~Dessinable() {};

  /*!
   * Méthode virtuelle pure qui doit être substituée dans CHAQUE objet
   * dessinable.
   * Elle est pure, pour:
   *    - forcer la substitution dans les sous-classes
   *    - on ne peut pas la définir ici, pour des raisons propres à c++.
   */
  virtual void dessine() = 0; //!< Méthode de dessin des objets.

  //! Méthode d'affichage d'instances dessinables pour Textviewer. Utilisé par operator<<.
  virtual void affiche(std::ostream& flot_de_sortie) const = 0;

protected:
  //! SupportADessin utilisé par les dessinable. (Texte ou OpenGL dans notre cas)
  SupportADessin* _support;

};

//! Surcharge de l'opérateur d'affichage.
std::ostream& operator<<(std::ostream& flot_de_sortie, Dessinable const& objet_a_afficher);

#endif // H_DESSINABLE
