#include "systeme.h"
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"
#include "../oscillateur/oscillateur.h"
#include "../integrateur/integrateur.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

Systeme::~Systeme()
{}

Systeme::Systeme(double dt, double t, SupportADessin* support, Integrateur* integr)
 : Dessinable(support), _dt(dt), _t(t), _integr(integr)
{}

// Affiche l'ensemble des oscillateurs se trouvant dans la collection hétérogène.
void Systeme::affiche(ostream& out) const {
  out << "***** Systeme *****" << endl;
  for (auto const& osc : _oscillateurs) {
    out << *osc << endl;
  };
}


/*!
 * Si l'adresse pointée par le pointeur donné en paramètre existe, alors ce
 * pointeur est ajouté à la collection hétérogène d'Oscillateur.
 */
void Systeme::ajoute(Oscillateur* osc) {
  if (osc != nullptr){ // on vérifie que le pointeur pointe vers quelque chose
    _oscillateurs.push_back(unique_ptr<Oscillateur>(osc));
  };
}

/*!
 * Fait évoluer tous les Oscillateur de la collection hétérogène d'un pas de
 * temps dt.
 */
void Systeme::evolue() {
  for (auto& osc : _oscillateurs) {
    _integr->evolue(*osc, _dt, _t);
  };
  _t += _dt;
}
