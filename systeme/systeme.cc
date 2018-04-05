#include "systeme.h"
#include "../dessinable/dessinable.h"
#include "../supportadessin/supportadessin.h"
#include "../oscillateur/oscillateur.h"
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
Systeme::Systeme(double dt, double t, SupportADessin* support)
 : Dessinable(support), _dt(dt), _t(t)
{
  _oscillateurs.clear(); // dans le doute, comme ça on a un tableau bien vide.
}


// getter
// vector<unique_ptr<Oscillateur>>&& Systeme::oscillateurs() const
// {
//   return _oscillateurs;
// }


// getter
  // vector<unique_ptr<Oscillateur>> Systeme::oscillateurs()
  // {
  //   return _oscillateurs;
  // }
// unique_ptr<Oscillateur> oscillateurs(size_t i)
// { return _oscillateurs[i]; }
  // Oscillateur* oscillateurs()
  // {
  //   return &_oscillateurs;
  // }

// /* Surcharge interne de l'opérateur d'affichage d'une Systeme. Celui-ci est utilisé
//  * pour la simulation en mode texte. Cela nous paraissait être la meilleure
//  * solution aux problèmes de droits que nous avions.
//  */
// std::ostream& Systeme::operator<<(std::ostream& flot)
// {
//   for (size_t i = 0; i < count; i++) {
//     /* Doit retourner un truc du type
//      * Oscillateur 42
//      * (infos sur l'oscillateur à la position 42 du tableau)
//      */
//     flot << "Oscillateur " << i << endl << *(_oscillateurs[i]) << endl; // *(...) car on ne veut pas afficher l'adresse, mais le contenu qui s'y trouve.
//   }
//
//   // for (auto const& osc : _oscillateurs) {
//   //   // osc->dessine();
//   //   flot << osc << endl; // ?
//   // }
//
//   return flot;
//
//
// }
