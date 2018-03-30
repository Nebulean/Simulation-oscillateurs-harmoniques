#ifndef H_DESSINABLE
#define H_DESSINABLE

#include "../supportadessin/supportadessin.h"

class Dessinable{
public:
  Dessinable(SupportADessin*);
  virtual ~Dessinable();
  virtual void dessine() = 0;

protected:
  SupportADessin* _support;

};


#endif // H_DESSINABLE
