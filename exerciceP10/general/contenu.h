#ifndef CONTENU_H
#define CONTENU_H

#include "dessinable.h"
#include "support_a_dessin.h"

class Contenu : public Dessinable {
public:
  Contenu(SupportADessin* vue)
    : Dessinable(vue), angle(0.0)
  {}
  virtual ~Contenu() {}

  virtual void dessine() override
  { support->dessine(*this); }

  void evolue(double dt);

  // accesseur
  double infos() const { return angle; }

private:
  double angle; /* pour le mouvement ;
                   dans cet exemple, juste une rotation
                   au cours du temps                    */
};

#endif // CONTENU_H
