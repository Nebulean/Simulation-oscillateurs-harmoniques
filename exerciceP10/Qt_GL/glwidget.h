#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
// #include "contenu.h"
#include "systeme.h"
#include "eulercromer.h"
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
    , _integrateur(new RungeKutta) // Ne faut-il pas le delete ?
    , _sys(0.1, &vue, _integrateur)
  {}
  virtual ~GLWidget() {}

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


  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  //! Position de la souris.
  QPoint lastMousePosition;

  //! L'intégrateur utilisé dans ce projet
  /*!
   * Il s'agit d'un pointeur pour se laisser la liberté de le changer lors de
   * l'initialisation.
   */
  Integrateur* _integrateur;

  // objets à dessiner, faire évoluer
  // Contenu c;
  //! Systeme contenant tous les Oscillateurs.
  Systeme _sys;

};

#endif // GLWIDGET_H
