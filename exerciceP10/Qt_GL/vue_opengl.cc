#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include <cmath>
using namespace std;
// #include "contenu.h"

// ======================================================================
// void VueOpenGL::dessine(Contenu const& a_dessiner)
// {
//    // Dessine le 1er cube (à l'origine)
//   dessineCube();
//
//   QMatrix4x4 matrice;
//   // Dessine le 2e cube
//   matrice.translate(0.0, 1.5, 0.0);
//   matrice.scale(0.25);
//   dessineCube(matrice);
//
//   // Dessine le 3e cube
//   matrice.setToIdentity();
//   matrice.translate(0.0, 0.0, 1.5);
//   matrice.scale(0.25);
//   matrice.rotate(45.0, 0.0, 1.0, 0.0);
//   dessineCube(matrice);
//
//   // Dessine le 4e cube
//   matrice.setToIdentity();
//   matrice.rotate(a_dessiner.infos(), 1.0, 0.0, 0.0);
//   matrice.translate(0.0, 2.3, 0.0);
//   matrice.scale(0.2);
//   dessineCube(matrice);
// }
void VueOpenGL::dessine(Pendule const& pendule)
{
  // on créé une matrice.
  QMatrix4x4 matrice;

  // on déplace le point devant nous, centré.
  //matrice.translate(0.0, 0.0, -2.0);

  // on déplace le point pour l'amener à l'origine du pendule.
  matrice.translate(pendule.O(0), pendule.O(1), pendule.O(2));

  // on fait une rotation à 90 degrés pour avoir le pendule à l'angle 0.
  matrice.rotate(-90, 0.0, 0.0, 1.0);

  // on applique la rotation actuelle du pendule, dans le plan perpendiculaire à
  // la direction principale et passant par O. (a n'est pas encore implémenté.)
  matrice.rotate(toDegree(pendule.P(0)), 0.0, 0.0, 1.0);

  // // on dessine la ligne.
  // dessineLigne(matrice, false, pendule.L(), pendule.a(0), pendule.a(1), pendule.a(2));
  //
  // // on va a l'extrémité de la ligne
  // matrice.translate(pendule.L()*pendule.a(0), pendule.L()*pendule.a(1), pendule.L()*pendule.a(2));
  //
  // // on réduit un peu la taille de la sphère
  // matrice.scale(pendule.m()/10);
  //
  // // on dessine la sphère.
  // dessineSphere(matrice);

  dessineOscill(pendule, matrice, pendule.L(), pendule.m());

}

void VueOpenGL::dessine(Ressort const& ressort)
{
  // on créé une matrice 4x4.
  QMatrix4x4 matrice;

  // on place le point dans le centre de l'écran.
  //matrice.translate(0.0, 0.0, -2.0);

  // on déplace le ressort à l'origine
  matrice.translate(ressort.O(0), ressort.O(1), ressort.O(2));

  // on fait une rotation à 90 degrés de la matrice.
  matrice.rotate(90, 0.0, 0.0, 1.0);

  // on se place le ressort dans la direction de a.
  //matrice.translate(ressort.a(0), ressort.a(1), ressort.a(2));
  //matrice.rotate(toDegree(atan(ressort.a(2)/ressort.a(0))), 0.0, 1.0, 0.0);

  // // on dessine la ligne, qui prend en paramètre la longueur courante du
  // // ressort.
  // //dessineLigne(matrice, false, ressort.P(0));
  // dessineLigne(matrice, false, ressort.P(0), ressort.a(0), ressort.a(1), ressort.a(2));
  //
  // // on se place au bout du fil
  // //matrice.translate(ressort.P(0), 0.0, 0.0);
  // matrice.translate(ressort.P(0)*ressort.a(0), ressort.P(0)*ressort.a(1), ressort.P(0)*ressort.a(2));
  //
  // // on modifie la taille de la sphère en fonction de la masse.
  // matrice.scale(ressort.m()/3);
  //
  // // on dessine la sphère
  // dessineSphere(matrice);

  dessineOscill(ressort, matrice, ressort.P(0), ressort.m());
}

