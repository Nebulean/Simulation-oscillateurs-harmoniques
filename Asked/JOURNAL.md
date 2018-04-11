A MODIFIER AVANT DE RENDRE:
* Semaine 5, vérifier que Oscillateur est bien une classe abstraite et que la méthode d'évolution est une méthode virtuelle pure.


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
Nous avons également eu un problème avec les exceptions en c++. Nos souvenirs sur le cours à ce sujet, qui date d'il y a plus d'un an pour nous, n'étaient plus très frais , et les réponses données sur internet ne sont guères suffisantes. La solution est donc de relire le cours sur les exceptions.

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
L'essentiel des soucis sont apparu après coup. En effet, la version de P8 faite ici n'est pas terrible. Il y a quelques implémentation qui font défaut, et qui méritent d'être retravaillés.

## Semaine 7
Semaine de vacances, donc on a été efficace.
### Travail accompli
Nous avons réalisé l'entièreté de P8 et P9. Ceux-ci sont désormais fonctionnels, car nous avons corrigé la plupart des problèmes d'implémentation de la semaine précédente.
### Problèmes rencontrés
Malgré le travail fourni cette semaine, nous avons tout-de-même eut quelques *gros* problèmes d'implémentation, qui nous ont bloqué pendant deux jours.
Premièrement, nous avons eu des problèmes avec Dessinable, SupportADessin et les oscillateurs. En effet, il y avait des dépendances cycliques qui posaient des problèmes lors de la compilation. (les classes n'étaient pas définies...)
Ensuite s'est posé la question de savoir si il fallait que chaque oscillateur (pendule, ressort, ...) hérite de Oscillateur **et** de Dessinable, héritage multiple donc, ou alors s'il héritaient de Dessinable au travers d'Oscillateur par transitivité. C'est ce deuxième choix que nous avons retenu, bien qu'il nous ait demandé plus de compréhension des concepts abordés.
Et finalement, nous avons eu un problème avec Systeme et TextViewer. En effet, nous avons décidé que Systeme *est* un Dessinable, donc il fallait y implémenter void dessine(Systeme const&). Le souci est que nous devions avoir accès, dans la portée de TextViewer, aux différents oscillateurs de système, qui sont des attributs privés, et ce sont des unique_ptr.
Après de longues réflexions, nous avons finalement implémenté une méthode *affiche()* dans Système, qui appelle *dessine()* de chaque oscillateur. Ainsi, nous pouvons dessiner tous les éléments de système facilement.
Remarquons également que cette implémentation devrait être suffisamment générale pour fonctionner avec OpenGL plus tard.

## Semaine 8
### Travail accompli
### Problèmes rencontrés


## Semaine 9
### Travail accompli
### Problèmes rencontrés


## Semaine 10
### Travail accompli
### Problèmes rencontrés


## Semaine 11
### Travail accompli
### Problèmes rencontrés


## Semaine 12
### Travail accompli
### Problèmes rencontrés


## Semaine 13
### Travail accompli
### Problèmes rencontrés


## Semaine 14
### Travail accompli
### Problèmes rencontrés
