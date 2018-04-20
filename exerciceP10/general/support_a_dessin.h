#ifndef SUPPORT_A_DESSIN_H
#define SUPPORT_A_DESSIN_H

class Contenu;

class SupportADessin
{
 public:
  virtual ~SupportADessin() {}

  virtual void dessine(Contenu const& a_dessiner) = 0;

  /* Mettre ici toutes les méthodes nécessaires pour dessiner tous les
   * objets que l'on veut dessiner. Par exemple :
   *    virtual void dessine(Nounours const& a_dessiner) = 0;
   *    virtual void dessine(Voiture  const& a_dessiner) = 0;
   */
};

#endif
