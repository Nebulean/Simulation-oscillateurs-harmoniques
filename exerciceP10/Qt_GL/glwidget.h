#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "systeme.h"
#include "rungekutta.h"
#include "eulercromer.h"
#include "newmark.h"
#include "integrateur.h"
#include "rungekutta.h"

class GLWidget : public QGLWidget
/* La fenêtre hérite de QGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
  GLWidget(QWidget* parent = nullptr)
    : QGLWidget(parent)
    // , c(&vue)
    , _integrateur(new RungeKutta) // Par défaut, on utilise un intégrateur de RungeKutta
    , _sys(0.1, &vue, _integrateur)
    , _integrateurActuel(3) // par défaut, on utilise un intégrateur de Runge-Kutta (3).
    , _isPhase(false)
    , _phase(&vue)
  {}
  virtual ~GLWidget() { delete _integrateur; }

  void togglePhase();

private:
  // Les 3 méthodes clés de la classe QGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  //! Méthode d'initialisation du système.
  void initSys();

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;

  //! gestion des clicks de souris
  virtual void mousePressEvent(QMouseEvent* event) override;

  //! gestion des mouvements de la souris
  virtual void mouseMoveEvent(QMouseEvent* event)  override;

  // Surcharges de la méthode choose_integrateur(...) permetant de choisir le bon intégrateur.
  // void change_integrateur(Eulercromer* IEC);
  // void change_integrateur(Newmark* INM);
  // void change_integrateur(RungeKutta* INM);
  void change_integrateur(Integrateur* nouvel_integrateur, int nombre_integrateur_actuel);

  //! Méthodes de gestion interne
  void pause();

  //! Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  //! Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  //! Position de la souris.
  QPoint lastMousePosition;

  //! L'intégrateur utilisé dans ce projet
  /*!
   * Il s'agit d'un pointeur sur un intégrateur, ce qui nous donne la posibilité
   * de changer d'intégrateur facilement.
   */
  Integrateur* _integrateur;

  //! Variable conservant l'intégrateur actuellement utilisé.
  /*!
   * Les intégrateurs sont décrit par des ints.
   *
   * - (1) --> Euler-Cromer
   * - (2) --> Newmark
   * - (3) --> Runge-Kutta
   */
  int _integrateurActuel;

  // objets à dessiner, faire évoluer
  // Contenu c;
  //! Systeme contenant tous les Oscillateurs.
  Systeme _sys;

  //! Bool activant ou desactivant l'affichage de l'espace des phases.
  bool _isPhase;

  //! Pointeur sur une Phase d'un oscillateur en particulier.
  Phase _phase;

  //! Matrice conservant la bonne projection. Utilisé pour l'espace des phases.
  /*!
   * Cette matrice permet de régler le problème de dilatation lorsque l'on
   * applique le zoom à "projection" dans le dessine de Phase. Elle garde en
   * mémoire la bonne projection.
   */
  QMatrix4x4 matrice_projection;

};

#endif // GLWIDGET_H
