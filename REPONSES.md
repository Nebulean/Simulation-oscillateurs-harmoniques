<!-- Ce document est en format Markdown, et utilise latex pour le rendu de quelques éléments. Pour le lire, veuillez vous procurer un bon lecteur markdown, ou de lire le PDF associé. -->

# Question P1.1
> _Comment représentez-vous ces vecteurs ? Comment sont-ils organisés : quels attributs ? quelles méthodes ? quels droits d'accès ?_

### Représentation
Les vecteurs de dimension n quelconque (finie) sont représentés par des tableaux dynamiques de réels (vector<double>) de manière à pouvoir changer librement la dimension n au cours du programme.

### Attributs

* _*coord*: il s'agit d'un tableau dynamique contenant à chaque emplacement une coordonnée du vecteur.

### Méthodes
* *void augmente(double)*: ajoute une dimension au vecteur et remplit la case ainsi ajoutée au tableau par un réel fourni;
* *void set_coord(size_t, double)*: prend en paramètre une position dans le tableau et un réel, et modifie la valeur de la coordonnée à cette position en ce réel. De plus, nous avons ajouté une exception pour le cas où la coordonnée entrée est plus grande que la dimension du vecteur;
* *void affiche()*: méthode qui affiche les coordonnées du vecteur dans le style "x1 x2 x3 ..." avec xi les coordonnées du vecteur;
* *bool compare(Vecteur)*: compare les coordonnées de deux vecteurs. Dans un premier temps, elle vérifie que les deux vecteurs ont le même nombre de coordonnées, et si c'est le cas, elle compare les coordonnées des deux vecteurs. Elle retourne *false* si les deux vecteurs sont différents, et *true* si ce sont des vecteurs identiques.
* *size_t dim()*: méthode-outil qui retourne la taille du tableau contenant les coordonnées du vecteur. C'est un raccourci à *_coord.size()*, qui rend le texte beaucoup plus lisible *in fine*.

### Droits d'accès
#### private

_*coord* car c'est un attribut.

#### public
Toutes les méthodes définies jusqu'à présent car elles sont toutes utilisées directement par l'utilisateur-programmeur.

### Remarques
Nous n'avons pas définit d'assesseur *getVec()*, car nous pouvions nous en passer, **sans compromettre l'encapsulation**. En effet, dans la méthode compare, nous avons besoin d'accéder au membre _*coord* du deuxième vecteur. Mais comme *compare()* est une méthode de la classe *Vecteur*, alors on se trouve encore dans la portée de celle-ci. Ainsi, on a une une variable *privée* accessible dans sa portée.


# Question P1.2
> _Quel choix avez vous fait pour les opérations entre vecteurs de dimensions différentes ?_

Nous avons choisi de lancer une exception dans chaque méthode sensible à la dimension des vecteurs.


# Question P4.1
> _Avez-vous ajouté un constructeur de copie ? Pourquoi (justifiez votre choix) ?_

Non. En effet, la copie de surface nous est suffisante, car nous n'avons pas de pointeur. Ainsi, lors de la copie (par défaut), la valeur des attributs est simplement copiée, ce qui nous est amplement suffisant.

# Question P4.2
> _Si l'on souhaitait ajouter un constructeur par coordonnées sphériques (deux angles et une longueur) pour les vecteurs de dimension 3_
> a) _que cela impliquerait-il au niveau des attributs de la classe ?_

Cela n'impliquerait rien pour les attributs de la classe puisqu'il suffit de faire une méthode de conversion pour trouver les coordonnées cartésiennes. De plus, l'encapsulation implique que changer les attributs ne devrait en aucun cas changer l'effet des méthodes et des constructeurs.


> b) _quelle serait la difficulté majeure (voire l'impossibilité) de sa réalisation en C++ ? (C'est d'ailleurs pour cela qu'on ne vous demande pas de faire un tel constructeur !)_

