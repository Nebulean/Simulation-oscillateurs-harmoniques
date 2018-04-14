#ifndef H_SUPPORTADESSIN
#define H_SUPPORTADESSIN

class Pendule;
class Ressort;
class Systeme;

class SupportADessin{
public:
  // destructeur de SupportADessin
  virtual ~SupportADessin() {}

  // l'ensemble des méthodes dessinant les objets dessinables.
  virtual void dessine(Pendule const& pendule_a_dessiner) = 0;
  virtual void dessine(Ressort const& ressort_a_dessiner) = 0;
  virtual void dessine(Systeme const& systeme_a_dessiner) = 0;
};

#endif // H_SUPPORTADESSIN
