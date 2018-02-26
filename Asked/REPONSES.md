# Question P1.1
*Comment représentez-vous ces vecteurs ? Comment sont-ils organisés : quels attributs ? quelles méthodes ? quels droits d'accès ?*

### Représentation
Les vecteurs de dimension n quelconque (finie) sont représentés par des tableaux dynamiques de réels (vector<double>) de manière à pouvoir changer librement la dimension n au cours du programme.

### Attributs
* *_coord*: il s'agit d'un tableau dynamique contenant à chaque emplacement une coordonnée du vecteur.

### Méthodes
* *void augmente(double)*: ajoute une dimension au vecteur et remplit la case ainsi ajoutée au tableau par un réel fourni;
* *void set_coord(size_t, double)*: prend en paramètre une position dans le tableau et un réel, et modifie la valeur de la coordonnée à cette position en ce réel;
* *void affiche()*: méthode qui affiche les coordonnées du vecteur dans le style "x1 x2 x3 ..." avec xi les coordonnées du vecteur;
* *bool compare(Vecteur)*: compare les coordonnées de deux vecteurs. Dans un premier temps, elle vérifie que les deux vecteurs ont le même nombre de coordonnées, et si c'est le cas, elle compare les coordonnées des deux vecteurs. Elle retourne *false* si les deux vecteurs sont différents, et *true* si ce sont des vecteurs identiques.

### Droits d'accès
#### private
*_coord* car c'est un paramètre

#### public
Toutes les méthodes définies jusqu'à présent car elles sont toutes utilisées directement par l'utilisateur-programmeur.

### Remarques
Nous n'avons pas définit d'assesseur *getVec()*, car nous pouvions nous en passer, **sans compromettre l'encapsulation**. En effet, dans la méthode compare, nous avons besoin d'accéder au membre *_coord* du deuxième vecteur. Mais comme *compare()* est une méthode de la classe *Vecteur*, alors on se trouve encore dans la portée de celle-ci. Ainsi, on a une une variable *privée* accessible dans sa portée.
