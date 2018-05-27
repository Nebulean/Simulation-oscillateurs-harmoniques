## Semaine 1
### Travail accompli
Cette première semaine, nous avons surtout organisé le projet.

* Nous avons choisi d'utiliser GIT pour la communication du projet, et la centralisation des données.
* Nous avons également choisi d'utiliser doxygen pour créer automatiquement le graphique de CONCEPTION.
* Nous avons aussi réfléchi à la question: "Quand travailler sur le projet".

En bref: C'est la semaine organisation.

### Problèmes rencontrés
Aucun, tout se passe bien pour le moment, et nous sommes enthousiastes.

## Semaine 2
### Travail accompli
Nous avons réalisé la première version de la classe Vecteur, avec toutes les méthodes demandées.
Au niveau des méthodes réalisées, nous avons donc:

* Toutes les opérations mathématiques classiques.
* Quelques méthodes-outil.
En même temps, nous avons réalisé tous les tests demandés dans le cours.

En bref: La première version de la classe Vecteur est finie.

### Problèmes rencontrés
Nous avons eu quelques questions de conception, des question principalement liée à "Est-ce que c'est bien de faire X de la manière Y".
Nous avons également eu un problème avec les exceptions en c++. Nos souvenirs sur le cours à ce sujet, qui date d'il y a plus d'un an pour nous, n'étaient plus très frais , et les réponses données sur internet ne sont guère suffisantes. La solution est donc de relire le cours sur les exceptions.

## Semaine 3
### Travail accompli
Cette semaine, nous avons avancé les constructeurs demandés et fait la surcharge de certains des opérateurs. Nous avons aussi ajouté quelques méthodes-outils.

### Problèmes rencontrés
Comme la semaine précédente, nous avons eu quelques questions de conception, qui étaient facilement résolubles.


## Semaine 4
### Travail accompli
Nous avons créé les constructeurs restants et modifié le fichier test comme demandé. Nous avons tous deux opté de nous concentrer sur les autres branches cette semaine donc nous n'avons pas beaucoup avancé le projet. Néanmoins notre avance nous a permis d'éviter de prendre du retard.

### Problèmes rencontrés
De simples questions de conception et quelques questions organisationnelles.

## Semaine 5
### Travail accompli
Cette semaine, nous avons bien avancé dans le projet. Nous avons séparé le travail en plusieurs parties, ce qui nous a permis d'avancer chacun à notre vitesse.
D'une part, nous avons crée et implémenté les classes Integrateur et Eulercromer. Les deux sont, pour le moment, fonctionnels. Néanmoins, pour réaliser le test de Eulercromer (chute libre) sans devoir faire du "travail à double", il a fallu déjà intégrer quelques éléments du chapitre sur le polymorphisme.
Ainsi, Oscillateur est devenu une classe abstraite, et ne peut donc plus être instanciée seule. Cela est dû au fait que la méthode d'évolution est devenu une méthode virtuelle pure.
Nous avons également du modifier pas mal de détails dans oscillateur et dans les différentes méthodes que nous avions établies auparavant, car nous avions mal jugé comment elles agissaient. Mais le tir est corrigé, et nous avons réussi à réaliser la première simulation, la chute libre, qui semble être similaire à la théorie.
Nous avons également fini une première version de la classe pendule.

### Problèmes rencontrés
Les principaux problèmes sont survenus avec les classes Integrateur et Eulercromer.
Déjà, la classe Integrateur a posé quelques problèmes de compréhension, qu'il nous a fallu attendre vendredi pour les corriger. La classe oscillateur a également posé problème, car la fonction d'évolution n'était pas vraiment ce à quoi on s'attendait. Il a donc fallu corriger le tir.

Pendant le week-end l'un d'entre nous a rencontré un problème de compilation avec qmake et a malencontreusement cassé l'interface graphique de son ordinateur en manipulant des paquets de Qt dans une tentative de résoudre le problème. Après une demi-journée de détresse existentielle profonde nous avons réussi à récupérer l'interface avec un peu d'aide extérieure, heureusement sans dommage apparent à la machine. Le contretemps nous a cependant empêché d'avancer sur la classe Ressort, mais elle ne devrait pas prendre trop de temps à implémenter.


## Semaine 6
Cette semaine de travail a été essentiellement composé de Jeudi soir. Le reste de la semaine, nous étions occupé à travailler sur les branches plus vitales.

### Travail accompli
Nous avons essentiellement réalisé une première version de P8. Cette version n'était pas fonctionnelle, mais avait au moins l'avantage de poser les bases.

