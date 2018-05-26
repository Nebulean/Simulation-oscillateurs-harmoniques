#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include <cmath>
using namespace std;


void VueOpenGL::dessine(Phase const& phase)
{
  // on créé une matrice identité
  QMatrix4x4 matrice;

  // On met la matrice identité dans vue_modele
  prog.setUniformValue("vue_modele", matrice);

  /* Dessine le cadre blanc */
  // matrice.setToIdentity();
  // matrice.ortho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);         // matrice simple pour faire le cadre
  // prog.setUniformValue("projection", matrice);
  //
  // prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
  // glBegin(GL_LINE_LOOP);                                    // la primitive LINE_LOOP referme le tracé avec une ligne (n lignes)
  // prog.setAttributeValue(SommetId, -1.0, -1.0, 2.0);        // le 2.0 dans la composante z permet de mettre le cadre par dessus tout
  // prog.setAttributeValue(SommetId, +1.0, -1.0, 2.0);        // ceci fonctionne grace à l'option GL_DEPTH_TEST
  // prog.setAttributeValue(SommetId, +1.0, +1.0, 2.0);
  // prog.setAttributeValue(SommetId, -1.0, +1.0, 2.0);
  // glEnd();

  /* Change de matrice de projection adpatée aux zoom du graph */
  // matrice.setToIdentity();
  // double xmin(-2); // comme ça on a -2PI entre 0 et la gauche de l'écran.
  // double xmax(+2); // comme ça on a 2PI entre 0 et la droite de l'écran.
  // double ymin(-2); // comme ça on a -1.2 entre 0 et le bas de l'écran.
  // double ymax(+2); // comme ça on a 1.2 entre 0 et la le haut de l'écran.

  // choisi le niveau de zoom de la fenêtre
  /* Applique une projection orthographique, c-à-d
   * transformer des objets 3D vers des objets 2D.
   *
   * Le -10.0 c'est le plan éloigné du clipping.
   * Le 10.0 c'est le plan approché du clipping.
   * Voir: https://upload.wikimedia.org/wikipedia/commons/0/02/ViewFrustum.svg
   */
  matrice.ortho(-1.05 * phase.max(), 1.05 * phase.max(), -1.05 * phase.max(), 1.05 * phase.max(), -10.0, 10.0);
  prog.setUniformValue("projection", matrice);

  QMatrix4x4 origine(matrice);

  /* Dessine les axes */
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
  glBegin(GL_LINES);                                        // la primitive LINES dessine une ligne par paire de points (n/2 lignes)
  prog.setAttributeValue(SommetId, -1.05 * phase.max(), 0.0, -1.0);        // le -1.0 dans la composante z met les axes en arrière plan
  prog.setAttributeValue(SommetId, 1.05 * phase.max(), 0.0, -1.0);
  prog.setAttributeValue(SommetId, 0.0, -1.05 * phase.max(), -1.0);
  prog.setAttributeValue(SommetId, 0.0, 1.05 * phase.max(), -1.0);
  glEnd();

  // prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);
  glBegin(GL_LINES);
  for (int i = 1; i <= phase.max(); ++i) {
    // matrice.translate(-i, 0.0, 0.0);
    prog.setAttributeValue(SommetId, -i, -0.1, -1.0);
    prog.setAttributeValue(SommetId, -i, 0.1, -1.0);
    // matrice = origine;

    // matrice.translate(i, 0.0, 0.0);
    prog.setAttributeValue(SommetId, i, -0.1, -1.0);
    prog.setAttributeValue(SommetId, i, 0.1, -1.0);
    // matrice = origine;

    // matrice.translate(0.0, -i, 0.0);
    prog.setAttributeValue(SommetId, -0.1, -i, -1.0);
    prog.setAttributeValue(SommetId, 0.1, -i, -1.0);
    // matrice = origine;

    // matrice.translate(0.0, i, 0.0);
    prog.setAttributeValue(SommetId, -0.1, i, -1.0);
    prog.setAttributeValue(SommetId, 0.1, i, -1.0);
    // matrice = origine;
  }
  glEnd();

  // /* Dessine la fonction sinus */
  // prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);
  // glBegin(GL_LINE_STRIP);                                   // la primitive LINE_STRIP ne referme par le tracé (n-1 lignes)
  // double xpas((xmax - xmin) / 128.0); // change l'échantillonage
  //
  // /* Pour x = xmin (gauche de la fenêtre) qui va jusqu'à xmax (droite de la fenêtre)
  //  *  |   On choisi une valeur y = sin(x) et on pose
  //  *
  //  */
  // for (double x(xmin); x <= xmax; x += xpas) {
  //   double y = sin(x);
  //   prog.setAttributeValue(SommetId, x, y, 0.0);
  // }
  // glEnd();

  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);
  glBegin(GL_LINE_STRIP);
  for (auto const& point : phase.pts()){
    prog.setAttributeValue(SommetId, point[0], point[1], 0.0);
  }
  glEnd();

  // matrice.ortho(xmin, xmax, ymin, ymax, 10.0, -10.0);
  // matrice.setToIdentity();
  // prog.setUniformValue("matrice_vue", matrice);
}



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

  // on choisi les couleurs du pendule.
  // la tige est un solide indéformable, alors on lui donne une couleur fixe:
  // vert.
  double rL( 0.1 );
  double vL( 0.8 );
  double bL( 0.0 );

  // la boule est également indéformable, donc on lui donne une couleur fixe:
  // bleu turquoise.
  double rS( 0.1 );
  double vS( 0.8 );
  double bS( 1.0 );

  // et on dessine le pendule
  dessineOscill(pendule, matrice, pendule.L(), pendule.m(), rL, vL, bL, rS, vS, bS);

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
  matrice.rotate(-90, 1.0, 0.0, 0.0);

  // la tige est un solide déformable, alors on lui donne une couleur variable
  // en fonction de sa déformation: jaune à rouge.
  if (debugMode) {
    cout << "Niveau de vert de l'élastique du Ressort -  " << abs(ressort.P(0)) <<  " in [ " << 0.0 << ", " << ressort.getMaxSize() << " ] -> [ " << 0.0 << ", " << 1.0 << " ] : " << 1.0 - mapTo(abs(ressort.P(0)), 0.0, ressort.getMaxSize(), 0.0, 1.0) << endl;
  }
  double rL( 1.0 );
  double vL( 1.0 - mapTo(abs(ressort.P(0)), 0.0, ressort.getMaxSize(), 0.0, 1.0) ); // inversement proportionnel
  double bL( 0.1 );

  // la boule est indéformable, donc on lui donne une couleur fixe:
  // bleu turquoise.
  double rS( 0.1 );
  double vS( 0.8 );
  double bS( 1.0 );

  // et on dessine le ressort
  dessineOscill(ressort, matrice, ressort.P(0), ressort.m(), rL, vL, bL, rS, vS, bS);
}

