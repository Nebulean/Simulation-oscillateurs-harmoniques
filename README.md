<!-- Ce document est en format Markdown, et utilise latex pour le rendu de quelques éléments. Pour le lire, veuillez vous procurer un bon lecteur markdown, ou de lire le PDF associé. -->

# Oscillateurs couplés

Bienvenue dans ce projet d'informatique du Bachelor 2 à l'EPFL, en section physique.

Projet réalisé par **Delphine Martres** et **Damien Korber**.

## Préambule
### Informations concernant le projet.

> _Jusqu'où avez-vous été ? qu'est-ce que vous avez fait/pas fait ?_

Nous avons été jusqu'au bout du projet, c'est-à-dire **jusqu'à P13 compris**.

Nous avons réalisé l'**ensemble des oscillateurs** du complément mathématique, à l'exceptions des pendules reliés par un ressort et l'oscillateur DeuxRessort, dû à un manque de temps. Une analyse des oscillateurs implémentés est disponible plus bas.

Nous avons implémenté **tous les intégrateurs** énoncés dans le complément mathématique, c-à-d Euler-Cromer, Newmark et Runge-Kutta d'ordre 4. Un comparatif est disponible plus bas.

Nous avons également un **espace des phases fonctionnel**. Cependant, changer l'oscillateur doit se faire **manuellement**. Nous avons pas eu le temps d'implémenter une touche de changement d'oscillateur.

> _Avez-vous une version graphique ? Si oui, avec quelle bibliothèque graphique (Qt (quelle version ?), WxWidget, SDL, Glut, autre [précisez]) ?_

Oui, nous avons une version graphique et nous avons utilisé Qt 5.10. Pour plus de détails concernant les supports sur lesquels le projet à été testé, se référer à la section "Guide de compilation".

> _Combien d'heures en moyenne par personne estimez vous avoir passé par semaine sur le projet ? (essayez d'être objectif : n'oubliez pas qu'au début vous n'avez peut être pas fait grand chose, comptez sur 14 semaines, i.e. la première semaine incluse, ne comptez pas le cours ni les exercices hors projet, n'oubliez pas de diviser le total par 2 car je veux une estimation moyenne par personne.)_

Nous estimons, en moyenne et par personne, une implication d'une petite dizaine d'heures par semaine. Cependant, nous avons fait attention à ne pas prendre trop de temps sur les autres branches. Ainsi, nous avons essentiellement travaillé sur nos temps libres (soirs du week-end et vendredi dès midi essentiellement).

### Les quelques points intéressants du projet.
**La simulation visuelle**

Le point central de ce projet est évidemment la simulation visuelle. Nous vous proposons de compiler et executer le programme dans Qt_GL. Quand vous y êtes, vous pouvez vous balader dans l'espace et admirer les oscillateurs.

**L'espace des phases**

Lors de l'execution de la version graphique du projet, l'espace des phases peut-être affiché en appuyant sur **P**. On peut donc y voir une représentation de la vitesse en fonction du temps de l'oscillateur sélectionné. Pour changer d'oscillateur à représenter dans l'espace des phases, il faut se rendre dans le fichier `exerciceP10/Qt_GL/glwidget.cc` et suivre les instructions se trouvant dans la méthode `initSys()`.

**La boussole**

Il est très facile de se perdre dans la simulation visuelle. Du coup, nous avons implémenté une boussole directement sur Qt. Nous en sommes fière, parce que c'était pas facile à faire. Par défaut, elle devrait être activée. Mais si ce n'est pas le cas, ou si vous voulez desactiver cette boussole, appuyez sur la touche **B**. Elle suivre vos mouvements dans l'espace.

**Le changement de point de vue**

Nous n'étions pas d'accord sur la façon de se déplacer dans l'espace. Nous avons donc implémenté un toggle permetant de switcher entre une vue à la première personne (on "est" la caméra) et une vue à la troisième personne (on fixe un point dans l'espace). Pour changer de point de vue, appuyez sur **V**.

**Le changement d'intégrateur en cours d'execution**

