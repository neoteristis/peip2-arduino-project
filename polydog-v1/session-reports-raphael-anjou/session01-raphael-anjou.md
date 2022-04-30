# Séance 1 : 23/11/2021 --> 02/12/2021

&nbsp;&nbsp;&nbsp;&nbsp;Le travail compris dans la séance 0 correspond au travail préliminaire effectué avec la première
séance en classe avec les enseignants.

### Information supplémentaire

&nbsp;&nbsp;&nbsp;&nbsp;Pour cette première partie du projet, nous n'avions pas encore réparti les tâches précisément et
avons tous les deux travaillés sur quasi-tous les sujets ensemble. Toutefois, Hugo s'est principalement concentré sur la
partie modélisation tandis que de mon côté, j'ai fait de nombreuses recherches sur la partie programmation.

### Étape 1 : Choix du projet

&nbsp;&nbsp;&nbsp;&nbsp;Hugo et moi-même souhaitions réaliser un robot capable de se déplacer et pouvant être téléguidé.
Très impressionné par le robot chien **Spot** de ***Boston Dynamics***, nous avons tout d'abord recherché si d'autres 
personnes avaient eu la même idée que nous et avaient réalisé des versions réduites de ce robot. 
Bien évidemment, des dizaines de projets similaires existent sur Internet. Cela nous a rassuré dans notre idée et nous a
motivé à avancer. C'était décidé, nous allions faire un robot chien !

### Étape 2 : Création et mise en place du github

&nbsp;&nbsp;&nbsp;&nbsp;Avant d'aller plus loin dans nos recherches, nous avons décidé de mettre en place au plus vite 
un repository github fonctionnel afin de pouvoir se partager facilement nos recherches. Nous utilisons aussi un groupe
discord dédié au projet Arduino.

La structure actuelle est la suivante : 

```
.
+-- docs
|   +-- cahier_des_charges.md
|   +-- liste_du_materiel.md
|   +-- masson_presentation_deroulement_projet.pdf
|   +-- masson_propositions_projets.pdf
|   +-- masson_tuto_github.pdf
+-- miniature_robot_parts
+-- rapports_seances_hugo_durand
+-- rapports_seances_raphael_anjou
+-- research
+-- robot_parts
+-- src
+-- test
+-- .gitattributes
+-- .gitignore
+-- CMakeLists.txt
+-- README.md
```

### Étape 3 : Création d'une milestone dans github ainsi que plusieurs issues
&nbsp;&nbsp;&nbsp;&nbsp;Nous avons créé une milestone dans github intitulée `Documents, research and setup of the project`.
Dans cette milestone, 10 issues ont été créées afin de lister les tâches nécessaires à faire avant même la première séance
de cours.

### Étape 4 : Recherches générales sur le projet

&nbsp;&nbsp;&nbsp;&nbsp;Cette étape nous a permis de se faire une idée globale des difficultés et challenges techniques
que nous allions rencontrer. Nous avons ainsi étudié le design de nombreux robots disponibles en ligne que ce soit au
niveau du fonctionnement, du design ou des matériaux utilisés.

&nbsp;&nbsp;&nbsp;&nbsp;Parmi nos investigations, Hugo a trouvé la chaîne Youtube de ***Loki Le Dev***. Celui-ci est en
train de réaliser un projet similaire au nôtre, mais dans des envergures bien plus grandes. Hugo l'a contacté et Loki a
été très cordial durant nos échanges et nous a même donné accès aux fichiers 3D d'une jambe de son robot.

&nbsp;&nbsp;&nbsp;&nbsp;Nous avons aussi fait des recherches techniques notamment sur les différents mécanismes permettant
de faire bouger une jambe. Il semble judicieux d'après ce que nous avons trouvé d'utiliser la technologie du "parallélogramme"
qui permet de garder les moteurs au niveau du corps du robot. Contrairement à d'autres méthodes qui nécessitent d'avoir
un moteur au niveau du genou, mais cela nous paraissait trop complexe.

&nbsp;&nbsp;&nbsp;&nbsp;Les recherches sur les algorithmes ont aussi commencés. Ainsi, nous allons probablement travailler
sur un programme capable de faire du "inverse kinematic" car celui-ci est plus simple et efficace que le "forward kinematic".
Nous avons aussi trouvé des exemples de simulations de robot permettant d'entraîner virtuellement notre robot à se déplacer
sur différents terrains. Enfin, j'ai fait des recherches sur la façon dont on pouvait adapter les signaux PWM envoyés aux
moteurs pour que leurs mouvements soient plus naturels et plus fluides.