void VueOpenGL::dessine(Torsion const& torsion)
{
  QMatrix4x4 matrice;

  // on place le point dans le centre de l'écran.
  //matrice.translate(0.0, 0.0, -2.0);

  // on déplace le pendule de Torsion à l'origine.
  matrice.translate(torsion.O(0), torsion.O(1), torsion.O(2));

  // on choisi la couleur de l'axe central, en fonction de la torsion.
  // de jaune à rouge.
  if (debugMode) {
    cout << "Niveau de vert de l'axe central du pendule de torsion -  " << abs(torsion.P(0)) <<  " in [ " << 0.0 << ", " << torsion.getMaxAngle() << " ] -> [ " << 0.0 << ", " << 1.0 << " ] : " << 1.0 - mapTo(abs(torsion.P(0)), 0.0, torsion.getMaxAngle(), 0.0, 1.0) << endl;
  }
  double rA( 1.0 );
  double vA( 1.0 - mapTo(abs(torsion.P(0)), 0.0, torsion.getMaxAngle(), 0.0, 1.0) );
  double bA( 0.1 );

  // on dessine l'axe central
  dessineLigne(matrice, true, 1.0, 0.0, 1.0, 0.0, rA, vA, bA);
  dessineLigne(matrice, true, 1.0, 0.0, -1.0, 0.0, rA, vA, bA);

  // on applique la rotation du pendule.
  matrice.rotate(toDegree(torsion.P(0)), 0.0, 1.0, 0.0);

  // on choisi les couleurs de Torsion.
  // les tige est un solide indéformable, alors on lui donne une couleur fixe:
  // vert.
  double rL( 0.1 );
  double vL( 0.8 );
  double bL( 0 );

  // les boules sont également indéformable, donc on leur donne une couleur fixe:
  // bleu turquoise.
  double rS( 0.1 );
  double vS( 0.8 );
  double bS( 1 );

  // on dessine la 1e partie
  dessineOscill(torsion, matrice, sqrt(torsion.I()), torsion.I(), rL, vL, bL, rS, vS, bS);

  // on inverse le sens
  matrice.scale(-1);

  // on dessine l'autre partie
  dessineOscill(torsion, matrice, sqrt(torsion.I()), torsion.I(), rL, vL, bL, rS, vS, bS);
}

