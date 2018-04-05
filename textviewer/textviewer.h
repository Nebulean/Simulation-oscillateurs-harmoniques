#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include "supportadessin.h"
#include <iostream>

class Pendule;
class Ressort;
class Systeme;

class TextViewer : public SupportADessin {
public:
  Textviewer(std::ostream&);
  virtual ~TextViewer() {};

  void dessine(Pendule const&) override;
  void dessine(Ressort const&) override;
  void dessine(Systeme const&) override;

private:
  std::ostream& _flot;

};


#endif // TEXTVIEWER_H
