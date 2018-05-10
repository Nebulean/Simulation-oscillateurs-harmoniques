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
}

// change l'intégrateur.
void Systeme::changeIntegrateur(Integrateur* intgr){
  _integr = intgr;
}


/*!
 * Si l'adresse pointée par le pointeur donné en paramètre existe, alors ce
 * pointeur est ajouté à la collection hétérogène d'Oscillateur.
 */
// void Systeme::ajoute(Oscillateur* osc) {
//   if (osc != nullptr){ // on vérifie que le pointeur pointe vers quelque chose
//     _oscillateurs.push_back(unique_ptr<Oscillateur>(osc));
//   };
// }

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
 *
 */
// void Systeme::ajoute(Oscillateur const& o){
//   _oscillateurs.push_back(o.copie());
// }



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

// Systeme& Systeme::operator+=(initializer_list<Oscillateur> const& liste){
//   for (auto const& osc : liste){
//     _oscillateurs.push_back(osc.copie());
//   }
//   return *this;
// }

// Systeme& Systeme::operator+=(Systeme const& s){
//   for (auto const& osc : s._oscillateurs){
//     _oscillateurs.push_back(osc.copie());
//   }
//   return *this;
// }

// const Systeme operator+(Systeme const& s, Oscillateur const& o){
//   return s+=o;
// }

// const Systeme operator+(Oscillateur const& o1, Oscillateur const& o2){ // viable mais inutilisable, je pense
//   Systeme s;
//   s+=o1;
//   s+=o2;
//   return s;
// }

// const Systeme operator+(Systeme s1, Systeme const& s2){
//   return s1+=s2;
// }
