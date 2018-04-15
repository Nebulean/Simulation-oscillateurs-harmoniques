#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include "../supportadessin/supportadessin.h"
#include <iostream>
#include "../pendule/pendule.h"
#include "../ressort/ressort.h"
#include "../systeme/systeme.h"

/*!
 * Visualisation en mode texte du simulateur.
 */
class TextViewer : public SupportADessin {
public:
  //! Constructeur de TextViewer
  TextViewer(std::ostream& flot_de_sortie);

  //! Destructeur de TextViewer
  virtual ~TextViewer() {};

  // substitution des fonctions dessine() de SupportADessin
  //! Dessine en version texte un Pendule.
  void dessine(Pendule const& pendule_a_dessiner) override;

  //! Dessine en version texte un Ressort.
  void dessine(Ressort const& ressort_a_dessiner) override;

  //! Dessine en version texte un Systeme.
  void dessine(Systeme const& systeme_a_dessiner) override;

private:
  //! flot de sortie, utilisé pour l'affichage dans TextViewer.
  std::ostream& _flot;

};

#endif // TEXTVIEWER_H
