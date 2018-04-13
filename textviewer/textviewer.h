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
  TextViewer(std::ostream&);

  // destructeur de TextViewer
  virtual ~TextViewer() {};

  // substitution des fonctions dessine() de SupportADessin
  void dessine(Pendule const&) override;
  void dessine(Ressort const&) override;
  void dessine(Systeme const&) override;

private:
  // _flot utilisé pour l'affichage dans TextViewer.
  std::ostream& _flot;

};

#endif // TEXTVIEWER_H
