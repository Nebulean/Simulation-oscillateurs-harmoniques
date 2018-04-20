#ifndef DESSINABLE_H
#define DESSINABLE_H

class SupportADessin;

class Dessinable {
 public:
  Dessinable(SupportADessin* support)
    : support(support)
  {}
  virtual ~Dessinable() {}
  virtual void dessine() = 0;

 protected:
  /* Nous mettons un pointeur au lieu d'une référence *
   * au cas où l'on voudrait changer de support (non  *
   * implémenté ici), ou même copier un dessinable,   *
   * échanger (swap) deux dessinables, etc.           *
   * Il n'est pas nécessaire d'implémenter une copie  *
   * profonde ici ; c'est bien une copie de surface   *
   * dont nous avons besoin.                          */
  SupportADessin* support;
};

#endif
