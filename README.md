# Oscillateurs couplés
Bienvenu dans ce projet d'informatique du Bachelor 2 à l'EPFL.

Nous y réalisons une simulation d'oscillateurs.

Vous pouvez retrouver les pages associées dans le menu de la page.

Projet réalisé par **Delphine Martres** et **Damien Korber**.
## Table des matières
1. [Compilation](#compilation)
2. [Utilisation](#utilisation)
3. [Structure du projet](#structure)
4. [Conventions - A SUPPRIMER POUR LE RENDU !](#conventions)

## Compilation <a name="compilation"/>
### Compiler le projet dans son ensemble
Pour compiler le projet ou les tests qui sont encore compilable, il suffit d'executer ces commandes.
```bash
qmake # ou qmake-qt5 dans certaines distributions. Génère le Makefile. Attention, il faut utiliser Qt5 !
make # Compile le projet ou les tests.
```

### (Bonus) La documentation
La documentation du projet peut-être générée avec Doxygen. Pour ce faire, rien de plus simple !

Il suffit de se rendre à la racine du projet et d'executer `doxygen doxyfile`.

La documentation ainsi générée se trouve dans le dossier `docs/`.

## Utilisation <a name="utilisation"/>
A REMPLIR

## Structure du projet <a name="structure"/>
L'organisation du projet suit une certaine structure, que voici.
```bash
> Asked/ # contient tous les fichiers demandés pour l'avancement du projet, et la partie administrative.
> docs/ # contient toute la documentation liée au projet (généré automatiquement avec doxygen).
```

## Conventions (À supprimer pour le rendu) <a name="conventions"/>
Quelques conventions sont respectée dans ce projet.
### Les commentaires.
Pour garder le code lisible, il est utile d'avoir certaines conventions, et comme un exemple est plus parlant qu'un long texte, voici ce qui devrait être pratiqué.

```c++
/*!
* Brève explication de son intéret.
* Un exemple de son fonctionnement si besoin
*
* Problème(s) liés à cette fonction si besoin
*
* Il est fortement conseillé d'écrire sur plusieurs lignes, afin de garder
* un semblant de lisibilité. De plus, il est préférable de mettre les commentaires
* globaux de cette méthode dans ce commentaire plutôt que le long du code.
* Préférer les commentaire en une ligne pour le reste du code.
*/
//! Un commentaire d'une ligne avant la fonction (si besoin).
void Classe::Methode()
{
    double attribut(42); //<! un commentaire d'une ligne après la fonction (si besoin)
}
```
