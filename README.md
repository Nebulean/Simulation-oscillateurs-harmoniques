# Oscillateurs couplés
## Table des matières
1. [Compilation](#compilation)
2. [Utilisation](#utilisation)
3. [Structure du projet](#structure)
4. [Conventions](#conventions)

## Compilation <a name="compilation"/>
### Compiler le projet dans son ensemble
A REMPLIR

### ERRONÉ ~~Compiler les tests~~
Tous les tests se trouvent dans le dossier `test/`, situé à la racine du projet. Pour compiler un test, il suffit de se rendre dans le dossier du test, et d'executer `make`. Le fichier de sortie aura (normalement) le nom du dossier.

## Utilisation <a name="utilisation"/>
A REMPLIR

## Structure du projet <a name="structure"/>
L'organisation du projet suit une certaine structure, que voici.
```bash
> Asked/ # contient tous les fichiers demandés pour l'avancement du projet, et la partie administrative.
> docs/ # contient toute la documentation liée au projet (généré automatiquement avec doxygen).
```

## Conventions <a name="conventions"/>
Quelques conventions sont respectée dans ce projet.
### Les commentaires.
Pour garder le code lisible, il est utile d'avoir certaines conventions, et comme un exemple est plus parlant qu'un long texte, voici ce qui devrait être pratiqué.

```c++
// ======================================================================
void Classe::Methode()
{
   /* Brève explication de son intéret.
    * Un exemple de son fonctionnement si besoin
    *
    * Problème(s) liés à cette fonction si besoin
    *
    * Il est fortement conseillé d'écrire sur plusieurs lignes, afin de garder
    * un semblant de lisibilité. De plus, il est préférable de mettre les commentaires
    * globaux de cette méthode dans ce commentaire plutôt que le long du code.
    * Préférer les commentaire en une ligne pour le reste du code.
    */
    // on commentaire d'une ligne avant la fonction (si besoin).
    double attribut(42); // un commentaire d'une ligne après la fonction (si besoin)
    // le reste de la méthode
}
```