void VueOpenGL::dessine(Torsion const& torsion)
{
  QMatrix4x4 matrice;

  // on place le point dans le centre de l'écran.
  //matrice.translate(0.0, 0.0, -2.0);

  // on déplace le pendule de Torsion à l'origine.
  matrice.translate(torsion.O(0), torsion.O(1), torsion.O(2));

  // on fait une rotation pour placer le pendule de Torsion dans sa position
  // initiale
  //matrice.rotate(45, 0.0, 1.0, 0.0);

  // on applique la rotation du pendule.
  matrice.rotate(toDegree(torsion.P(0)), 0.0, 1.0, 0.0);

  // // on enregistre la position
  // QMatrix4x4 reference(matrice);

  // // on dessine la première demi-tige.
  // dessineLigne(matrice, false, sqrt(torsion.I()), torsion.a(0), torsion.a(1), torsion.a(2));
  //
  // // on se place au bout de la demi-tige.
  // matrice.translate(sqrt(torsion.I())*torsion.a(0), sqrt(torsion.I())*torsion.a(1), sqrt(torsion.I())*torsion.a(2));
  //
  // // on réduit la taille de la sphère
  // matrice.scale(torsion.I()/5);
  //
  // // on dessine la première masse.
  // dessineSphere(matrice);

  dessineOscill(torsion, matrice, sqrt(torsion.I()), torsion.I());

  // on va de l'autre côté du pendule en faisant les opérations inverses.
  // on augmente de 5 la taille
  // matrice.scale(torsion.I()*5);

  // on déplace le point au centre.
  // matrice.translate(-1.0, 0.0, 0.0);

  // // on revient à la posiiton de référence
  // matrice = reference;

  // on inverse le sens
  matrice.scale(-1);

  // // on dessine la deuxième demi-tige.
  // //dessineLigne(matrice);
  // dessineLigne(matrice, false, sqrt(torsion.I()), torsion.a(0), torsion.a(1), torsion.a(2));
  //
  // // on se place au bout de la demi-tige.
  // //matrice.translate(1.0, 0.0, 0.0);
  // matrice.translate(sqrt(torsion.I())*torsion.a(0), sqrt(torsion.I())*torsion.a(1), sqrt(torsion.I())*torsion.a(2));
  //
  // // on réduit la taille de la sphère
  // matrice.scale(torsion.I()/5);
  //
  // // on dessine la deuxième masse.
  // dessineSphere(matrice);

  dessineOscill(torsion, matrice, sqrt(torsion.I()), torsion.I());
}

void VueOpenGL::dessine(Chariot const& chariot)
{
  // on créé une matrice
  QMatrix4x4 matrice;

  // on déplace le point pour l'amener à l'origine du chariot
  matrice.translate(chariot.O(0), chariot.O(1), chariot.O(2));

  // on dessine le chariot d'abord
  dessineOscill(chariot, matrice, chariot.P(0), chariot.m1());

  // on se déplace au bout du chariot
  matrice.translate(chariot.P(0)*chariot.a(0), chariot.P(0)*chariot.a(1), chariot.P(0)*chariot.a(2));

  // on applique la rotation actuelle du pendule
  matrice.rotate(toDegree(chariot.P(1)), 0.0, 0.0, 1.0);

  // on fait une rotation de 90 degrés
  matrice.rotate(-90, 0.0, 0.0, 1.0);

  //on dessine le pendule
  dessineOscill(chariot, matrice, chariot.L(), chariot.m2());
}

void VueOpenGL::dessine(Systeme const& systeme)
{
  // on dessine le système
  systeme.affiche();

  // On choisi d'afficher les informations de debug.
  if (debugMode) {
    cout << systeme << endl;
  }

  // On choisit de dessiner la boussole ou non.
  if (boussoleVisible) {
    dessineAxesCamera();
  }
}

// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  // on active la boussole
  boussoleVisible = true;

  // on désactive le mode debug
  debugMode = false;

  // on active le mode troisième personne
  TPS = true;

  sphere.initialize();
  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -4.0);
  // translation = matrice_vue;
  memoire = matrice_vue;
  boussole.setToIdentity();
  boussole.translate(-2.0, -1.0, -3.0);
  //boussole.rotate(-90.0, 1.0, 0.0, 0.0);
  position = boussole;
  // matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
  // matrice_vue.rotate(45.0, 0.0, 0.0, 1.0);
  // rotfps.setToIdentity();
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
  // translation = translation_supplementaire * translation;
  memoire = translation_supplementaire * memoire;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);

  if (TPS) {
  /* En multipliant d'abord par l'inverse des translations puis par la rotation puis par les translations
   * on fait en sorte que toutes les rotations se passent AVANT les translations
   * comme ça l'objet tourne sur lui-même. :)
   */
    matrice_vue = memoire * rotation_supplementaire * memoire.inverted() * matrice_vue; // troisième personne
  } else {
    matrice_vue = rotation_supplementaire * matrice_vue; // première personne
    // rotfps = rotation_supplementaire * rotfps;
    memoire = rotation_supplementaire * memoire;
  }

  boussole = position * rotation_supplementaire * position.inverted() * boussole;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}





/*!
 * Méthode générique de dessin de sphère.
 */
void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue, double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}





/*!
 * Méthode générique de dessin d'axes.
 */
void VueOpenGL::dessineAxes(QMatrix4x4 const& point_de_vue, bool translatable, bool en_couleur)
{
  if (translatable) {
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  } else {
    prog.setUniformValue("vue_modele", boussole * point_de_vue);
  }

  // prog.setUniformValue("vue_modele", boussole * point_de_vue);

  glBegin(GL_LINES);

  // axe X
  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);

  // axe Y
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);

  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

  glEnd();
}


/*!
 * Méthode générique de dessin de lignes.
 */
void VueOpenGL::dessineLigne(QMatrix4x4 const& point_de_vue, bool en_couleur, double longueur, double x, double y, double z )
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);

  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, longueur*x, longueur*y, longueur*z);

  glEnd();
}

/*!
 * Méthode générique de dessin d'oscillateur.
 */
void VueOpenGL::dessineOscill(Oscillateur const& osc, QMatrix4x4 point_de_vue, double longueur, double coeff){

  //on dessine l'axe de l'oscillateur en utilisant sa direction principale a
  dessineLigne(point_de_vue, false, longueur, osc.a(0), osc.a(1), osc.a(2));

  //on se déplace au bout de l'axe
  point_de_vue.translate(longueur*osc.a(0), longueur*osc.a(1), longueur*osc.a(2));

  //on réduit la taille de la sphère proportionnellement à la racine de la masse de l'oscillateur
  point_de_vue.scale(sqrt(coeff)/3);

  //on dessine la sphère
  dessineSphere(point_de_vue);
}


/*!
 * Méthode de dessin des axes qui suivent le point de vue (caméra).
 */
void VueOpenGL::dessineAxesCamera()
{
  // on dessine le repère, qui bouge avec la caméra.
  // on commence par créer une matrice 4x4 du point de vue des Axes.
  // QMatrix4x4 pdvAxes;
  // pdvAxes.translate(-2.0, -1.0, -3.0);
  //
  // positionAxes.translate(0, -2, 0);
  dessineAxes(QMatrix4x4(), false); // Laisser une matrice par défaut ici, sinon ça fuck up tout
}

/*!
 * Convertit des angles exprimés en radians vers les degrés.
 */
double toDegree(double radian){
  return radian * 180 / M_PI;
}
