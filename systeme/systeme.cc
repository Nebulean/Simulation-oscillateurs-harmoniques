#include "systeme.h"
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"
#include "../oscillateur/oscillateur.h"
#include "../integrateur/integrateur.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

/*
 * Destructeur de système. Tant que nous utilisons des pointeurs intelligents,
 * nous n'avons pas de problème de destruction, car ils se détruisent tout seul.
 */
Systeme::~Systeme()
{}

/*
 * Constructeur de Systeme.*/
Systeme::Systeme(double dt, double t, SupportADessin* support, Integrateur* integr)
 : Dessinable(support), _dt(dt), _t(t), _integr(integr)
{
  // _oscillateurs.clear(); // dans le doute, comme ça on a un tableau bien vide.
}

// afficheur général
void Systeme::affiche() const {
  for (auto const& osc : _oscillateurs) {
    osc->dessine();
  };
}

// pour ajouter un oscillateur au système
void Systeme::ajoute(Oscillateur* osc) {
  if (osc != nullptr){ // on vérifie que le pointeur pointe vers quelque chose
    _oscillateurs.push_back(unique_ptr<Oscillateur>(osc));
  };
}

void Systeme::evolue() {
  for (auto& osc : _oscillateurs) {
    _integr->evolue(*osc, _dt, _t);
  };
  _t += _dt;
}