Premièrement, un tel constructeur prendrait en argument trois *double*, exactement comme le constructeur de dimension 3 en coordonnées cartésiennes. Il serait donc impossible en C++ de différencier l'appel à l'un ou l'autre de ces constructeurs, à moins d'ajouter à l'un des constructeurs un argument inutile comme *bool inutile* pour le différencier de l'autre.

Deuxièmement, la conversion des coordonnées sphériques en coordonnées cartésiennes implique d'utiliser sin et cos, qui donneront inévitablement lieu à des arrondis, ce qui pourrait générer une marge d'erreur conséquente.

# Question P4.3
> _Quels opérateurs avez vous introduits ?_

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
> _Comment avez vous conçu votre classe Integrateur ?_

La classe Intégrateur possède une méthode _evolue_ qui est public. Elle ne retourne rien, et prend en paramètres une référence sur un oscillateur, le pas de temps (double) et le temps courant (double).
Cette méthode sera substituée dans toutes les sous-classes héritant de celle-ci.  Nous avons également le destructeur virtuel qui est vide.

# Question P6.2

> _Quelle est la relation entre les classes Integrateur et IntegrateurEulerCromer ?_

IntegrateurEulerCromer (notée Eulercromer dans notre projet) **hérite** d'Integrateur. En effet, l'intégrateur de Euler-Cromer **est** un intégrateur. Alors la relation d'héritage s'applique.

# Question P7.1
> _Comment se situent ces classes par rapport à la classe Oscillateur définie la semaine passée ?_

Pendule et Ressort **héritent** d'Oscillateur. En effet, ce **sont** des oscillateurs, donc de la même manière la relation d'héritage s'applique. Ainsi, Pendule et Ressort ont un caneva de base qui est Oscillateur, et cela évite de ré-écrire plein de code ou d'en oublier une partie qui doit être implémenté à tout pris pour utiliser le polymorphisme (Dans la collection hétérogène de système nottament).

# Question P8.1
> _En termes de POO, quelle est donc la nature de la méthode dessine() ?_

La méthode dessine est une méthode **virtuelle pure**. En effet, dans la classe Dessinable, elle ne représente "rien", vu qu'on ne sait pas comment dessiner un Dessinable. Cependant, si l'on fait hériter Dessinable, à un oscillateur par exemple, alors elle prend pleinement son sens: dessiner cet oscillateur (qui est un dessinable.)
Ainsi, avec cette méthode et du polymorphisme, on a une version unifiée pour dessiner des objets.

# Question P8.2
> _Quelle est la bonne façon de le faire dans un cadre de programmation orientée-objet ?_

Il s'agit d'une collection hétérogène. On a donc une collection (vector dans notre cas) d'éléments qui sont des pointeurs sur Oscillateur. Ainsi, vu que les classes comme Pendule, ou autre **sont** des oscillateur, et que l'on utilise des pointeurs, alors le polymorphisme entre en jeu.

# Question P8.3
> _A quoi faut-il faire attention pour les classes contenant des pointeurs ? Quelles solutions peut-on envisager ?_

Il faut faire attention à plusieurs éléments.



* Le **constructeur de copie**: il faut le redéfinir, car si une instance est la copie d'une autre, elle doit réallouer de nouvelles cases mémoires pour les paramètres. Il faut pour cela implémenter une copie profonde;
* L'**opérateur d'affectation operator=**, qui est très lié au constructeur de copie et doit par conséquent aussi être redéfini pour faire une copie profonde;
* Le **destructeur**: Il faut penser à désallouer les pointeurs lorsqu'ils sont en fin de vie.

Pour nous éviter tous ces problèmes, nous avons cependant choisi d'utiliser des unique_ptr, des smart pointers qui se désallouent d'eux-même quand c'est nécessaire et ne permettent pas la copie.

# Question P8.4
> _Comment représentez vous la classe Systeme ? Expliquez votre conception (attributs, interface, …)._

