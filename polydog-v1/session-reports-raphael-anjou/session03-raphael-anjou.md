# Séance 3 : 03/11/2021 --> 06/01/2022

Le travail que j'ai fait entre les deux dernières séances n'est pas très conséquent... J'ai tout de même travaillé sur
quelques points

### Design du robot

&nbsp;&nbsp;&nbsp;&nbsp;Nous avons beaucoup discuté avec Hugo de ce que l'on pourrait faire comme structure pour la partie
supérieure du robot. Hugo a donc proposé l'idée de faire des côtes sur le robot (cf. image). Je lui ai donc fait remarquer
que les côtes d'un chien n'était pas situé de cette façon. Notre design aurait donc montré une certaine ignorance concernant
l'anatomie d'un chien. De plus, cela aurait rajouté beaucoup de poids pas forcément nécessaire et déplacer le centre de
gravité du robot vers le haut. Ce décalage aurait eu pour effet de le rendre plus instable et la gestion de son équilibre
aurait été bien plus complexe.

![](seance03_illustrations/seance03_illustation01.PNG)

### Assemblage du robot dans OnShape et création d'animation

&nbsp;&nbsp;&nbsp;&nbsp;Une fonctionnalité majeure de OnShape est celle des animations. Elle permet de voir les pièces
bouger et ainsi mieux comprendre les problèmes liés au design que l'on pourrait rencontrer. J'ai ainsi essayé pendant
plusieurs heures de gérer les relations entre les pièces, leurs contraintes et la façon dont elles intéragissaient entre
elles mais cela s'est révélé infructueux au niveau des engrenages. Je n'ai pas réussi à les connecter de tel sorte que
seulement la pièce de la patte concernée tourne en même temps que l'engrenage.

&nbsp;&nbsp;&nbsp;&nbsp;Le comportement actuel est démontré dans la vidéo ci-dessous. Le premier engrenage est censé déplacer
toute la patte en fonction de sa rotation. Ensuite, lorsque je sélectionne la pièce orange il faudrait seulement le "tendon"
et "tibia" se déplace (pièce bleu foncé et pièce très fine bleu ciel). Enfin, lorsque je sélectionne la pièce jaune de la
"hance" il faudrait que toute la patte bouge sans que la pièce orange ni le "tibia" ni le "tendon" ne bouge.

![](seance03_illustrations/seance03_illustration02.gif)

### Prochain objectif

&nbsp;&nbsp;&nbsp;&nbsp;Mon prochain objectif est d'écrire un petit bout de code pour qu'on puisse tester la patte avec
des moteurs une fois qu'elle sera imprimée en 3D. L'impression a été lancée vendredi donc nous pourrons la récupérer dès
le lundi 10/01/2022.