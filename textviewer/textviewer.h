#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include "../supportadessin/supportadessin.h"
#include <iostream>
#include "../pendule/pendule.h"
#include "../ressort/ressort.h"
#include "../systeme/systeme.h"

class TextViewer : public SupportADessin {
public:
  // constructeur de TextViewer
  TextViewer(std::ostream& flot_de_sortie);

  // destructeur de TextViewer
  virtual ~TextViewer() {};

  // substitution des fonctions dessine() de SupportADessin
  void dessine(Pendule const& pendule_a_dessiner) override;
  void dessine(Ressort const& ressort_a_dessiner) override;
  void dessine(Systeme const& systeme_a_dessiner) override;

private:
  // _flot utilisé pour l'affichage dans TextViewer.
  std::ostream& _flot;

};

#endif // TEXTVIEWER_H
