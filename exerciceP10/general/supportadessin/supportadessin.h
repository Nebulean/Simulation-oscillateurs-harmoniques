#ifndef H_SUPPORTADESSIN
#define H_SUPPORTADESSIN

class Pendule;
class Ressort;
class Systeme;
class Torsion;
class Chute;
class Chariot;
class PenduleDouble;

/*!
 * Méthode de base des support à dessin.
 *
 * Héritée plus tard pour la simulation en texte (TextViewer) ou en mode
 * graphique (VueOpenGL).
 */
class SupportADessin{
public:
  //! Destructeur de SupportADessin
  virtual ~SupportADessin() {}

  // L'ensemble des méthodes dessinant les objets dessinables.
  //! Méthode de dessin de Pendule.
  virtual void dessine(Pendule const& pendule_a_dessiner) = 0;

  //! Méthode de dessin de Ressort.
  virtual void dessine(Ressort const& ressort_a_dessiner) = 0;

  //! Méthode de dessin de Systeme.
  virtual void dessine(Systeme const& systeme_a_dessiner) = 0;

  //! Méthode de dessin de Torsion.
  virtual void dessine(Torsion const& torsion_a_dessiner) = 0;

  //! Méthode de dessin de Chute.
  virtual void dessine(Chute const& chute_a_dessiner) = 0;

  //! Méthode de dessin de Chariot.
  virtual void dessine(Chariot const& chariot_a_dessiner) = 0;

  //! Méthode de dessin de PenduleDouble
  virtual void dessine(PenduleDouble const& penduledouble_a_dessiner) = 0;
};

#endif // H_SUPPORTADESSIN
