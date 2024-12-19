# Template-Breakout

![Breakout Game](https://i.imgur.com/qMvvhcm.png) <!-- Remplacez par une image ou un GIF de votre jeu -->

## Description

**Template-Breakout** est une implémentation moderne et modulaire du jeu classique *Breakout*, développée en C++ en utilisant [SFML 3.0.0](https://www.sfml-dev.org/). Ce projet sert de base pour la création de jeux 2D, mettant en avant les bonnes pratiques de programmation orientée objet et une architecture basée sur des composants.

## Fonctionnalités

- **Système de composants** :
  - Gestion dynamique des entités et de leurs composants.
  - Composants personnalisables pour les formes, la physique, les collisions, etc.

- **Système de collision avancé** :
  - Gestion des collisions entre cercles et rectangles.
  - Calcul précis des normales et des rebonds.

- **Effets dynamiques** :
  - Effets audio grâce à SFML.

- **Outils de débogage** :
  - Affichage en temps réel des informations pour faciliter le développement.

- **Extensibilité** :
  - Ajout facile de nouveaux comportements, formes ou mécanismes de jeu.

## Prérequis

- Un compilateur compatible C++20 ou supérieur (par exemple : GCC, Clang, MSVC).

## Installation

1. Clonez le dépôt :

   ```bash
   git clone https://github.com/Floran05/Template-Breakout.git
   cd Template-Breakout
   ```

2. Ouvrez le projet dans votre IDE préféré (par exemple : Visual Studio, Code::Blocks, CLion).

3. Compilez et exécutez.

## Utilisation

### Contrôles

- **Flèche gauche** : déplacer la raquette vers la gauche.
- **Flèche droite** : déplacer la raquette vers la droite.
- **Espace** : Relancer la partie lors du Game Over

## Arborescence du projet

```
Template-Breakout/
├── assets/           # Ressources (textures, polices, etc.)
├── components/       # Implémentations des composants
├── objects/          # Objets du jeu (balle, raquette, etc.)
├── services/         # Manageurs
├── main.cpp          # Point d'entrée du programme
├── resources.h       # Fichier qui contient les configurations
```
