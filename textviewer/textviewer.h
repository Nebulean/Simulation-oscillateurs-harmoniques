#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include "../supportadessin/supportadessin.h"
#include <iostream>
#include "../pendule/pendule.h"
#include "../ressort/ressort.h"
#include "../systeme/systeme.h"
#include "../oscillateur/oscillateur.h"

// class Pendule;
// class Ressort;
// class Systeme;
// class Oscillateur;

class TextViewer : public SupportADessin {
public:
  Textviewer(std::ostream&); // constructeur
  virtual ~TextViewer() {}; // destructeur

  // Redéfinition des fonctions dessine() de SupportADessin
  void dessine(Pendule const&) override;
  void dessine(Ressort const&) override;
  void dessine(Systeme const&) override;

  // pour tester
  void dessine(Oscillateur const&)  override;
private:
  std::ostream& _flot;

};


#endif // TEXTVIEWER_H
