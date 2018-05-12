#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include "supportadessin.h"
#include <iostream>
#include "pendule.h"
#include "ressort.h"
#include "systeme.h"
#include "torsion.h"
#include "chute.h"
#include "chariot.h"

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

  //! Dessine en version texte un Torsion.
  void dessine(Torsion const& torsion_a_dessiner) override;

  //! Dessine en version texte un Chute.
  void dessine(Chute const& chute_a_dessiner) override;

  //! Dessine en version texte un Chariot
  void dessine(Chariot const& chariot_a_dessiner) override;

private:
  //! flot de sortie, utilisé pour l'affichage dans TextViewer.
  std::ostream& _flot;

};

#endif // TEXTVIEWER_H
