#include "textviewer.h"
#include "pendule.h"
#include "ressort.h"
#include "systeme.h"
#include "chariot.h"
#include "penduledouble.h"
#include "penduleressort.h"
#include <iostream>
using namespace std;

// constructeur de TextViewer
TextViewer::TextViewer(ostream& flot) : _flot(flot)
{}

// dessine les pendules
void TextViewer::dessine(Pendule const& pendule) {
  _flot << pendule << endl;
}

// dessine les ressorts
void TextViewer::dessine(Ressort const& ressort) {
  _flot << ressort << endl;
}

// dessine les systèmes
void TextViewer::dessine(Systeme const& syst) {
  _flot << syst;
  cout << "t = " << syst.temps() << endl << endl;
}

void TextViewer::dessine(Torsion const& torsion) {
  _flot << torsion << endl;
}

void TextViewer::dessine(Chute const& chute) {
  _flot << chute << endl;
}

void TextViewer::dessine(Chariot const& chariot) {
  _flot << chariot << endl;
}

void TextViewer::dessine(PenduleDouble const& penduledouble) {
  _flot << penduledouble << endl;
}

void TextViewer::dessine(PenduleRessort const& penduleressort) {
  _flot << penduleressort << endl;
}

void TextViewer::dessine(DeuxRessorts const& deuxressorts) {
  _flot << deuxressorts << endl;
}
