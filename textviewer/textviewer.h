#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include "../supportadessin/supportadessin.h"
#include <iostream>
#include "../pendule/pendule.h"
#include "../ressort/ressort.h"
#include "../systeme/systeme.h"

class TextViewer : public SupportADessin {
public:
  TextViewer(std::ostream&); // constructeur
  virtual ~TextViewer() {}; // destructeur

  // Redéfinition des fonctions dessine() de SupportADessin
  void dessine(Pendule const&) override;
  void dessine(Ressort const&) override;
  void dessine(Systeme const&) override;

private:
  std::ostream& _flot;

};


#endif // TEXTVIEWER_H
