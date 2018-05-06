# A fAIRE
Corriger question 7s, question 8s.


# Question P1.1
> Comment représentez-vous ces vecteurs ? Comment sont-ils organisés : quels attributs ? quelles méthodes ? quels droits d'accès ?

### Représentation
Les vecteurs de dimension n quelconque (finie) sont représentés par des tableaux dynamiques de réels (vector<double>) de manière à pouvoir changer librement la dimension n au cours du programme.

### Attributs
* *_coord*: il s'agit d'un tableau dynamique contenant à chaque emplacement une coordonnée du vecteur.

### Méthodes
* *void augmente(double)*: ajoute une dimension au vecteur et remplit la case ainsi ajoutée au tableau par un réel fourni;
* *void set_coord(size_t, double)*: prend en paramètre une position dans le tableau et un réel, et modifie la valeur de la coordonnée à cette position en ce réel. De plus, nous avons ajouté une exception pour le cas où la coordonnée entrée est plus grande que la dimension du vecteur;
* *void affiche()*: méthode qui affiche les coordonnées du vecteur dans le style "x1 x2 x3 ..." avec xi les coordonnées du vecteur;
* *bool compare(Vecteur)*: compare les coordonnées de deux vecteurs. Dans un premier temps, elle vérifie que les deux vecteurs ont le même nombre de coordonnées, et si c'est le cas, elle compare les coordonnées des deux vecteurs. Elle retourne *false* si les deux vecteurs sont différents, et *true* si ce sont des vecteurs identiques.
* *size_t dim()*: méthode-outil qui retourne la taille du tableau contenant les coordonnées du vecteur. C'est un raccourci à *_coord.size()*, qui rend le texte beaucoup plus lisible *in fine*.

### Droits d'accès
#### private
*_coord* car c'est un paramètre.

#### public
Toutes les méthodes définies jusqu'à présent car elles sont toutes utilisées directement par l'utilisateur-programmeur.

### Remarques
Nous n'avons pas définit d'assesseur *getVec()*, car nous pouvions nous en passer, **sans compromettre l'encapsulation**. En effet, dans la méthode compare, nous avons besoin d'accéder au membre *_coord* du deuxième vecteur. Mais comme *compare()* est une méthode de la classe *Vecteur*, alors on se trouve encore dans la portée de celle-ci. Ainsi, on a une une variable *privée* accessible dans sa portée.


# Question P1.2
> Quel choix avez vous fait pour les opérations entre vecteurs de dimensions différentes ?

Nous avons choisi de lancer une exception dans chaque méthode sensible à la dimension des vecteurs.


# Question P4.1
> Avez-vous ajouté un constructeur de copie ? Pourquoi (justifiez votre choix) ?

Non. En effet, la copie de surface nous est suffisante, car nous n'avons pas de pointeur. Ainsi, lors de la copie (par défaut), la valeur des attributs est simplement copiée, ce qui nous est amplement suffisant.

# Question P4.2
> Si l'on souhaitait ajouter un constructeur par coordonnées sphériques (deux angles et une longueur) pour les vecteurs de dimension 3
> a) que cela impliquerait-il au niveau des attributs de la classe ?

Cela n'impliquerait rien pour les attributs de la classe puisqu'il suffit de faire une méthode de conversion pour trouver les coordonnées cartésiennes. De plus, l'encapsulation implique que changer les attributs ne devrait en aucun cas changer l'effet des méthodes et des constructeurs.


> b) quelle serait la difficulté majeure (voire l'impossibilité) de sa réalisation en C++ ? (C'est d'ailleurs pour cela qu'on ne vous demande pas de faire un tel constructeur !)

Premièrement, un tel constructeur prendrait en argument trois *double*, exactement comme le constructeur de dimension 3 en coordonnées cartésiennes. Il serait donc impossible en C++ de différencier l'appel à l'un ou l'autre de ces constructeurs, à moins d'ajouter à l'un des constructeurs un argument inutile comme *bool inutile* pour le différencier de l'autre.

Deuxièmement, la conversion des coordonnées sphériques en coordonnées cartésiennes implique d'utiliser sin et cos, qui donneront inévitablement lieu à des arrondis, ce qui pourrait générer une marge d'erreur conséquente.

# Question P4.3
> Quels opérateurs avez vous introduits ?

Nous avons introduit la plupart des opérateurs "classiques" des vecteurs mathématiques, avec quelques compléments:

