#include "textviewer.h"
#include "../pendule/pendule.h"
#include "../ressort/ressort.h"
#include "../systeme/systeme.h"
#include <iostream>
using namespace std;

TextViewer::TextViewer(ostream& flot) : _flot(flot)
{}

void TextViewer::dessine(Pendule const& pendule) {
  _flot << "*** Pendule ***" << endl;
  _flot << pendule << endl;
}

void TextViewer::dessine(Ressort const& ressort) {
  _flot << "*** Ressort ***" << endl;
  _flot << ressort << endl;
}

void TextViewer::dessine(Systeme const& syst) {
  _flot << "***** Systeme *****" << endl;
  syst.affiche();
  cout << "t = " << syst.temps() << endl << endl;

  // for(auto const& osc : syst.oscillateurs()){
  //   // _flot << *osc << endl;
  //   osc->dessine();
  // }
}
