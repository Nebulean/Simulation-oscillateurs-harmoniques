// Ce fichier provient (pouvant être modifié) du cours d'informatique pour physiciens et mathématiciens de l'EPFL.
// Lien: https://progmaph.epfl.ch/

attribute vec3 sommet;
attribute vec3 couleur;

uniform mat4 projection;
uniform mat4 vue_modele;

varying vec3 ma_couleur;

void main()
{
  gl_Position = projection * vue_modele * vec4(sommet, 1.0);
  ma_couleur = couleur;
}
