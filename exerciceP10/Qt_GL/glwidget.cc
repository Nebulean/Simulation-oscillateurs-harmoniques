#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include <cmath>
#include "glwidget.h"
#include "integrateur.h"
#include "eulercromer.h"
#include "rungekutta.h"
#include "newmark.h"
using namespace std;

/*!
 * Cette méthode initialise le système, et tous les éléments qui le compose.
 *
 * C'est ici que l'on peut sélectionner les oscillateurs à dessiner, les
 * valeurs initiales qui leur sont attribué, et la sélection de l'oscillateur à
 * dessiner dans l'espace des phases.
 *
 * Voici les oscillateurs qui peuvent être construit, et les paramètres servant
 * à leur initialisation.
 * Pendule: masse, longueur, viscosité, supportadessin, P, Q, O.
 * Ressort: masse, elasticité, viscosité, supportadessin, P, Q, O, a, avec a de norme 1.
 * Torsion: moment d'inertie, cte de torsion, friction, support, P, Q, O.
 * Chariot: masse du chariot, masse du pendule, longueur du pendule, elasticité, viscosité du chariot, viscosité du pendule, support, P, Q, O.
 * PenduleDouble: masse1, masse1, longueur1, longueur2, support, P, Q, O.
 * PenduleRessort: masse, longueur, raideur, support, P, Q, O.
 *
*/
void GLWidget::initSys(){
  // on initialise tous les oscillateurs que l'on souhaite afficher.
  Pendule p(2, 2, 0.5, &vue, {M_PI/3}, {0.0}, {-2.0, -0.3, 0.0});
  Ressort r(0.5, 2.5, 0.01, &vue, {0.0}, {0.0}, {-2.5, 2.0, -1.0}, {0.6, 0.0, -0.8});
  Torsion t(1, 1, 0, &vue, {M_PI/4}, {0.0}, {2.0, -1.0, 0.0});
  Chariot ch(1, 1, 1.5, 0.7, 0.1, 0.1, &vue, {1.5, M_PI/3}, {0.0, 0.0}, {2.0, 2.0, -2.0});
  PenduleDouble pdou(0.5, 0.5, 1, 1, &vue, {M_PI/2, 3*M_PI/4}, {0.0, 0.0}, {0.0, 2.0, 0.0});
  PenduleRessort pr(1, 1, 10, &vue, {0.5, -0.5}, {0.0, 0.0}, {0.0, 0.5, -0.5});

  /* BEGIN - Choix de l'oscillateur dessiné dans l'espace des phases*/

  /* Pour selectionner un oscillateur à dessiner PAR DEFAUT, suivez la syntaxe suivante.
   *
   * nom_oscillateur.setPhase(&_phase);
   * _oscPhase = place_de_l'oscillateur_dans_la_collection_de_systeme;
   *
   * La première ligne permet de lier la phase à un oscillateur à l'espace de
   * phase. La deuxième ligne permet de savoir à quel oscillateur on se trouve
   * dans le vector contenant tous les oscillateurs. Il est utilisé pour le
   * changement d'oscillateur dessiné dans l'espace de phase en cours d'execution.
   *
   * Dans le cas où vous ajoutez la phase à deux oscillateurs en même temps,
   * le resultat va vous surprendre.
   *
   * Plus sérieusement, il n'y a pas de protection contre les "inclusions multiples",
   * donc le résultat est plutot aléatoire si ça arrive (Néanmoins, très joli !).
   */
  p.setPhase(&_phase);
  _oscPhase = 0;
  // r.setPhase(&_phase);
  // _oscPhase = 1;
  // t.setPhase(&_phase);
  // _oscPhase = 2;
  // ch.setPhase(&_phase);
  // _oscPhase = 3;
  // pdou.setPhase(&_phase);
  // _oscPhase = 4;
  // pr.setPhase(&_phase);
  // _oscPhase = 5;

  /* END */

  // On ajoute les pendules au système.
  _sys+=p;
  _sys+=r;
  _sys+=t;
  _sys+=ch;
  _sys+=pdou;
  _sys+=pr;
}