### Problèmes rencontrés
L'essentiel des soucis sont apparu après coup. En effet, la version de P8 faite ici n'est pas terrible. Il y a quelques implémentation qui font défaut, et qui méritent d'être retravaillées.

## Semaine 7
Semaine de vacances, donc on a été efficace.

### Travail accompli
Nous avons réalisé l'entièreté de P8 et le début de P9. Ceux-ci sont désormais fonctionnels, car nous avons corrigé la plupart des problèmes d'implémentation de la semaine précédente.

### Problèmes rencontrés
Malgré le travail fourni cette semaine, nous avons tout-de-même eut quelques *gros* problèmes d'implémentation, qui nous ont bloqué pendant deux jours.
Premièrement, nous avons eu des problèmes avec Dessinable, SupportADessin et les oscillateurs. En effet, il y avait des dépendances cycliques qui posaient des problèmes lors de la compilation. (les classes n'étaient pas définies...)
Ensuite s'est posé la question de savoir si il fallait que chaque oscillateur (pendule, ressort, ...) hérite de Oscillateur **et** de Dessinable, héritage multiple donc, ou alors s'il héritaient de Dessinable au travers d'Oscillateur par transitivité. C'est ce deuxième choix que nous avons retenu, bien qu'il nous ait demandé plus de compréhension des concepts abordés.
Et finalement, nous avons eu un problème avec Systeme et TextViewer. En effet, nous avons décidé que Systeme *est* un Dessinable, donc il fallait y implémenter void dessine(Systeme const&). Le souci est que nous devions avoir accès, dans la portée de TextViewer, aux différents oscillateurs de système, qui sont des attributs privés, et ce sont des unique_ptr.
Après de longues réflexions, nous avons finalement implémenté une méthode *affiche()* dans Système, qui appelle *dessine()* de chaque oscillateur. Ainsi, nous pouvons dessiner tous les éléments de système facilement.
Remarquons également que cette implémentation devrait être suffisamment générale pour fonctionner avec OpenGL plus tard.

## Semaine 8
### Travail accompli
Nous avons terminé P9 et rendu le code plus clair en appliquant les conseils des assistants et du professeur, notamment en nommant tous les paramètres dans les fichiers .h.

### Problèmes rencontrés
RAS.


## Semaine 9
### Travail accompli
Cette semaine, nous avons bien avancé. Premièrement, nous avons fini de rendre P9 présentable, ce qui a pris beaucoup de temps, mais c'est fait. Le code est donc commenté (et compatible doxygen) et semble présentable.
Nous avons également pu enfin commencer P10. Nous avons bien réorganisé notre code pour que la version texte soit encore fonctionnelle, et nous avons pu débuter la partie graphique. Donc avons donc une fenêtre où nous pouvons nous déplacer. Nous avons implémenté les sphères, carrés et axes. De plus, nous avons réussi à réalisé une boussole qui nous permet de se repérer facilement dans l'espace (essentiellement une représentation des trois axes xyz qui reste dans un coin de l'écran et tourne en suivant les rotations effectuées) ! Nous avons également réalisé la classe Torsion pour modéliser les pendules de torsion.

### Problèmes rencontrés
Le principal problème rencontré touche essentiellement à l'implémentation de cette boussole. Ce n'était pas aisé, mais c'est un franc succès !


## Semaine 10
### Travail accompli
Nous avons réalisé une première version de l'implémentation graphique et ajouté des options d'affichage (mode debug, toggle pour la vue 3ème personne) et des déplacements contrôlés par la souris. Les oscillateurs implémentés jusqu'ici (Pendule, Ressort, Torsion) s'affichent maintenant à l'écran et évoluent selon leurs équations du mouvement respectives.

### Problèmes rencontrés
Nous n'avons pas encore trouvé de moyen d'implémenter la direction principale a, paramètre de tous les oscillateurs.


## Semaine 11
### Travail accompli
Nous avons implémenté la direction principale a en dessinant simplement l'axe du pendule dans cette direction dans un premier temps, puis en ajoutant une rotation si nécessaire. De plus nous avons rendu le code de l'implémentation graphique plus général pour le synthétiser et simplifier l'implémentation des futurs oscillateurs. Nous avons également réalisé une première version de l'intégrateur de Newmark.