| prototype | type de surcharge | fonction |
| --- | --- | --- |
| `const Vecteur operator+(Vecteur, Vecteur const&)` | externe | Addition vectorielle. Dépendante d'operator+=. |
| `Vecteur& operator+=(Vecteur const&)` | interne | Opérateur d'auto-affectation de l'addition vectorielle. |
| `const Vecteur operator-(Vecteur, Vecteur const&)` | externe | Soustraction vectorielle. Dépendante d'operator-=. |
| `const Vecteur operator-(Vecteur const&)` | externe | Opérateur de négation. Dépendante d'operator*. |
| `Vecteur& operator-=(Vecteur const&)` | interne | Opérateur d'auto-affection de la soustraction vectorielle. |
| `bool operator==(Vecteur const&) const` | interne | Opérateur testant l'égalité de deux vecteurs. |
| `bool operator!=(Vecteur const&, Vecteur const&)` | externe | Opérateur testant l'inégalité de deux vecteurs. |
| `const Vecteur operator*(double const&, Vecteur);` | externe | Opérateur de multiplication d'un vecteur par un scalaire, avec le scalaire à gauche (Pour v un vecteur et a un scalaire: a*v). Dépend d'operator*=. |
| `double operator*(Vecteur const&, Vecteur const&)` | externe | Opérateur du produit scalaire entre deux vecteurs. |
| `const Vecteur operator*(Vecteur const&, double const&)` | externe | Opérateur de multiplication par un scalaire, avec le scalaire à droite. (Pour v un vecteur et a un scalaire: v*a) |
| `Vecteur& operator*=(double const&)` | interne | Opérateur d'auto-affectation pour la multiplication d'un vecteur par un scalaire. |
| `std::ostream& operator<<(std::ostream&, Vecteur const&)` | externe | Opérateur affichant les coordonnées du vecteur. |
| `const Vecteur operator^(Vecteur const&, Vecteur const&)` | externe | Produit vectoriel. Ne fonctionne que pour les vecteurs de dimension 3. Utilise la méthode prod_scal.|


# Question P6.1
> Comment avez vous conçu votre classe Integrateur ?

La classe Intégrateur ne possède qu'une méthode _evolue_. Elle ne retourne rien, et prend en paramètres une référence sur un oscillateur, le pas de temps (double) et le temps courant (double).
Cette méthode sera substituée dans toutes les sous-classes héritant de celle-ci.

# Question P6.2
> Quelle est la relation entre les classes Integrateur et IntegrateurEulerCromer ?

IntegrateurEulerCromer (notée Eulercromer dans notre projet) **hérite** d'Integrateur. En effet, l'intégrateur de Euler-Cromer **est** un intégrateur. Alors la relation d'héritage s'applique.

# Question P7.1
> Comment se situent ces classes par rapport à la classe Oscillateur définie la semaine passée ?

Pendule et Ressort **héritent** d'Oscillateur. En effet, ce **sont** des oscillateurs, donc de la même manière la relation d'héritage s'applique.

# Question P8.1
> En termes de POO, quelle est donc la nature de la méthode dessine() ?

La méthode dessine est une méthode virtuelle pure. En effet, dans la classe Dessinable, elle ne représente "rien", vu qu'on ne sait pas comment dessiner un Dessinable. Cependant, si l'on fait hériter Dessinable, à un oscillateur par exemple, alors elle prend son sens. Celle-ci de dessiner cet oscillateur (qui est un dessinable.)
Ainsi, avec cette méthode et le polymorphisme, on a une version unifiée pour dessiner des objets.

# Question P8.2
> Quelle est la bonne façon de le faire dans un cadre de programmation orientée-objet ?

Il s'agit d'une collection hétérogène ! On a donc une collection (vector) d'éléments qui sont un pointeur sur un Oscillateur. Ainsi, comme les différentes classes comme Pendule, ou autre **sont** des oscillateur, et que l'on utilise des pointeurs, alors le polymorphisme entre en jeu.

# Question P8.3
> A quoi faut-il faire attention pour les classes contenant des pointeurs ? Quelles solutions peut-on envisager ?

Il faut faire attention à plusieurs éléments.
* Le **constructeur de copie**: il faut le redéfinir, car si une instance est la copie d'une autre, elle doit réallouer de nouvelles cases mémoires pour les paramètres. Il faut pour cela implémenter une copie profonde.
* Le **destructeur**: Il faut penser à désallouer les pointeurs lorsqu'ils sont en fin de vie.
* IL Y A UN TROISIEME TRUC, NON ?

# Question P8.4
> Comment représentez vous la classe Systeme ? Expliquez votre conception (attributs, interface, ...).

La classe Systeme contient une une collection hétérogène d'oscillateurs. C'est dans ce tableau que seront stockés tous les oscillateurs du système. Elle contient également deux attributs double: le temps courant et le pas de temps. Ces deux sont des variables utilisées dans tous le projet, et pour simplifier le tout, elles se situent dans l'instance de Systeme.
Au niveau des méthodes [A REMPLIR]
