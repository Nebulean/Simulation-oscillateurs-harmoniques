#include "vecteur.h"
#include <vector>
#include <iostream>
using namespace std;

int main(){
  /* Cette partie du code contient les tests ajoutés dès la semaine 4.
   * Elle est la version fonctionnelle.
   * L'ancienne version se trouve en bas de page.
   */

  // un vecteur en 3D :
  Vecteur vect1(1.0, 2.0, -0.1);

  // un autre vecteur en 3D
  Vecteur vect2(2.6, 3.5,  4.1);

  Vecteur vect3(vect1);  // copie de V1
  Vecteur vect4(4);      // le vecteur nul en 4D

  cout << "Vecteur 1 : " << vect1 << endl;
  cout << "Vecteur 2 : " << vect2 << endl;
  cout << "Vecteur 4 : " << vect4 << endl;

  cout << "Le vecteur 1 est ";
  if (vect1 == vect2) {
      cout << "égal au";
  } else {
      cout << "différent du";
  }
  cout << " vecteur 2," << endl << "et est ";
  if (vect1 != vect3) {
      cout << "différent du";
  } else {
      cout << "égal au";
  }
  cout << " vecteur 3." << endl;

  // test augmente()
  cout << "=== TEST AUGMENTE ===" << endl;
  Vecteur vect5;
  vect5.augmente(2.0);
  vect5.augmente(3.1);
  cout << "Vecteur 5: " << vect5 << endl << endl;

  // test addition
  cout << "( " << vect1 << ") + ( " << vect2 << ") = " << "( " << vect1 + vect2 << ")" << endl;
  cout << "( " << vect2 << ") + ( " << vect1 << ") = " << "( " << vect2 + vect1 << ")" << endl;

  // test addition du vecteur nul.
  Vecteur vect0(3); // création du vecteur nul de dimension 3.
  cout << "( " << vect1 << ") + ( " << vect0 << ") = " << "( " << vect1 + vect0 << ")" << endl;
  cout << "( " << vect0 << ") + ( " << vect1 << ") = " << "( " << vect0 + vect1 << ")" << endl;


  // test soustraction
  cout << "( " << vect1 << ") - ( " << vect2 << ") = " << "( " << vect1 - vect2 << ")" << endl;
  cout << "( " << vect2 << ") - ( " << vect1 << ") = " << "( " << vect2 - vect1 << ")" << endl;

  // soustraction du même vecteur
  cout << "( " << vect2 << ") - ( " << vect2 << ") = " << "( " << vect2 - vect2 << ")" << endl;


  // Vecteur vect5({1.0, 4.1}) //test de l'erreur ********* NE PAS EFFACER NE PAS EFFACER *********
  // cout << "La soustraction de vect1 et vect5 donne: " << vect1 - vect5 << endl;

  // test oppose
  cout << "-( " << vect1 << ") = ( " << -vect1 << ")" << endl;

  cout << "( " << vect1 << ") + -( " << vect1 << ") = " << "( " << vect1 + -vect1 << ")" << endl;

  cout << "-( " << vect2 << ") + ( " << vect1 << ") = ( " << -vect2 + vect1 << ")" << endl;


  // test multiplication par un scalaire
  cout << "3 * ( " << vect1 << ") = ( " << 3 * vect1 << ")" << endl;
  cout << "( " << vect1 << ") * 3 = ( " << vect1 * 3 << ")" << endl;

  // test produit scalaire
  cout << "( " << vect1 << ") * ( " << vect2 << ") = ( " << vect1 * vect2 << ")" << endl;
  cout << "( " << vect2 << ") * ( " << vect1 << ") = ( " << vect2 * vect1 << ")" << endl;

  // test produit vectoriel
  cout << "( " << vect1 << ") ^ ( " << vect2 << ") = ( " << (vect1 ^ vect2) << ")" << endl; // Il faut utiliser les ( ), parce que ^ n'a pas la même priorité des opérations.
  cout << "( " << vect2 << ") ^ ( " << vect1 << ") = ( " << (vect2 ^ vect1) << ")" << endl;

  // test norme
  cout << "||( " << vect1 << ")||^2 = " << vect1.norme2() << endl;
  cout << "||( " << vect2 << ")||^2 = " << vect2.norme2() << endl;
  cout << "||( " << vect1 << ")|| = " << vect1.norme() << endl;
  cout << "||( " << vect2 << ")|| = " << vect2.norme() << endl;

  // test exception set_coord
  // vect1.set_coord(5,0);

  // test multiplication
  // Vecteur vect7(vect1.mult(3));
  // cout << "La multiplication de vect1 par 3 donne: ";
  // vect7.affiche();
  // cout << endl;

  // test produit scalaire
  // double scalaire;
  // scalaire = vect1.prod_scal(vect4); // test de l'erreur
  // cout << "Produit scalaire erronné entre vect1 et vect4: " << scalaire << endl;
  // cout << "Le produit scalaire de vect4 et vect5 donne: " << vect4.prod_scal(vect5) << endl;
  // cout << "Le produit scalaire de vect1 et vect2 donne: " << vect1.prod_scal(vect2) << endl;
  // cout << endl;

  cout << endl << "========== TESTS SUPPLEMENTAIRES ==========" << endl << endl;


  // test norme et norme2.
  // cout << "=== TEST DES NO1RMES ===" << endl;
  // double scal1;
  // scal1 = vect1.norme2();
  // cout << "La norme au carré de vect1 est " << vect1.norme2() << " unités." << endl;
  // scal1 = vect1.norme();
  // cout << "La norme de vect1 est " << vect1.norme() << " unités." << endl;
  // double scal2(vect2.norme2());
  // cout << "La norme au carré de vect2 est " << vect2.norme2() << " unités." << endl;
  // scal2 = vect2.norme();
  // cout << "La norme de vect2 est " << vect2.norme2() << " unités." << endl << endl;
  // cout << endl;

  //test produit vectoriel
  // Vecteur vect8(vect1.prod_vect(vect2));
  // cout << "Le produit vectoriel de vect1 avec vect2 donne: ";
  // vect8.affiche();
  // cout << endl;
  // Vecteur vect9(vect1.prod_vect(vect4)); // test de l'erreur
  // cout << "Produit vectoriel erronné de vect1 avec vect4: ";
  // vect9.affiche();
  // cout << endl;


  // test constructeur nul.
  cout << "=== TEST CONSTRUCTEURS ===" << endl;
  Vecteur vec1(0);
  Vecteur vec2(12);
  cout << "vec1: " << vec1 << endl << "vec2: " << vec2 << endl;

  // test constructeur 3D
  Vecteur  vec3(1,2,3);
  cout << "vec3: " << vec3 << endl;
  // vec3.affiche();
  // cout << endl;

  // test constructeur avec vector         // vieux constructeur
  // vector<double> v1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  // Vecteur vec4(v1);
  // cout << "vec4: ";
  // vec4.affiche();
  // cout << endl;
  // vector<double> v2;
  // Vecteur vec5(v2);
  // cout << "vec5: ";
  // vec5.affiche();
  // cout << endl;

  // test constructeur avec initializer_list
  Vecteur vec6({1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1});
  cout << "vec6: " << vec6 << endl << endl;

  cout << "=== TEST SURCHARGES ===" << endl;

  // test de operator<<
  Vecteur ve1({1, 2, 3, 4, 5});
  cout << "ve1: " << ve1 << endl;

  // test de operator==
  // vector<double> v4({1, 2, 3, 4}); // vieux constructeur
  // vector<double> v5(v4);
  Vecteur ve2({1, 2, 3, 4});
  Vecteur ve3(ve2); // test du constructeur de copie par défaut
  cout << "ve2 et ve3 sont ";
  if (ve2 == ve3) {
    cout << "égaux" << endl;
  } else {
    cout << "différents" << endl;
  }
  cout << "ve1 et ve2 sont ";
  if (ve1 == ve2) {
    cout << "égaux" << endl;
  } else {
    cout << "différents" << endl;
  }

  // test de operator!=
  cout << "ve2 et ve3 sont ";
  if (ve2 != ve3) {
    cout << "différents" << endl;
  } else {
    cout << "égaux" << endl;
  }

  // Vecteur v6({1,2,3,4});
  // Vecteur v7({1,1,1,1});
  // cout << "v6 + v7 = " << v6 + v7 << endl;
  // v6 += v7;
  // cout << "v6 += v7: " << v6 << endl;

  // test des operator*
  // double a(5);
  Vecteur v8({1,1,1,1,1,1});
  cout << "3 * v8 = " << 3*v8 << endl;
  cout << "v8 * 4 = " << v8*4 << endl;
  v8 *= 5;
  cout << "v8 final = " << v8 << endl;
  Vecteur v9({1,2,3,4,5,6});
  cout << "Produit scalaire v8*v9 = " << v8*v9 << endl;
  // v8*v7; // test de lancement d'exception

  // test de operator-
  Vecteur v10({1,2,3,4});
  Vecteur v11({0,1,1,1});
  cout << "v10 - v11 = " << v10 - v11 << endl;
  v10 -= v11;
  cout << "v10 -= v11: " << v10 << endl;
  cout << "-v11 = " << -v11 << endl;

  // test de operator^
  Vecteur v12({1,0,0});
  Vecteur v13({0,1,0});
  // cout << "v10 ^ v13 = " << (v10 ^ v13) << endl; // test de l'erreur
  cout << "v12 ^ v13 = " << (v12 ^ v13) << endl;

  // ancienne version
  // Vecteur vect1;
  // Vecteur vect2;
  // Vecteur vect3;
  //
  // // v1 = (1.0, 2.0, -0.1)
  // vect1.augmente(1.0); vect1.augmente(0.0); vect1.augmente(-0.1);
  // vect1.set_coord(1, 2.0); // pour tester set_coord()
  //
  // // v2 = (2.6, 3.5,  4.1)
  // vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);
  //
  // vect3 = vect1;
  //
  // cout << "Vecteur 1 : ";
  // vect1.affiche();
  // cout << endl;
  //
  // cout << "Vecteur 2 : ";
  // vect2.affiche();
  // cout << endl;
  //
  // cout << "Le vecteur 1 est ";
  // if (vect1.compare(vect2)) {
  //     cout << "égal au";
  // } else {
  //     cout << "différent du";
  // }
  // cout << " vecteur 2," << endl << "et est ";
  // if (not vect1.compare(vect3)) {
  //     cout << "différent du";
  // } else {
  //     cout << "égal au";
  // }
  // cout << " vecteur 3." << endl;
  //
  // // test d'addition.
  // vect3 = vect1.addition(vect2); // vect1 + vect2
  // cout << "L'addition de vect1 et vect2 donne: ";
  // vect3.affiche();
  // cout << endl;
  //
  // Vecteur vect0;
  // vect0.augmente(0);
  // vect0.augmente(0);
  // vect0.augmente(0);
  // vect3 = vect1.addition(vect0);
  // cout << "L'addition de vect1 avec le vecteur nul donne: ";
  // vect3.affiche();
  // cout << endl;
  //
  // Vecteur vect4;
  // vect4.augmente(2.0);
  // vect4.augmente(3.1);
  // // vect3 = vect1.addition(vect4); // vect1 + vect4 //test de l'erreur
  // // cout << "L'addition de vect1 et vect4 donne: ";
  // // vect3.affiche();
  // // cout << endl;
  //
  // // test soustraction
  // vect3 = vect1.soustraction(vect2);
  // cout << "La soustraction de vect1 et vect2 donne: ";
  // vect3.affiche();
  // cout << endl;
  //
  // Vecteur vect5;
  // vect5.augmente(1.0);
  // vect5.augmente(4.1);
  // // vect3 = vect1.soustraction(vect5); //test de l'erreur
  // // cout << "La soustraction de vect1 et vect5 donne: ";
  // // vect3.affiche();
  // // cout << endl;
  //
  // vect3 = vect1.soustraction(vect1);
  // cout << "La soustraction de vect1 avec lui-même donne: ";
  // vect3.affiche();
  // cout << endl;
  //
  // // test oppose
  // Vecteur vect6;
  // vect6 = vect1.oppose();
  // cout << "L'opposé de vect1 donne: ";
  // vect6.affiche();
  // cout << endl;
  //
  // vect3 = vect1.addition(vect6);
  // cout << "L'addition de vect1 avec son opposé donne: ";
  // vect3.affiche();
  // cout << endl;
  //
  // // test exception set_coord
  // // vect1.set_coord(5,0);
  //
  // // test multiplication
  // Vecteur vect7(vect1.mult(3));
  // cout << "La multiplication de vect1 par 3 donne: ";
  // vect7.affiche();
  // cout << endl;
  //
  // // test produit scalaire
  // // double scalaire;
  // // scalaire = vect1.prod_scal(vect4); // test de l'erreur
  // // cout << "Produit scalaire erronné entre vect1 et vect4: " << scalaire << endl;
  // cout << "Le produit scalaire de vect4 et vect5 donne: " << vect4.prod_scal(vect5) << endl;
  // cout << "Le produit scalaire de vect1 et vect2 donne: " << vect1.prod_scal(vect2) << endl;
  // cout << endl;
  //
  // // test norme et norme2.
  // double scal1;
  // scal1 = vect1.norme2();
  // cout << "La norme au carré de vect1 est " << scal1 << " unités." << endl;
  // scal1 = vect1.norme();
  // cout << "La norme de vect1 est " << scal1 << " unités." << endl;
  // cout << endl;
  //
  // double scal2(vect2.norme2());
  // cout << "La norme au carré de vect2 est " << scal2 << " unités." << endl;
  // scal2 = vect2.norme();
  // cout << "La norme de vect2 est " << scal2 << " unités." << endl;
  // cout << endl;
  //
  // //test produit vectoriel
  // Vecteur vect8(vect1.prod_vect(vect2));
  // cout << "Le produit vectoriel de vect1 avec vect2 donne: ";
  // vect8.affiche();
  // cout << endl;
  // // Vecteur vect9(vect1.prod_vect(vect4)); // test de l'erreur
  // // cout << "Produit vectoriel erronné de vect1 avec vect4: ";
  // // vect9.affiche();
  // // cout << endl;
  //
  //
  // // test constructeur nul.
  // cout << "=== TEST CONSTRUCTEURS ===" << endl;
  // Vecteur vec1(0);
  // Vecteur vec2(12);
  // cout << "vec1: ";
  // vec1.affiche();
  // cout << endl << "vec2: ";
  // vec2.affiche();
  // cout << endl;
  //
  // // test constructeur 3D
  // Vecteur  vec3(1,2,3);
  // cout << "vec3: ";
  // vec3.affiche();
  // cout << endl;
  //
  // // test constructeur avec vector         // vieux constructeur
  // // vector<double> v1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  // // Vecteur vec4(v1);
  // // cout << "vec4: ";
  // // vec4.affiche();
  // // cout << endl;
  // // vector<double> v2;
  // // Vecteur vec5(v2);
  // // cout << "vec5: ";
  // // vec5.affiche();
  // // cout << endl;
  //
  // // test constructeur initializer_list
  // Vecteur vec6({1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1});
  // cout << "vec6: " << vec6 << endl;
  //
  // cout << "=== TEST SURCHARGES ===" << endl;
  //
  // // test de operator<<
  // Vecteur ve1({1, 2, 3, 4, 5});
  // cout << "ve1: " << ve1 << endl;
  //
  // // test de operator==
  // // vector<double> v4({1, 2, 3, 4}); // vieux constructeur
  // // vector<double> v5(v4);
  // Vecteur ve2({1, 2, 3, 4});
  // Vecteur ve3(ve2); // test du constructeur de copie par défaut
  // cout << "ve2 et ve3 sont ";
  // if (ve2 == ve3) {
  //   cout << "égaux" << endl;
  // } else {
  //   cout << "différents" << endl;
  // }
  // cout << "ve1 et ve2 sont ";
  // if (ve1 == ve2) {
  //   cout << "égaux" << endl;
  // } else {
  //   cout << "différents" << endl;
  // }
  //
  // // test de operator!=
  // cout << "ve2 et ve3 sont ";
  // if (ve2 != ve3) {
  //   cout << "différents" << endl;
  // } else {
  //   cout << "égaux" << endl;
  // }
  //
  // // test de operator+
  // Vecteur v6({1,2,3,4});
  // Vecteur v7({1,1,1,1});
  // cout << "v6 + v7 = " << v6 + v7 << endl;
  // v6 += v7;
  // cout << "v6 += v7: " << v6 << endl;
  //
  // // test des operator*
  // // double a(5);
  // Vecteur v8({1,1,1,1,1,1});
  // cout << "3 * v8 = " << 3*v8 << endl;
  // cout << "v8 * 4 = " << v8*4 << endl;
  // v8 *= 5;
  // cout << "v8 final = " << v8 << endl;
  // Vecteur v9({1,2,3,4,5,6});
  // cout << "Produit scalaire v8*v9 = " << v8*v9 << endl;
  // // v8*v7; // test de lancement d'exception
  //
  // // test de operator-
  // Vecteur v10({1,2,3,4});
  // Vecteur v11({0,1,1,1});
  // cout << "v10 - v11 = " << v10 - v11 << endl;
  // v10 -= v11;
  // cout << "v10 -= v11: " << v10 << endl;
  // cout << "-v11 = " << -v11 << endl;
  //
  // // test de operator^
  // Vecteur v12({1,0,0});
  // Vecteur v13({0,1,0});
  // // cout << "v10 ^ v13 = " << (v10 ^ v13) << endl; // test de l'erreur
  // cout << "v12 ^ v13 = " << (v12 ^ v13) << endl;


  return 0;
}