Dans la simulation graphique, il est possible de changer d'intégrateur en cours d'execution. Par défaut, l'intégrateur de Runge-Kutta d'ordre 4 est utilisé, mais vous pouvez switcher d'intégrateur en cours de route. Pour cela, appuyez sur:
* **1** - pour utiliser Euler-Cromer;
* **2** - pour utiliser Newmark;
* **3** - pour utiliser Runge-Kutta d'ordre 4.
Un message indiquant un changement d'intégrateur sera affiché dans le terminal.

Remarque: le texte affiché après est l'adresse de l'intégrateur actuel.

**La documentation**

Pour ne pas se perdre dans le projet, nous avons utilisé Doxygen pour générér la documentation automatiquement. Pour plus d'informations à ce sujet, plus d'informations sont disponible dans la section "Générer la documentation".

**Le mode debug**

Pour vérifier le bon fonctionnement des oscillateurs executé durant la simulation visuelle, nous avons implémenter un mode debug. Lors de l'execution, appuyez sur **§** pour (des)activer le mode debug. Les informations s'afficheront dans le terminal.


## Table des matières
<!-- TOC depthFrom:2 depthTo:6 withLinks:0 updateOnSave:0 orderedList:1 -->

1. Préambule
	1. Informations concernant le projet.
	2. Les quelques points intéressants du projet.
2. Table des matières
3. Introduction
4. Ce qu'il faut regarder
5. Guide de compilation
	1. Preambule les informations importantes
	2. Ce qui est compilable
	3. Compiler sur MacOS
	4. Compiler sur Kubuntu (et donc Linux)
	5. Compiler tous les sous-projet fonctionnels
	6. Générer la documentation
6. Guide d'utilisation
	1. Les touches.
7. Analyse
	1. Les intégrateurs
	2. Les oscillateurs
		1. Le pendule simple
		2. Le ressort simple
		3. La chute
		4. Le pendule de torsion
		5. Le chariot
		6. Le pendule double non amorti.
		7. Le Pendule-Ressort non amorti.

<!-- /TOC -->

\pagebreak
## Introduction

Le but de ce projet est la réalisation d'un programme pouvant simuler des oscillateurs couplés. Nous avons réalisé quelques preset d'oscillateurs, mais le programme se veut suffisament souple pour ajouter de nouveaux oscillateurs.

Nous offrons une simulation textuelle, ainsi qu'une simulation visuelle, utilisant Qt et OpenGL.

## Ce qu'il faut regarder



\pagebreak
## Guide de compilation

Pour compiler le programme dans sa version actuelle, rien de plus simple, suivez ce tutoriel et tout devrait bien se passer.

### Preambule les informations importantes

Nous utilisons **qmake 3.1** et **Qt 5.10** pour ce projet. Le programme fonctionne peut-être avec d'autres version, mais nous n'avons pas testé.
De plus, nous avons testé le programme sur les OS suivants:

- **MacOS 10.13.4**
- **Kubuntu 16.04**
- **Machine virtuelle de l'EPFL (25 mai)**

### Ce qui est compilable

Comme dit précédemment, nous avons implémenté deux simulations, qui sont séparée dans deux dossiers.

**La simulation textuelle**

Elle se trouve dans `exerciceP10/text/`.

**La simulation visuelle**

Elle se trouve dans `exerciceP10/Qt_GL/`.

Concernant le reste des sous-projets (les tests, ...) vous pouvez tester des les compiler, mais la plus part ne sont plus fonctionnel dans l'état actuel du projet. Cependant, ils étaient bel et bien fonctionnels lorsqu'ils nous étaient utile.

### Compiler sur MacOS

Pour compiler sur MacOS, il suffit de se rendre dans le projet que l'on veut compiler, et de faire ces commandes.

```bash
qmake # permet de générer un Makefile
make # compile le projet demandé
```

Pour executer, il suffit tout simplement d'executer

```bash
./$NOM_DE_EXECUTABLE # execute la simulation
```

où NOM_DE_EXECUTABLE est le... nom de l'executable.

### Compiler sur Kubuntu (et donc Linux)

