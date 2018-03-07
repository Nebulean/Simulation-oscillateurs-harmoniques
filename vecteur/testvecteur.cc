#include "vecteur.h"
#include <vector>
#include <iostream>
using namespace std;

int main(){
  Vecteur vect1;
  Vecteur vect2;
  Vecteur vect3;

  /* Cette partie
   * (1) pourrait être écrite autrement, par exemple avec des
   *     manipulateurs (set_coord) ;
   * (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
   */
  // v1 = (1.0, 2.0, -0.1)
  vect1.augmente(1.0); vect1.augmente(0.0); vect1.augmente(-0.1);
  vect1.set_coord(1, 2.0); // pour tester set_coord()

  // v2 = (2.6, 3.5,  4.1)
  vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);

  vect3 = vect1;

  cout << "Vecteur 1 : ";
  vect1.affiche();
  cout << endl;

  cout << "Vecteur 2 : ";
  vect2.affiche();
  cout << endl;

  cout << "Le vecteur 1 est ";
  if (vect1.compare(vect2)) {
      cout << "égal au";
  } else {
      cout << "différent du";
  }
  cout << " vecteur 2," << endl << "et est ";
  if (not vect1.compare(vect3)) {
      cout << "différent du";
  } else {
      cout << "égal au";
  }
  cout << " vecteur 3." << endl;

  // test d'addition.
  vect3 = vect1.addition(vect2); // vect1 + vect2
  cout << "L'addition de vect1 et vect2 donne: ";
  vect3.affiche();
  cout << endl;

  Vecteur vect0;
  vect0.augmente(0);
  vect0.augmente(0);
  vect0.augmente(0);
  vect3 = vect1.addition(vect0);
  cout << "L'addition de vect1 avec le vecteur nul donne: ";
  vect3.affiche();
  cout << endl;

  Vecteur vect4;
  vect4.augmente(2.0);
  vect4.augmente(3.1);
  // vect3 = vect1.addition(vect4); // vect1 + vect4 //test de l'erreur
  // cout << "L'addition de vect1 et vect4 donne: ";
  // vect3.affiche();
  // cout << endl;

  // test soustraction
  vect3 = vect1.soustraction(vect2);
  cout << "La soustraction de vect1 et vect2 donne: ";
  vect3.affiche();
  cout << endl;

  Vecteur vect5;
  vect5.augmente(1.0);
  vect5.augmente(4.1);
  // vect3 = vect1.soustraction(vect5); //test de l'erreur
  // cout << "La soustraction de vect1 et vect5 donne: ";
  // vect3.affiche();
  // cout << endl;

  vect3 = vect1.soustraction(vect1);
  cout << "La soustraction de vect1 avec lui-même donne: ";
  vect3.affiche();
  cout << endl;

  // test oppose
  Vecteur vect6;
  vect6 = vect1.oppose();
  cout << "L'opposé de vect1 donne: ";
  vect6.affiche();
  cout << endl;

  vect3 = vect1.addition(vect6);
  cout << "L'addition de vect1 avec son opposé donne: ";
  vect3.affiche();
  cout << endl;

  // test exception set_coord
  // vect1.set_coord(5,0);

  // test multiplication
  Vecteur vect7(vect1.mult(3));
  cout << "La multiplication de vect1 par 3 donne: ";
  vect7.affiche();
  cout << endl;

  // test produit scalaire
  // double scalaire;
  // scalaire = vect1.prod_scal(vect4); // test de l'erreur
  // cout << "Produit scalaire erronné entre vect1 et vect4: " << scalaire << endl;
  cout << "Le produit scalaire de vect4 et vect5 donne: " << vect4.prod_scal(vect5) << endl;
  cout << "Le produit scalaire de vect1 et vect2 donne: " << vect1.prod_scal(vect2) << endl;
  cout << endl;

  // test norme et norme2.
  double scal1;
  scal1 = vect1.norme2();
  cout << "La norme au carré de vect1 est " << scal1 << " unités." << endl;
  scal1 = vect1.norme();
  cout << "La norme de vect1 est " << scal1 << " unités." << endl;
  cout << endl;

  double scal2(vect2.norme2());
  cout << "La norme au carré de vect2 est " << scal2 << " unités." << endl;
  scal2 = vect2.norme();
  cout << "La norme de vect2 est " << scal2 << " unités." << endl;
  cout << endl;

  //test produit vectoriel
  Vecteur vect8(vect1.prod_vect(vect2));
  cout << "Le produit vectoriel de vect1 avec vect2 donne: ";
  vect8.affiche();
  cout << endl;
  // Vecteur vect9(vect1.prod_vect(vect4)); // test de l'erreur
  // cout << "Produit vectoriel erronné de vect1 avec vect4: ";
  // vect9.affiche();
  // cout << endl;


  // test constructeur nul.
  cout << "=== TEST CONSTRUCTEURS ===" << endl;
  Vecteur vec1(0);
  Vecteur vec2(12);
  cout << "vec1: ";
  vec1.affiche();
  cout << endl << "vec2: ";
  vec2.affiche();
  cout << endl;

  // test constructeur 3D
  Vecteur  vec3(1,2,3);
  cout << "vec3: ";
  vec3.affiche();
  cout << endl;

  // test constructeur liste d'initialisation
  vector<double> v({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  Vecteur vec4(v);
  cout << "vec4: ";
  vec4.affiche();
  cout << endl;
  vector<double> v2;
  Vecteur vec5(v2);
  cout << "vec5: ";
  vec5.affiche();
  cout << endl;

  return 0;
}
