#ifndef H_SUPPORTADESSIN
#define H_SUPPORTADESSIN

// CES INCLUDE NE DOIVENT PAS ÊTRE LA, SOUS PEINE D'AVOIR DES ERREURS D'INCOMPLETION DE CLASSES.
// #include "../pendule/pendule.h"
// #include "../ressort/ressort.h"
// #include "../systeme/systeme.h"
// #include "../oscillateur/oscillateur.h"

class Pendule;
class Ressort;
// class Systeme;
//
// // pour des tests
// class Oscillateur;

class SupportADessin{
public:
  virtual ~SupportADessin() {}

  // pour testeulercromer
  virtual void dessine(Pendule const&) = 0;
  virtual void dessine(Ressort const&) = 0;
  // virtual void dessine(Systeme const&) = 0;

  // pour des tests
  // virtual void dessine(Oscillateur const&) = 0;
};

#endif // H_SUPPORTADESSIN