La classe Systeme contient une collection hétérogène d'oscillateurs (vector). C'est dans ce tableau que seront stockés tous les oscillateurs du système. Elle contient également deux attributs double: le temps courant et le pas de temps. Ces deux sont des variables utilisées dans tous le projet, et pour simplifier le tout, elles se situent dans l'instance de Systeme. De plus, elle contient un pointeur sur un Integrateur, qui est utilisé pour faire évoluer le système.
Au niveau des méthodes, nous avons défini en plus de la méthode dessine():



* temps(), un accesseur pour pouvoir afficher le temps courant du système;
* ajoute(Oscillateur) qui permet d'ajouter un oscillateur à la collection hétérogène;
* evolue() qui fait évoluer le système d'un pas de temps;
* affiche(ostream&), une méthode d'affichage textuel polymorphique qui permet d'utiliser operator<<, défini pour toutes les classes Dessinable.

**Correctif du 27 mai 2018.**

La méthode Systeme a beaucoup évolué depuis, afin d'adapter nos besoins. Nous ne décriverons pas toutes les méthodes utilisées pour les graphismes (se référer à la documentation ou au code), mais juste le changement majeur pour la réponse ci-dessus. 

La méthode *ajoute(Oscillateur)* a été remplacée par une surcharge de l'opérateur +=. Il est donc très facile d'ajouter un oscillateur au système.

# Question P11.1
> _Comment représentez-vous ces nouveaux oscillateurs ? Où s'inscrivent-ils dans votre conception ?_

Comme les oscillateurs couplés sont des combinaisons d'oscillateurs existants, la tentation est de les faire hériter de plusieurs sous-classes d'oscillateurs. Cependant, un oscillateur couplé composé d'une partie ressort et d'une partie pendule par exemple, n'**est pas** un ressort **et** un pendule en même temps. C'est un composé des deux, avec ses propres attributs et propriétés. Nous avons donc décidé de les faire hériter d'Oscillateur uniquement. Ils ont donc le même statut que les oscillateurs simples.

# Question P12.1
> _Comment implémentez-vous la possibilité de tracer les trajectoires dans l'espace des phases ?_

Nous considérons ici l'espace des phases comme un objet dessinable. Nous avons donc créé une classe Phase héritant de Dessinable, afin de pouvoir l'afficher en mode texte ou graphique. Nous avons ajouté à chaque Oscillateur un attribut de type Phase* afin d'associer chaque espace des phases à un oscillateur spécifique.

Phase stock chaque point de l'oscillateur dans une liste chainée de tableau à la C de taille 2. Ainsi, nous avons la faible complexité ($\mathcal{O}(1)$) de l'ajout d'un élément à la liste chainée, en comparaison des tableaux dynamiques ($\mathcal{O}(n)$). Puis, il nous reste qu'à dessiner et relier les points à chaque frame.

# Question P13.1
> _Où cela s'intègre-t-il dans votre projet/conception ? Quels changements cela engendre ?_

Pour implémenter ce changement d'intégrateur, nous avons procédé de la sorte. Les touches $1$, $2$ et $3$ du clavier agissent comme une sélection d'integrateur. Nous avons ajouté une variable d'état dans GLWidget qui garde en mémoire l'intégrateur actuel (ID) (il s'agit d'un int tout simplement). Lorsque l'on appuie sur une de ces touches, on suit cela:



1. On copie le pointeur sur l'intégrateur actuellement utilisé dans une variable temporaire.
2. On alloue dynamiquement le nouvel intégrateur voulu, et on l'applique dans le pointeur sur intégrateur de GLWidgets.
3. On applique le changement d'intégrateur au système à l'aide d'une méthode celle-ci.
4. On change l'ID de l'intégrateur actuel avec celui du nouveau.
5. On désalloue la variable temporaire que l'on avait créé auparavant.

De cette manière nous pouvons avoir un changement d'intégrateur pendant l'execution, de manière transparente.