void VueOpenGL::dessine(Chariot const& chariot)
{
  // on créé une matrice
  QMatrix4x4 matrice;

  // on déplace le point pour l'amener à l'origine du chariot
  matrice.translate(chariot.O(0), chariot.O(1), chariot.O(2));

  // on choisi les couleurs du chariot
  // la tige est un solide déformable, alors on lui donne une couleur variable
  // en fonction de sa déformation: jaune à rouge.
  if (debugMode) {
    cout << "Niveau de vert du ressort du chariot -  " << abs(chariot.P(0)) <<  " in [ " << 0 << ", " << chariot.getMaxSize() << " ] -> [ " << 0 << ", " << 1 << " ] : " << 1 - mapTo(abs(chariot.P(0)), 0, chariot.getMaxSize(), 0, 1) << endl;
  }
  double rC( 1.0 );
  double vC( 1.0 - mapTo(abs(chariot.P(0)), 0.0, chariot.getMaxSize(), 0.0, 1.0) ); // inversement proportionnel
  double bC( 0.1 );

  // les boules sont indéformables, donc on leur donne une couleur fixe:
  // bleu turquoise.
  double rS( 0.1 );
  double vS( 0.8 );
  double bS( 1.0 );

  // on dessine le chariot d'abord
  dessineOscill(chariot, matrice, chariot.P(0), chariot.m1(), rC, vC, bC, rS, vS, bS);

  // on se déplace au bout du chariot
  matrice.translate(chariot.P(0)*chariot.a(0), chariot.P(0)*chariot.a(1), chariot.P(0)*chariot.a(2));

  // on applique la rotation actuelle du pendule
  matrice.rotate(toDegree(chariot.P(1)), 0.0, 0.0, 1.0);

  // on fait une rotation de 90 degrés
  matrice.rotate(-90, 0.0, 0.0, 1.0);

  // on choisi une couleur pour les tiges solides du pendule.
  // vert
  double rP( 0.1 );
  double vP( 0.8 );
  double bP( 0.0 );

  //on dessine le pendule
  dessineOscill(chariot, matrice, chariot.L(), chariot.m2(), rP, vP, bP, rS, vS, bS);
}

void VueOpenGL::dessine(PenduleDouble const& pdouble)
{
  // on créé une matrice
  QMatrix4x4 matrice;

  // on déplace le point pour l'amener à l'origine
  matrice.translate(pdouble.O(0), pdouble.O(1), pdouble.O(2));

  // on applique la rotation actuelle du pendule 1
  matrice.rotate(toDegree(pdouble.P(0)), 0.0, 0.0, 1.0);

  // on fait une rotation à 90 degrés pour avoir le pendule à l'angle 0.
  matrice.rotate(-90, 0.0, 0.0, 1.0);

  // on initialise les couleurs.
  double rL( 0.1 );
  double vL( 0.8 );
  double bL( 0.0 );
  double rS( 0.1 );
  double vS( 0.8 );
  double bS( 1.0 );

  // on dessine le premier pendule
  dessineOscill(pdouble, matrice, pdouble.L1(), pdouble.m1(), rL, vL, bL, rS, vS, bS);

  // on se déplace au bout du premier pendule
  matrice.translate(pdouble.L1()*pdouble.a(0), pdouble.L1()*pdouble.a(1), pdouble.L1()*pdouble.a(2));

  // on retire la rotation du premier pendule et on applique la rotation actuelle du pendule 2
  matrice.rotate(toDegree(pdouble.P(1)-pdouble.P(0)), 0.0, 0.0, 1.0);

  // on dessine le deuxième pendule
  dessineOscill(pdouble, matrice, pdouble.L2(), pdouble.m2(), rL, vL, bL, rS, vS, bS);
}


