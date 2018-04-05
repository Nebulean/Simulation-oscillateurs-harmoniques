#ifndef H_DESSINABLE
#define H_DESSINABLE

#include "../supportadessin/supportadessin.h"

class SupportADessin;

class Dessinable{
public:
  Dessinable(SupportADessin*);
  virtual ~Dessinable() {};
  virtual void dessine() = 0;

protected:
  SupportADessin* _support; // Il faut penser à le désallouer ! NON, C'EST CELUI QUI ALLOUE QUI DESALLOUE ! 

};


#endif // H_DESSINABLE