Pour compiler sur linux, il suffit de se rendre dans le projet que l'on veut compiler, et de faire ces commandes.

```bash
qmake # permet de générer un Makefile
make # compile le projet demandé
```

Pour executer, il suffit tout simplement d'executer

```bash
./$NOM_DE_EXECUTABLE # execute la simulation
```

où `NOM_DE_EXECUTABLE` est le... nom de l'executable.

### Compiler tous les sous-projet fonctionnels

A REMPLIR, MAIS CE N'EST PAS ENCORE PRET DANS LE CODE.

### Générer la documentation

La documentation est générée automatiquement par **Doxygen**.

**Génération et lecture**

Pour générer la documentation, allez à la racine du projet (là où se trouve le README), et executez cette commande:  `doxygen doxyfile`.

La documentation ainsi générée se trouve dans `docs/`. Pour la documentation html, ouvrez `docs/html/index.html`. Pour la documentation en latex, executez `make` dans le dossier `docs/latex`.

Remarque: la documentation en latex n'est ni maintenue, ni testée.



\pagebreak
## Guide d'utilisation

Dans cette section, nous vous expliquons comment utiliser ce projet. Concernant la simulation textuelle, il n'y a rien à savoir, donc nous nous intéressons à la simulation visuelle.

Remarque: Ce programme est adapté pour un clavier Suisse, c'est à dire un clavier QWERTZ.

### Les touches.

**Déplacements**

| Action                                              | Touche associée                   |
|:---------------------------------------------------:|:---------------------------------:|
| Avancer                                             | **w** ou **pageUp**               |
| Reculer                                             | **s** ou **pageDown**             |
| Translater sur la droite                            | **d**                             |
| Translater sur la gauche                            | **a**                             |
| Appliquer une rotation dans le sens trigonométrique | **q**                             |
| Appliquer une rotation dans le sens horaire         | **e**                             |
| Translater vers le haut                             | **r**                             |
| Translater vers le bas                              | **f**                             |
| Tourner vers la droite                              | $\rightarrow$ ou (click + souris) |
| Tourner vers la gauche                              | $\leftarrow$ ou (click + souris)  |
| Tourner vers le haut                                | $\uparrow$ ou (click + souris)    |
| Tourner vers le bas                                 | $\downarrow$ ou (click + souris)  |
| Réinitialiser à la position originale               | **home** ou **h**                 |

**Autres commandes.**

| Action                                                | Touche associée |
|:-----------------------------------------------------:|:---------------:|
| (Des)activation de la boussole                        | **b**           |
| (Des)activation du mode debug dans le terminal        | **§**           |
| (Des)activation de la mise en pause de la simulation  | **space**       |
| Changement de la vue (première ou troisième personne) | **v**           |
| Activation de l'intégrateur d'Euler-Cromer            | **1**           |
| Activation de l'intégrateur de Newmark                | **2**           |
| Activation de l'intégrateur de Runge-Kutta d'ordre 4  | **3**           |
| (Des)activation de l'espace de phase									| **p**						|

\pagebreak
## Analyse

Nous avons effectué quelques petites analyse de nos différentes implémentations.

### Les intégrateurs

Nous avons implémentés les trois intégrateurs proposés. L'intégrateur d'Euler-Cromer, de Newmark, et de Runge-Kutta à l'ordre 4. Nous avons donc testé une chute libre de conditions initiales $\vec{P} = (0, 1)$ et $\dot{\vec{P}} = (1, 2)$. ![graphique comparant les différents intégrateurs](annexes/integr_comp.png)

Nous remarquons que, effectivement, l'intégrateur d'Euler-Cromer est moins bon que les autres. Il est certes plus simple à implémenter, mais il est bien moins précis.

De plus, nous notons que l'intégrateur de Newmark et l'intégrateur de Runge-Kutta d'ordre 4 ont quasiment la même précision ! Sur le graph, ils sont confondus.

### Les oscillateurs

Nous avons implémenté un certaine nombre d'oscillateurs, et nous avons effectué quelques teste pour voir leur bon fonctionnement.

