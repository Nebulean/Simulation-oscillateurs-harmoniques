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

// dessine les torsions
void TextViewer::dessine(Torsion const& torsion) {
  _flot << torsion << endl;
}

// dessine les chutes
void TextViewer::dessine(Chute const& chute) {
  _flot << chute << endl;
}

// dessine les chariots
void TextViewer::dessine(Chariot const& chariot) {
  _flot << chariot << endl;
}

// dessine les pendules doubles
void TextViewer::dessine(PenduleDouble const& penduledouble) {
  _flot << penduledouble << endl;
}

// dessine les pendules-ressorts
void TextViewer::dessine(PenduleRessort const& penduleressort) {
  _flot << penduleressort << endl;
}

// dessine les espaces de phases
void TextViewer::dessine(Phase const& phase){
  _flot << phase << endl;
}
