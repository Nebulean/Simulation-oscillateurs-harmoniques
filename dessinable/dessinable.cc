#include "dessinable.h"
#include "../supportadessin/supportadessin.h"
#include <iostream>
using namespace std;


Dessinable::Dessinable(SupportADessin* support)
 : _support(support)
 {}

ostream& operator<<(ostream& out, Dessinable const& obj) {
  obj.affiche(out);
  return out;
}