### Problèmes rencontrés
Le problème principal avec l'implémentation graphique était dû au fait que les axes xyz de Qt-OpenGL ne correspondent pas aux axes tels que nous les avons représentés dans les classes Oscillateur (notamment la constante gravitationnelle g = (0.0, 0.0, -9.81)), ce qui a surtout posé problème pour l'implémentation de la direction principale de Ressort, puisque celui-ci est affecté par la gravité. Nous avons d'abord pensé à faire une rotation de la matrice_vue pour mettre les axes dans le bon sens, mais cela nous aurait forcé à changer beaucoup de choses dans le code de l'implémentation graphique. Comme ce problème n'affectait vraiment que Ressort nous avons décidé d'appliquer une rotation seulement sur Ressort.
D'autre part notre version de l'intégrateur de Newmark ne donnait pas exactement les mêmes résultats que l'exemple fourni, bien que l'algorithme nous parût correct. Nous avons donc demandé conseil à notre assistant, qui nous a dit que ce n'était pas un problème très grave. Nous avons tout de même posté un thread sur le forum pour demander de l'aide.


## Semaine 12
### Travail accompli

Nous avons implémenté quelques améliorations aux Oscillateurs afin d'empêcher les valeurs physiquement impossibles, et implémenté le double pendule ainsi que l'intégrateur de Runge-Kutta.

Finalement, en fin de semaine, nous avons en pu régler le problème de l'intégrateur de Newmark. En effet, il était décalé et nous ne savions pas pourquoi. En fait, il s'agissait d'une division entière qui ne devait pas l'être. (`1/2` $\neq$ `1.0/2.0`...). Peu après, nous avons également découvert un problème majeur dans l'intégrateur de RungeKutta. En effet, les tests avec l'oscillateur "Chute" semblaient corrects. Cependant, ces tests n'étaient pas suffisants, car Chute **ne dépend pas de P et Q** ! Du coup, en faisant le graphe d'évolution des différents oscillateurs, nous avons donc découvert un bug majeur dans cet intégrateur qui a dû être corrigé en changeant la façon dont `f()` fonctionne dans chaque oscillateurs. En effet, nous avions précédemment cette méthode qui dépendait du temps `f(t)` uniquement. Cependant, cela n'est pas assez général pour ces intégrateurs. C'est pourquoi nous avons dû ajouter les paramètres `P` et `Q` à la méthode `f(t, P, Q)`.

Pour ne pas tout casser, nous avons simplement surchargé cette méthode, et `f(t)` appelle `f(t,P,Q)` avec les `P` et `Q` de l'oscillateur. Ainsi, nous avons pu corriger les deux intégrateurs sans pour autant toucher au reste du code.

Du coup, les intégrateurs sont désormais fonctionnels et utilisables.

### Problèmes rencontrés

RAS.

## Semaine 13
### Travail accompli
Cette semaine, nous avons implémenté un nouvel oscillateur, le pendule-ressort, ainsi que l'espace des phases.

### Problèmes rencontrés
Concernant le pendule-ressort, rien à signaler, c'est comme tous les précédents.

Concernant l'espace des phases, l'implémentation est une réussite. Néanmoins, nous avons eu quelques soucis. En effet, lors que nous activions le _mode espace de phase_, où nous avions simplement copié l'exemple de représentation 2D du tutoriel Qt comme base, tout allait bien, ça s'affichait. Cependant, lorsque l'on revenait sur la vue des oscillateurs, la perspective changeait. Les oscillateurs étaient aplatis. Pour le corriger, nous avons remarqué que, lorsque les oscillateurs étaient aplatis, changer la taille de la fenêtre corrigeait le problème. Du coup, nous avons décidé d'enregistrer la matrice calculée dans paintGL, dans une variable de GLWidgets, et d'appliquer `setPerpective()` avec la matrice en paramètre, appliqué sur le Vue_OpenGL. C'est du bricolage, mais ça a corrigé le problème, et ne semble pas avoir d'effets de bord.

Sinon, le reste s'est déroulé comme prévu, et l'espace des phases est très joli à voir. Coup de coeur pour le pendule-ressort, qui rend particulièrement bien à l'écran.

## Semaine 14
### Travail accompli
Nous avons pas implémenté de nouveaux gros contenus. On a corrigé quelques bugs, changer quelques petits implémentation (phase nottament), et le plus gros de notre travail a été de préparer le projet pour le rendu.

Il n'y a donc rien de particulier à préciser ici. Tout se passe bien.

### Problèmes rencontrés
Rendre du code beau n'est clairement pas intéressant, ce qui n'aide pas à travailler. À part cela, RAS.
