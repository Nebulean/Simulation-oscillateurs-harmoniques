#ifndef H_SUPPORTADESSIN
#define H_SUPPORTADESSIN

#include "../pendule/pendule.h"

class Pendule;

class SupportADessin{
public:
  virtual ~SupportADessin() {}

  // pour testeulercromer
  virtual void dessine(Pendule const&) = 0;
  // virtual void dessine(Ressort const&) = 0;
  // virtual void dessine(Systeme const&) = 0;
};

#endif // H_SUPPORTADESSIN
