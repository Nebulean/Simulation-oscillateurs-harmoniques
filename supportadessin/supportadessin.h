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
  virtual void dessine(Pendule const&) = 0;
  virtual void dessine(Ressort const&) = 0;
  virtual void dessine(Systeme const&) = 0;
};

#endif // H_SUPPORTADESSIN