void VueOpenGL::dessine(PenduleRessort const& pr)
{
  QMatrix4x4 matrice;

  matrice.translate(pr.O(0), pr.O(1), pr.O(2));

  // matrice.rotate(toDegree(pr.P()))

  // on choisi les couleurs
  if (debugMode) {
    cout << "Niveau de vert de l'élastique du Pendule-Ressort -  " << abs(pr.P(0)) <<  " in [ " << 0.0 << ", " << pr.getMaxSize() << " ] -> [ " << 0.0 << ", " << 1.0 << " ] : " << 1.0 - mapTo(abs(pr.P(0)), 0.0, pr.getMaxSize(), 0.0, 1.0) << endl;
  }
  double rL( 1.0 );
  double vL( 1.0 - mapTo(abs(pr.P(0)), 0.0, pr.getMaxSize(), 0.0, 1.0) ); // inversement proportionnel
  double bL( 0.1 );
  double rS( 0.1 );
  double vS( 0.8 );
  double bS( 1.0 );

  //dessineOscill(pr, matrice, pr.P(0), pr.m(), rL, vL, bL, rS, vS, bS);

  //on dessine l'axe de l'oscillateur
  // dessineLigne(point_de_vue, true, longueur, osc.a(0), osc.a(1), osc.a(2), rougeL, vertL, bleuL);
  prog.setUniformValue("vue_modele", matrice_vue * matrice);

  glBegin(GL_LINES);
  prog.setAttributeValue(CouleurId, rL, vL, bL);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, pr.P(0), pr.P(1), 0.0);

  glEnd();

  //on se déplace au bout de l'axe
  matrice.translate(pr.P(0), pr.P(1), 0.0);

  //on réduit la taille de la sphère proportionnellement à la racine de la masse de l'oscillateur
  matrice.scale(sqrt(pr.m())/5);

  //on dessine la sphère
  dessineSphere(matrice, rS, vS, bS);
}

void VueOpenGL::dessine(Systeme const& systeme)
{
  // prog.setUniformValue("vue_modele", matrice_vue);

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

  // on désactive l'espace des phases
  _isPhase = false;

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
  if (!_isPhase){
    matrice_vue = translation_supplementaire * matrice_vue;
    memoire = translation_supplementaire * memoire;
  }
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  if (!_isPhase){
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
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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
void VueOpenGL::dessineLigne(QMatrix4x4 const& point_de_vue, bool en_couleur, double longueur, double x, double y, double z, double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);

  if (en_couleur) {
    prog.setAttributeValue(CouleurId, rouge, vert, bleu); // vert
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
void VueOpenGL::dessineOscill(Oscillateur const& osc, QMatrix4x4 point_de_vue, double longueur, double coeff, double rougeL, double vertL, double bleuL, double rougeS, double vertS, double bleuS){

  //on dessine l'axe de l'oscillateur en utilisant sa direction principale a
  dessineLigne(point_de_vue, true, longueur, osc.a(0), osc.a(1), osc.a(2), rougeL, vertL, bleuL);

  //on se déplace au bout de l'axe
  point_de_vue.translate(longueur*osc.a(0), longueur*osc.a(1), longueur*osc.a(2));

  //on réduit la taille de la sphère proportionnellement à la racine de la masse de l'oscillateur
  point_de_vue.scale(sqrt(coeff)/5);

  //on dessine la sphère
  dessineSphere(point_de_vue, rougeS, vertS, bleuS);
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

/*!
 * Fonction qui envoie des valeurs d'un ensemble sur un autre.
 */
double mapTo(double x, double a, double b, double c, double d)
{
  /* On veut envoyer un élément x de [a,b] sur [c,d], proportionnellement. Alors:
   *
   * f(x) = (x-a)/(b-a) * (d-c)+c
   */

   double valeur(0);

   // f(x)
   valeur = (x-a)/(b-a) * (d-c)+c;

   // on règle les cas extrèmes
   if (valeur < c) {
     valeur = c;
   } else if (valeur > d) {
     valeur = d;
   }

  return valeur;
}

void VueOpenGL::togglePhase() {
  _isPhase = !_isPhase;
  cout << "Espace des phases ";
  if (_isPhase) {
    cout << "activé." << endl;
  } else {
    cout << "désactivé." << endl;
  }
}
