# Projet pipex - École 42

## Description
pipex est un projet de l'École 42 qui consiste à recréer le comportement des pipes du shell Unix. L'objectif est de comprendre en profondeur comment fonctionnent les redirections et les pipes en programmation système.

## Objectifs
- Comprendre et implémenter le mécanisme des pipes Unix
- Gérer les redirections d'entrée et de sortie
- Manipuler les descripteurs de fichiers
- Exécuter des commandes externes
- Gérer les processus fils

## Fonctionnalités
- Simulation du comportement de la commande shell suivante :
  ```
  < file1 cmd1 | cmd2 > file2
  ```
- Gestion des erreurs et des cas limites
- Utilisation correcte des fonctions autorisées par le sujet

## Compétences développées
- Programmation en C
- Manipulation des processus (fork, wait, waitpid, exit)
- Gestion des descripteurs de fichiers et des pipes
- Exécution de programmes externes (execve)
- Gestion des erreurs système

## Utilisation
Le programme doit être exécuté de la manière suivante :
```
./pipex file1 cmd1 cmd2 file2
```
Cela devrait avoir le même résultat que la commande shell suivante :
```
< file1 cmd1 | cmd2 > file2
```

## Installation et compilation
1. Clonez ce dépôt :
   ```
   git clone https://github.com/thed6bel/pipex.git
   ```
2. Naviguez dans le dossier du projet :
   ```
   cd pipex
   ```
3. Compilez le projet :
   ```
   make
   ```

## Exemples d'utilisation
```
./pipex infile "ls -l" "wc -l" outfile
```
Cela devrait avoir le même résultat que :
```
< infile ls -l | wc -l > outfile
```

## Gestion des erreurs
- Le programme gère les erreurs liées aux fichiers (permissions, existence)
- Il gère également les erreurs liées aux commandes (commande introuvable, droits d'exécution)
- En cas d'erreur, des messages appropriés sont affichés sur la sortie d'erreur

## Bonus possibles
- Gestion de plusieurs pipes :
  ```
  ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
  ```
- Support de la redirection d'entrée « heredoc » (`<<`) :
  ```
  ./pipex here_doc LIMITER cmd cmd1 file
  ```

## Fonctions autorisées
- open, close, read, write
- malloc, free
- perror, strerror
- access
- dup, dup2
- execve
- exit
- fork
- pipe
- unlink
- wait, waitpid