// ======================================================================
void GLWidget::initializeGL()
{
  vue.init();
  timerId = startTimer(20);

  // on initialise le Systeme.
  initSys();
}

// ======================================================================
void GLWidget::resizeGL(int width, int height)
{
  /* On commence par dire sur quelle partie de la
   * fenêtre OpenGL doit dessiner.
   * Ici on lui demande de dessiner sur toute la fenêtre.
   */
  glViewport(0, 0, width, height);

  /* Puis on modifie la matrice de projection du shader.
   * Pour ce faire on crée une matrice identité (constructeur
   * par défaut), on la multiplie par la droite par une matrice
   * de perspective.
   * Plus de détail sur cette matrice
   *     http://www.songho.ca/opengl/gl_projectionmatrix.html
   * Puis on upload la matrice sur le shader à l'aide de la
   * méthode de la classe VueOpenGL
   */
  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);

  // on conserve la projection actuelle.
  matrice_projection = matrice;
}

// ======================================================================
void GLWidget::paintGL()
{
  /* Cette méthode redessine la scène.
   * Elle est appellée lorsqu'on utilise updateGL().
   */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (vue.isPhase()) {
    _phase.dessine();
  } else {
    // on remet la bonne projection, sinon l'écran est dilaté.
    vue.setProjection(matrice_projection);

    // on dessine le système.
    _sys.dessine();
  }
}


