#include "textviewer.h"
#include "../pendule/pendule.h"
#include "../ressort/ressort.h"
#include "../systeme/systeme.h"
#include <iostream>
using namespace std;

// constructeur de TextViewer
TextViewer::TextViewer(ostream& flot) : _flot(flot)
{}

// dessine les pendules
void TextViewer::dessine(Pendule const& pendule) {
  _flot << "*** Pendule ***" << endl;
  _flot << pendule << endl;
}

// dessine les ressorts
void TextViewer::dessine(Ressort const& ressort) {
  _flot << "*** Ressort ***" << endl;
  _flot << ressort << endl;
}

// dessine les systèmes
void TextViewer::dessine(Systeme const& syst) {
  _flot << "***** Systeme *****" << endl;
  syst.affiche();
  cout << "t = " << syst.temps() << endl << endl;
}
