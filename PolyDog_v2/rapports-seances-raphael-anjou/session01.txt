# Rapport de séance 1

## Introduction

Je n'ai pas écrit de rapport pour le travail concernant le Polydog V2 depuis sa création jusqu'à maintenant. Il n'y a donc pas de traces de mon côté. En revanche, Hugo a pris de note des différentes avancées relatives au robot.
Ma participation est souvent similaire à ce que Hugo a fait car nous avons avancer sur des tâches relativement similaires ou alors en parallèle lors de tâches répétitives.

## Où en est le robot actuellement ?

Tout le corps est complet, c'est-à-dire que nous avons toutes les pièces et celles-ci sont montées correctement. Il ne nous reste ainsi "plus qu'à" coder un cerveau au robot pour lui permettre de se déplacer.

À partir de maintenant et jusqu'en septembre je travaillerai seul sur le robot étant donné qu'il est chez moi.

## 30 juin 2022

### Remontage du robot


J'ai d'abord refait tous les branchements que ce soit ceux des moteurs, de l'Arduino, du capteur infrarouge et de l'alimentation. Il y avait quelques erreurs sur les branchements des moteurs probablement dûs à notre fatigue en fin d'année scolaire.

Concernant l'alimenation, j'avais déjà branché au Fablab les câbles sur l'alimentation et j'ai juste eu à les connecter au SSC-32.

Ayant maintenant une alimentation, j'ai pu coder un petit programme permettant de placer tous les servos moteurs à 90°. Ainsi, j'ai pu installé correctement toutes les pattes, avec le bon angle. Celles-ci avaient été détachées afin de faciliter le transport.

### Problème avec les moteurs lors du téléversement

J'ai rapidement fait face à un gros problème. En effet, lorsque je téléverse un nouveau programme sur la carte Arduino, tous les moteurs font des mouvements ératiques et incontrôllables les faisant se déplacer à leurs positions extrêmes. Ce comportement n'est pas anodin car il risque d'endommager sérieusement les pièces du robot à chaque nouveau code installé.
Ne comprenant pas tout de suite d'où venait le problème j'ai bien failli casser certaines pièces 3D.

Après de nombreuses recherces, il semblerait que ce problème ai lieu car, durant le téléversement, les servos sont alimenter mais ne reçoivent aucune information et donc par défaut se place à l'un des extrêmes de leur position.  
La solution ne pouvait donc pas être résolu au niveau du software.

#### Solution 1

Au niveau du hardware, la solution idéale serait d'installer un interrupteur au niveau de l'alimentation du SCC-32. Celui-ci pourrait être contrôler depuis l'Arduino et donc être seulement une fois que le téléversement est terminé et que la carte est prête à communiquer avec les servos moteurs.  

#### Solution 2

Malheureusement je n'ai pas le matériel à disposition pour cela. Je me suis résolu à un plan B. Tout d'abord, j'ai enlevé le câble reliant le 5V de la carte Arduino à celui du SSC-32 mais j'ai laissé le ground entre les deux. De fait le SSC-32 n'est alimenté que par le bloc d'alimentation et l'Arduino seulement par la connection USB avec l'ordinateur. Lorsque cette connection ne sera plus disponible il faudra envisager la première option afin d'avoir le 5V du bloc d'alimentation pour gérer l'Arduino.

Maintenant, je peux téléverser mon code sur l'Arduino en toute sécurité à partir du moment où le bloc d'alimentation est éteint. Une fois que le téléversement est réussis avec succès, je sais que je peux allumer l'alimentation ce qui va avoir pour effet d'allumer tous les moteurs. Comme la carte Arduino communique directement avec eux il n'y a aucun problème de mouvement.

> WARNING ! Ne surtout pas oublier de débrancher l'alimentation avec chaque téléversement sinon le problème de mouvement ératique sera à nouveau présent.

### Premiers paramétrages des offsets

Afin d'avoir des mouvements identiques sur chaque patte lorsque les angles d'input sont identiques, nous utilisons différents offsets et limites sur chaque servo. Ceux-ci doivent obligatoirement être configurés à la main au préalable.
La méthode la plus efficace que j'ai trouvé est d'utiliser un potentiomètre par servo et ainsi de savoir précisément quelles valeurs correspondent aux maximum et minimum. Je n'ai malheureusement pas eu le temps de finir le circuit permettant de les utiliser donc ce sera pour une prochaine fois.

En revanche, j'ai eu le temps de faire un premier jet des offsets permettant au moins aux servos de tourner dans le même sens. Il faut maintenant les poffiner pour que les mouvements soient identiques.





