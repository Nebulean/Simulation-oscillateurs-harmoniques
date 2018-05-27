#include "systeme.h"
#include "dessinable.h"
#include "supportadessin.h"
#include "oscillateur.h"
#include "integrateur.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

Systeme::~Systeme()
{}

Systeme::Systeme(double dt, SupportADessin* support, Integrateur* integr)
 : Dessinable(support), _dt(dt), _t(0), _integr(integr)
{}


/*!
 * Afficheur du Systeme en mode graphique. Utilisé par OpenGL.
 */
void Systeme::affiche() const {
  for (auto const& osc : _oscillateurs) {
    osc->dessine();
  }
}

// Affiche l'ensemble des oscillateurs se trouvant dans la collection hétérogène.
void Systeme::affiche(ostream& out) const {
  out << "***** Systeme *****" << endl;
  for (auto const& osc : _oscillateurs) {
    out << *osc << endl;
  };
  out << "Temps: " << _t << endl;
}

// change l'intégrateur.
void Systeme::changeIntegrateur(Integrateur* intgr){
  _integr = intgr;
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


/*!
 * Manipulateur du pas de temps.
 *
 * Utilisé pour la synchronisation entre le dt de système et le dt de Qt.
 */
void Systeme::setdt(double dt)
{
  _dt = dt;
}

Systeme& Systeme::operator+=(Oscillateur const& o){
  _oscillateurs.push_back(o.copie());
  return *this;
}
