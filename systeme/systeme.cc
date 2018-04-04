#include "systeme.h"
#include "../supportadessin/supportadessin.h"
using namespace std;

/*
 * Destructeur de système. Tant que nous utilisons des pointeurs intelligents,
 * nous n'avons pas de problème de destruction, car ils se détruisent tout seul.
 */
Systeme::~Systeme()
{}

/*
 * Constructeur de Systeme.*/
Systeme::Systeme(double dt, double t, std::initializer_list<unique_ptr<Oscillateur>> oscillateurs, SupportADessin* support)
 : Dessinable(support), _dt(dt), _t(t), _oscillateurs(oscillateurs)
{}
