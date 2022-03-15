# Séance 7 : 12/02/2022 -> 26/02/2022

## Encore des tests de marche infructueux

&nbsp;&nbsp;&nbsp;&nbsp;Je pense qu'on aurait pu faire un long métrage si on avait filmé tous les échecs de marche avant pour le robot... En voici l'un deux :

[Échec marche avant]()

## Marche synchronisée

&nbsp;&nbsp;&nbsp;&nbsp;Nous sommes rassuré par le fait que nous arrivions à faire bouger toutes les jambes de manière synchronisée et identique. Mais le robot ne marche toujours pas...

![Jambe synchronisé](seance07_illustrations/robot-synchronise.gif)

## Nouveau corps pour le robot

&nbsp;&nbsp;&nbsp;&nbsp;Nous avons passé beaucoup de temps au FabLab pour mettre en place le nouveau corps de notre robot.

Comme d'habitude, il a fallu d'abord nettoyé toutes les pièces imprimées en 3D...

![Nettoyage pièces](seance07_illustrations/nettoyage-pieces.png)

Nous avons ensuite démonté les 4 pattes du robot de l'ancien corps qui était en bois.

![Robot démonté](seance07_illustrations/demontage-robot.png)

C'était un petit peu le bazar sur l'établi...

![Etabli en bazar](seance07_illustrations/etabli-en-bazar.gif)

Je n'ai malheureusement pas retrouvé les vidéos concernant cette partie là du projet. Avec Hugo, nous avons mis en place plusieurs inserts dans les pièces 3D afin de pouvoir les viser ensemble sans risquer de casser le plastique. Il a fallu utiliser le fer à souder pour faire fondre le plastique autour du trou pré-existant, et ensuite rentrer l'insert dedans.

Le robot commence à prendre forme.

![Robot en cours de construction 01](seance07_illustrations/montage-robot01.png)

![Robot en cours de construction 02](seance07_illustrations/montage-robot02.png)

![Robot design final]() // TODO : Demander une photo à Hugo du design final

## Rush final avant la Journée Porte Ouvertes

&nbsp;&nbsp;&nbsp;&nbsp;Malgré le fait que je sois positif au covid, donc confiné, donc ne pouvant pas aller à la JPO, j'ai décidé de faire une nuit quasi blanche afin d'avoir un robot avec le plus de fonctionnalités possibles pour le lendemain étant que M. Masson pourra venir le chercher. J'ai travaillé quasi non-stop sur le robot de 14h (25/02) à 5h30 (26/02). Heureusement que j'avais du café...

_Photos prises à 23h30 ("seulement" 2 cafés déjà pris à ce moment là)_

![Selfie nuit blanche](seance07_illustrations/seflie-nuit-blanche.png)

**Tous les éléments suivants ont été réalisés pendant ce rush.**

## Rajout de la classe `Leg`

&nbsp;&nbsp;&nbsp;&nbsp;J'ai fait cet ajout en début d'après-midi afin de nous simplifier la vie. Cette classe permet de stocker toutes les constantes pour les offsets des servos moteurs d'une jambe. Ainsi, peu importe la jambe, l'angle donné en input fera bouger chaque jambe au même endroit. Cette méthode gère aussi l'assignation des bons servos en fonction de la jambe choisie.  
&nbsp;&nbsp;&nbsp;&nbsp;Cela nous permettra par la suite de coder beaucoup plus rapidement les différentes méthodes dont nous avions besoin. Le code est aussi beaucoup plus propre que précédemment.

## Mise en place de la communication infrarouge

&nbsp;&nbsp;&nbsp;&nbsp;Grâce au module infrarouge et la télécommande que nous avons, j'ai pu les mettre en place afin de commander le robot à distance. J'ai donc du modifié le code du `main.cpp` pour qu'en fonction du bouton appuyé, cela appelle différentes méthodes.

![Communication infrarouge](seance07_illustrations/infrared-communication.png)

[Démonstration de la télécommande](link vers youtube pas encore mis car je n'ai pas les accès à la chaîne)

## Méthodes de mouvement

&nbsp;&nbsp;&nbsp;&nbsp;Cette nuit a été l'occasion de revoir toutes les méthodes de mouvement du robot. J'ai créé la méthode `excitement` qui permet au robot d'avoir une petite animation sympathique. J'ai ensuite beaucoup travaillé sur `move_forward`, `move_left` et `move_right`. J'ai testé beaucoup de valeurs différentes, des délais différentes, des ordres de mouvements différents.  
&nbsp;&nbsp;&nbsp;&nbsp;La méthode move_forward fonctionne quasiment même sans aider le robot en le tenant avec la corde. En revanche, les méthodes pour aller à gauche et à droite ne sont pas du tout optimisées ni fonctionnelles en réalité puisqu'il faut impérativement aider le robot pour qu'elles fonctionnent.
&nbsp;&nbsp;&nbsp;&nbsp;Vous pourrez trouver des vidéos des différents mouvements ci-dessous.

// TODO Mettre les vidéos sur Youtube mais je n'ai pas encore les accès.

[Il marche enfin !]()  
[Il marche mais avec de l'aide]()  
[Marche sur le côté avec de l'aide]()

## Pixy2

&nbsp;&nbsp;&nbsp;&nbsp;Cette nuit a aussi été l'occasion de brancher et utiliser la pixy2. J'ai rencontré quelques difficultés à la configurer correctement pour qu'elle suive les objets bleus. J'ai d'abord utilisé le logiciel **PixyMon** pour vérifier que cela fonctionnait correctement mais j'ai ensuite dû inclure le code qui permet à la caméra de suivre un objet grâce à son support.  
&nbsp;&nbsp;&nbsp;&nbsp;Le robot ne peut pas suivre un objet car il ne peut pas se déplacer sur le côté ni tourner. En revanche, il sait détecter lorsqu'un objet bleu est devant lui, si c'est le cas, il commence à marcher tout droit.

[Démonstration détection objet bleu]()

## Liste des vidéos qui vont être mis sur Youtube

- demonstration-infrarouge.mp4
- following-blue-square.mp4
- il-marche-enfin.mp4
- robot-ne-marchant-pas.mp4
- walking-forward-with-help.mp4

Ces vidéos sont dans le dossier : [ici](seance07_illustrations)
