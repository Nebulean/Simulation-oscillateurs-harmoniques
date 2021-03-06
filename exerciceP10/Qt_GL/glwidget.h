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

/*!
 * Classe s'occupant de la gestion de la fenêtre.
 */
class GLWidget : public QGLWidget
/* La fenêtre hérite de QGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
  //! Constructeur de GLWidget.
  GLWidget(QWidget* parent = nullptr)
    : QGLWidget(parent)
    , _integrateur(new RungeKutta) // Par défaut, on utilise un intégrateur de RungeKutta
    , _sys(0.1, &vue, _integrateur) // on initialise le système, vide.
    , _integrateurActuel(3) // par défaut, on utilise un intégrateur de Runge-Kutta (3).
    , _phase(&vue) // on initialise la phase, vide.
  {}
  //! Destructeur de GLWidget, qui désalloue l'intégrateur actuel.
  virtual ~GLWidget() { delete _integrateur; }

private:
  // Les 3 méthodes clés de la classe QGLWidget à réimplémenter
  //! Méthode initialisant OpenGL.
  virtual void initializeGL()                  override;
  //! Méthode gérant le redimensionnement de la fenêtre.
  virtual void resizeGL(int width, int height) override;
  //! Méthode gérant le dessine du contenu.
  virtual void paintGL()                       override;

  //! Méthode d'initialisation du système.
  void initSys();

  //! Change l'oscillateur actuellement traité par l'espace des phases.
  void change_phase();

  // Méthodes de gestion d'évènements
  //! Méthode de gestion des évènements liés aux touches.
  virtual void keyPressEvent(QKeyEvent* event) override;
  //! Méthode de gestion du temps génèrant le bon dt.
  virtual void timerEvent(QTimerEvent* event)  override;

  //! gestion des clicks de souris
  virtual void mousePressEvent(QMouseEvent* event) override;

  //! gestion des mouvements de la souris
  virtual void mouseMoveEvent(QMouseEvent* event)  override;

  //! Change l'intégrateur actuel avec un nouveau.
  void change_integrateur(Integrateur* nouvel_integrateur, int nombre_integrateur_actuel);

  //! Méthodes de gestion interne
  void pause();

  //! Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  //! Timer
  int timerId;

  //! Attribut utile pour faire évoluer les objets avec le bon "dt"
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

  //! Systeme contenant tous les Oscillateurs.
  Systeme _sys;

  //! Phase d'un oscillateur en particulier.
  Phase _phase;

  //! Garde en mémoire l'oscillateur actuellement traité par l'espace de phase.
  /*!
   * En fait, cette variable garde en mémoire la position dans la collection
   * hétérogène où se situe l'oscillateur actuellement traité par l'espace de
   * phase.
   */
  size_t _oscPhase;

  //! Matrice conservant la bonne projection. Utilisé pour l'espace des phases.
  /*!
   * Cette matrice permet de régler le problème de dilatation lorsque l'on
   * applique le zoom à "projection" dans le dessine de Phase. Elle garde en
   * mémoire la bonne projection.
   */
  QMatrix4x4 matrice_projection;
};

#endif // GLWIDGET_H
