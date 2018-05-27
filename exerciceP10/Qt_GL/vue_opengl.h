#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include <cmath>
#include "supportadessin.h"
#include "pendule.h"
#include "ressort.h"
#include "systeme.h"
#include "torsion.h"
#include "chute.h"
#include "chariot.h"
#include "penduledouble.h"
#include "glsphere.h"
#include "penduleressort.h"
#include "phase.h"

/*!
 * Classe implémentant le support à dessin en mode OpenGL.
 */
class VueOpenGL : public SupportADessin {
 public:
  // méthodes de dessin (héritées de SupportADessin)
  virtual void dessine(Pendule const& pendule_a_dessiner) override;
  virtual void dessine(Ressort const& ressort_a_dessiner) override;
  virtual void dessine(Systeme const& systeme_a_dessiner) override;
  virtual void dessine(Torsion const& torsion_a_dessiner) override;
  virtual void dessine(Chariot const& chariot_a_dessiner) override;
  virtual void dessine(PenduleDouble const& penduledouble_a_dessiner) override;
  virtual void dessine(PenduleRessort const& penduleressort_a_dessiner) override;
  virtual void dessine(Phase const& espace_de_phase_a_dessiner) override;
  // est vide, mais est requis pour compiler.
  virtual void dessine(Chute const& chute_a_dessiner) override {Q_UNUSED(chute_a_dessiner);}
  //! méthode de (ré-)initialisation
  void init();
  //! méthode de (ré-)initialisation
  void initializePosition();

  //! méthode changent la projection actuelle, avec la matrice 4x4 donnée.
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  //! Méthodes translatant une matrice dans une certaine direction.
  void translate(double x, double y, double z);

  //! Méthode appliquant une rotation d'un certain angle, dans un certain plan.
  void rotate(double angle, double dir_x, double dir_y, double dir_z);

  // méthode utilitaire offerte pour simplifier
  //! Méthode dessinant un cube.
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  //! Méthode dessinant une sphère.
  void dessineSphere(QMatrix4x4 const& point_de_vue = QMatrix4x4(), double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  //! Méthode dessinant des axes cartésiens.
  void dessineAxes(QMatrix4x4 const& point_de_vue = QMatrix4x4(), bool translatable = true, bool en_couleur = true);
  //! Méthode dessinant une ligne.
  void dessineLigne(QMatrix4x4 const& point_de_vue = QMatrix4x4(), bool en_couleur = false, double longueur = 1, double x = 1.0, double y = 0.0, double z = 0.0, double rouge = 1.0, double vert = 1.0, double bleu = 1.0 );
  //! Méthode dessinant une ligne avec une sphère au bout.
  void dessineOscill(Oscillateur const& a_dessiner, QMatrix4x4 point_de_vue, double longueur, double coeff_diametre, double rougeLigne = 1.0, double vertLigne = 1.0, double bleuLigne = 1.0, double rougeSphere = 1.0, double vertSphere = 1.0, double bleuSphere = 1.0);
  //void dessineOscill(Oscillateur const& a_dessiner, QMatrix4x4 point_de_vue, double coeff_diametre, double rougeLigne = 1.0, double vertLigne = 1.0, double bleuLigne = 1.0, double rougeSphere = 1.0, double vertSphere = 1.0, double bleuSphere = 1.0);

  //! Méthode de dessin des axes suivant le point de vue.
  void dessineAxesCamera();

  //! Switch changeant la visibilité de la boussole.
  void toggleBoussole() { boussoleVisible = !boussoleVisible; }

  //! Switch changeant l'état du mode debug.
  void toggleDebugMode() { debugMode = !debugMode; }

  //! Switch pour passer de la vue première personne à la vue troisième personne.
  void toggleVue() { TPS = !TPS; }

  //! Switch pour passer à l'espace des phases
  void togglePhase();
  //! Accesseur de l'état de l'espace des phases
  bool isPhase() { return _isPhase; }

 private:
  //! Un shader OpenGL encapsulé dans une classe Qt
  QGLShaderProgram prog;

  //! Le caneva de sphère à dessiner.
  GLSphere sphere;

  //! Caméra
  QMatrix4x4 matrice_vue;

  //! Matrice qui mémorise les rotations en première personne et les translations de matrice_vue
  QMatrix4x4 memoire;

  //! Matrice affectée par les rotations mais pas les translations
  QMatrix4x4 boussole;
  //! Matrice qui mémorise la position des axes de la boussole
  QMatrix4x4 position;

  //! Variable d'état de la boussole, true = visible.
  bool boussoleVisible;

  //! Variable d'état du mode debug. (text activé)
  bool debugMode;

  //! Variable d'état de la vue première/troisième personne, TPS = troisième personne activée.
  bool TPS;

  //! Variable d'état de l'espace des phases
  bool _isPhase;
};

//! Convertisseur Radian -> Degrés.
double toDegree(double radian);

//! "Change l'echelle"
double mapTo(double valeur, double fromLow, double fromHigh, double toLow, double toHigh);

#endif