Tous les tests ci-dessus sont effectué avec l'intégrateur de **Runge-Kutta d'ordre 4**.

\pagebreak
#### Le pendule simple

**Conditions initiales**

- Masse = 1
- Longueur = 2
- Viscosité = 0.1
- Position = {M_PI/2}
- Vitesse = {0.0}
- Origine = {0.0, 0.0, 0.0}
- Direction principale = {1.0, 0.0, 0.0}

**Schéma**

![graphPendule](annexes/graphPendule.png)
Nous remarquons que l'évolution du pendule se passe comme prévu. Il est amorti et tend vers un minimum.

\pagebreak

#### Le ressort simple

**Conditions initiales**

- Masse = 0.25
- Elasticité = 0.5
- Viscosité = 0.02
- Position = {0.18}
- Vitesse = {0.0}
- Origine = {0.0, 0.0, 0.0}
- Direction principale = {0.8, 0.0, 0.6}

**Schéma**

<img>
![Graphique d'évolution d'un ressort à ces conditions initiales](annexes/graphRessort.png)
Nous remarquons que l'évolution du ressort se passe comme prévu. Il est amorti et tend vers un minimum.

\pagebreak

#### La chute

**Conditions initiales**

- Masse = 1
- Position = {0.0, 1.0}
- Vitesse = {1.0, 2.0}
- Origine = {0.0, 1.0}
- Direction principale = {0.0, 1.0}

**Schéma**

![Graphique d'évolution d'une chute à ces conditions initiales](annexes/graphChute.png)
Nous remarquons que l'évolution de la chute se passe comme prévu. Elle continue à chuter à accélération constante.

\pagebreak

#### Le pendule de torsion

**Conditions initiales**

- Moment d'inertie = 1
- Constante de torsion = 1
- Friction = 0.05
- Position = {M_PI/4}
- Vitesse = {0.0}
- Origine = {0.0, 0.0, 0.0}
- Direction principale = {1.0, 0.0, 0.0}

**Schéma**

![Graphique d'évolution d'un pendule de torsion à ces conditions initiales](annexes/graphTorsion.png)
Nous remarquons que l'évolution du pendule de torsion se passe comme prévu. Il est amorti et tend vers un minimum.

\pagebreak

#### Le chariot

**Conditions initiales**

- Masse du chariot = 1
- Masse du pendule = 1
- Longeur du pendule = 1.5
- Elasticité = 0.1
- Viscosité du chariot = 0.1
- Viscosité du pendule = 0.1
- Position = {1.0, M_PI/3}
- Vitesse = {0.0, 0.0}
- Origine = {0.0, 0.0, 0.0}
- Direction principale = {1.0, 0.0, 0.0}

**Schéma**

![Graphique d'évolution d'un chariot à ces conditions initiales](annexes/graphChariot.png)
Nous remarquons que l'évolution du chariot se passe comme prévu. Il est amorti et tend vers un minimum.

\pagebreak

#### Le pendule double non amorti.

**Conditions initiales**

- Masse 1 = 1
- Masse 2 = 1
- Longeur 1 = 1.5
- Longeur 2 = 0.1
- Position = {M_PI/3, M_PI/3}
- Vitesse = {0.0, 0.0}
- Origine = {0.0, 0.0, 0.0}

**Schéma**

![Graphique d'évolution d'un pendule double non amorti à ces conditions initiales](annexes/graphPenduleDouble.png)
Nous remarquons que l'évolution du pendule double non amorti se passe comme prévu. Comme il n'est pas ralenti, il continue à l'infinie et est plus ou moins périodique.

\pagebreak
#### Le Pendule-Ressort non amorti.

**Conditions initiales**

- Masse = 2
- Longeur = 1
- Raideur = 5
- Position = {1.0, 0.0}
- Vitesse = {0.0, 0.0}
- Origine = {0.0, 0.0, 0.0}

**Schéma**

![Graphique d'évolution d'un pendule-ressort non-amorti à ces conditions initiales](annexes/graphPenduleRessort.png)
Nous remarquons que l'évolution du pendule-ressort non-amorti semble se passer comme prévu.
