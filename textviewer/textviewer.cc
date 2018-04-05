#include "textviewer.h"
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
  _flot << "*** Systeme ***" << endl;
  for (auto osc : syst.oscillateurs()) {
    dessine(*osc);
  };
}

// pour tester
void TextViewer::dessine(Oscillateur const& osci) {
  _flot << "wow" << endl;
}