// ======================================================================
void GLWidget::keyPressEvent(QKeyEvent* event)
{
  constexpr double petit_angle(5.0); // en degrés
  constexpr double petit_pas(0.2);

  switch (event->key()) {

  case Qt::Key_Left:
    vue.rotate(petit_angle, 0.0, -1.0, 0.0);
    break;

  case Qt::Key_Right:
    vue.rotate(petit_angle, 0.0, +1.0, 0.0);
    break;

  case Qt::Key_Up:
    vue.rotate(petit_angle, -1.0, 0.0, 0.0);
    break;

  case Qt::Key_Down:
    vue.rotate(petit_angle, +1.0, 0.0, 0.0);
    break;

  case Qt::Key_PageUp:
  case Qt::Key_W:
    vue.translate(0.0, 0.0,  petit_pas);
    break;

  case Qt::Key_PageDown:
  case Qt::Key_S:
    vue.translate(0.0, 0.0, -petit_pas);
    break;

  case Qt::Key_A:
    vue.translate( petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_D:
    vue.translate(-petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_R:
    vue.translate(0.0, -petit_pas, 0.0);
    break;

  case Qt::Key_F:
    vue.translate(0.0,  petit_pas, 0.0);
    break;

  case Qt::Key_Q:
    vue.rotate(petit_angle, 0.0, 0.0, -1.0);
    break;

  case Qt::Key_E:
    vue.rotate(petit_angle, 0.0, 0.0, +1.0);
    break;

  case Qt::Key_Home:
  case Qt::Key_H:
    vue.initializePosition();
    break;

  case Qt::Key_Space:
    pause();
    break;

  // lorsqu'on appuie sur B, la visibilité de la boussole s'inverse.
  case Qt::Key_B:
    vue.toggleBoussole();
    break;

  // lorsqu'on appuie sur §, le mode debug est activé.
  case Qt::Key_section:
    vue.toggleDebugMode();
    break;

  // lorsqu'on appuie sur V, la vue est modifiée.
  case Qt::Key_V:
    vue.toggleVue();
    break;

  // lorsqu'on appuie, on choisi l'intégrateur d'Euler-Cromer.
  case Qt::Key_1:
    change_integrateur(new Eulercromer, 1);
    cout << "Nouvel intégrateur: Euler-Cromer: " << _integrateur << endl;
    break;

  // lorsqu'on appuie, on choisi l'intégrateur de Newmark.
  case Qt::Key_2:
    change_integrateur(new Newmark, 2);
    cout << "Nouvel intégrateur: Newmark: " << _integrateur << endl;
    break;

  // lorsqu'on appuie, on choisi l'intégrateur d'Runge-Kutta.
  case Qt::Key_3:
    change_integrateur(new RungeKutta, 3);
    cout << "Nouvel intégrateur: Runge-Kutta: " << _integrateur << endl;
    break;

  // lorsqu'on appuie sur P, switch à l'espace des phases ou on retourne aux oscillateurs.
  case Qt::Key_P:
    vue.togglePhase();
    break;

  // change l'oscillateur traité par l'espace des phases.
  case Qt::Key_O:
    change_phase();
    break;
  };

  updateGL(); // redessine
}

// ======================================================================
void GLWidget::timerEvent(QTimerEvent* event)
{
  Q_UNUSED(event);

  // on génère le "bon" dt
  double dt = chronometre.restart() / 1000.0;
  // en cas de dt trop grand...
  if (dt > 0.05) {
    dt = 0.005; // ...on ralenti la simulation.
  }
  // À activer si on veut checker le dt utilisé à chaque frame.
  // cout << "dt actuel = " << dt << endl;

  // on alligne le dt calculé avec celui du systeme.
  _sys.setdt(dt);

  // on fait évoluer le système.
  _sys.evolue();

  // on met à jour la fenêtre.
  updateGL();
}

// ======================================================================
void GLWidget::pause()
{
  if (timerId == 0) {
    // dans ce cas le timer ne tourne pas alors on le lance
    timerId = startTimer(20);
    chronometre.restart();
  } else {
    // le timer tourne alors on l'arrête
    killTimer(timerId);
    timerId = 0;
  }
}



/*!
 * Enregistre la dernière position de la souris.
 */
void GLWidget::mousePressEvent(QMouseEvent* event)
{
  lastMousePosition = event->pos();
}


/*!
 * Mouvement de la souris. click & drag.
 */
void GLWidget::mouseMoveEvent(QMouseEvent* event)
{
  /* If mouse tracking is disabled (the default), the widget only receives
   * mouse move events when at least one mouse button is pressed while the
   * mouse is being moved.
   *
   * Pour activer le "mouse tracking" if faut lancer setMouseTracking(true)
   * par exemple dans le constructeur de cette classe.
   */

  if (event->buttons() & Qt::LeftButton && !vue.isPhase()) { // désactivé dans l'espace des phases pour éviter le lag
	constexpr double petit_angle(.4); // en degrés

	// Récupère le mouvement relatif par rapport à la dernière position de la souris
	QPointF d = event->pos() - lastMousePosition;
	lastMousePosition = event->pos();

	vue.rotate(petit_angle * d.manhattanLength(), d.y(), d.x(), 0);

	update();
  }
}

//! Permet de changer d'intégrateur.
void GLWidget::change_integrateur(Integrateur* intgr, int nbIntgr){
  if (_integrateurActuel != nbIntgr) {
    // copie du pointeur
    Integrateur* tmp(_integrateur);

    // on applique le nouveau pointeur à GLWidget
    _integrateur = intgr;

    // on l'applique au système
    _sys.changeIntegrateur(_integrateur);

    // on change l'id de l'intégrateur
    _integrateurActuel = nbIntgr;

    // et on désalloue l'intégrateur précédent.
    delete tmp;
  } else {
    delete intgr;
  }
}

/*!
 * Passe à l'oscillateur suivant dans le tableau dynamique. Si on arrive au bout,
 * on retourne au début.
 */
void GLWidget::change_phase(){
  // on commence par délier la phase à l'oscillateur actuel.
  _sys.setPhase(nullptr, _oscPhase);

  // ensuite on efface les valeurs actuellement enregistrées dans la Phase.
  _phase.empty();

  // on choisi le nouvel oscillateur à dessiner dans l'espace des phases.
  if (_oscPhase < _sys.sizeOsc() - 1) {
    // si on est pas au bout du vector, on avance d'un
    ++_oscPhase;
  } else {
    // si on est au bout, on recommence.
    _oscPhase = 0;
  }
  cout << "Oscillateur nouvellement dessiné dans l'espace de phase: " << _oscPhase << endl;

  // et finalement on lie la Phase au nouvel oscillateur.
  _sys.setPhase(&_phase, _oscPhase);
}
