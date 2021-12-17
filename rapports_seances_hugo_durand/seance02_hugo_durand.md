# Séance du 15/12/2021

## Mise au point avec Raphael :

Nous avons décidés de la manière dont nous allons assemblés les moteurs ensemble. Nous avons 3 moteurs : un pour le mouvement du genou, un pour lever la patte, un dernier pour rentrer ou écarter la patte du corps. 

On opte pour ce système :

<figure align="center">
  <img src="vue_de_dessus patte onshape.PNG" width="300" title="image du système vue de dessus"/>
  <figcaption>image du système vue de dessus</figcaption>
</figure>

<figure align="center">
  <img src="vue_de_cote patte onshape.PNG" width="300" title="image du système vue de cote"/>
  <figcaption>image du système vue de dessus</figcaption>
</figure>

Le premier servo-moteur est relié au sommet du femur pour activer le genou.

Le deuxième est relié sur le contour du haut du femur avec un mecanisme d'engrenage.

Le troisième bouge le boitier de l'épaule lateralement.


On s'est concertés pour être au point à la rentrée des vacances :

- La modélisation et les pièces du robot chien sont entièrement terminés et prêtes pour impression à la rentrée.

- Modélisation des pièces sur notre logiciel de simulation. Cette partie ne devrait pas prendre trop de temps vu que on a juste à les importer sur le logiciel.

- Tester certains mouvement du robot sur la console : écrire un code qui bouge la patte dans un premier temps

## Recherche du meilleur logiciel de simulation :

On doit entraîner notre robot via une interface pour tester son poids par rapport à la force du moteur. Tester les rotations et les limites des mouvements des pattes. On aura la possibilité de tester notre code directement sur l'interface.

### Unreal Engine :

Ce logiciel est très connu et facil d'accès pour les débutants. Il utilise BluePrints : un système de script visuel, relier des blocks les uns avec les autres et créer un jeu d'éléments. Je me suis pas plus attardé sur ce logiciel, je me suis tout de suite tourné sur Unity parce qu'il est adopté par la plupart des dog robots développeurs open source.

### Unity :

J'ai testé Unity sous conseil d'un ami. Je l'ai installé et découvert un peu ses fonctionnalités. Il est composé d'un onglet mise en scène, vue d'une camera, un inspector, une console, une fenêtre pour y glisser les fichiers Obj. Point noir de ce logiciel : Le code est en C et je ne connais pas ce language. Pour pouvoir coder en Python, il faut installer une extension (je n'ai pas encore tester).

### Webot de Cyberrobotics :

Le téléchargement à mis trop de temps je n'ai pas pu le télécharger. En faisant quelques recherches : Webots est un simulateur open-source de robotique. Il est utilisé dans l'industrie, dans la recherche et éducation.

Parfait pour nous en tant qu'étudiant. Il existe également des exemples de simulations de Robot qui nous sont accessibles sur le site, pour avoir un aperçu de notre tache.

