# Séance du 23/02/2022

## Adaptation du code pour le nouveau controleur de servo moteur

Pour envoyer une commande à un servo branché sur le pin 4, pour qu'il aille à un angle de 90 degré en 500 millisecondes, on écrit :
```c++
//Code en Arduino
#4P1000T500;
```

1. ### `CustomServos`

De plus, dans la classe CustomServos, nous n'avons plus la nécessité d'attacher les servos à un pin particulier (~~servo_lambda.attach(4)~~).

J'ai alors modifié la classe CustomServos en y ajoutant les fonctions suivantes :

```c++
void CustomServos::move(int position, int time)
{
  Serial.print("#");
  Serial.print(this->_pin);
  Serial.print(" P");
  Serial.print(position);
  Serial.print(" T");
  Serial.println(time);
  delay(time);
}

// Modification de la fonction write, pour que l'on puisse garder notre code avec des angles compris entre 0 et 180 degré, par comodité

void CustomServos::write(int angle)
{
  this->move(map(angle, 0, 180, 500, 2500), 0);
}
```

## Problème de réglage

1. Nous nous sommes rendu compte que le servo controller n'était pas autonome et ne pouvait pas stocker en mémoire les commandes. Nous avions donc besoin d'une carte Arduino pour faire l'intermédiaire et de transmettre les infos sur le serial;

Voici le montage :

<figure align="center">
  <img src="montage.png" width="500" title="montage.png"/>
</figure>

2. Ensuite, deuxième soucis, le code se transférait successfullement sur la carte UNO mais cette dernière ne relayait pas l'information au servo controller. Les led RX et TX demeuraient éteinte. Après des heures et des heures de recherches en vain, il suffisait en réalité de recréer un projet sur PlateformIO et de transférer le code, et ça a marché.

## Impression des pièces

En mettant la pièce des côtes du bas dans le slicer de l'imprimante, le poids serait de 230gr, je l'ai donc modifié ainsi avant impression :

<figure align="center">
  <img src="cotelegere.png" width="500" title="cote plus légère.png"/>
</figure>

J'ai modifié également les bras de maintien des épaules (ou plus logiquement la colonne vertebrale), en y perçant son centre :

<figure align="center">
  <img src="trou.png" width="500" title="trou au centre.png"/>
</figure>

J'ai rajouté également deux clips pour les cables pour tester si cela fonctionne mais pour le moment j'en suis pas très convaincu.

## Assemblage du nouveau corps

Nous avons commencé par insérer des insert dans le nouveau corps, une étape délicate, qui n'a pas été filmé. Le principe est de faire chauffer le plastique autour de l'insert avec une panne de fer à souder. L'insert descend dans la matière plastique jusqu'à ne plus dépasser de la surface. Il faut être très attentif à ce que l'insert se place droit et qu'il ne soit pas décalé, sinon la vis ne rentre pas :

<figure align="center">
  <img src="insert.png" width="500" title="insert.png"/>
</figure>

Puis nous avons démonté l'ancien corps de robot pour y extraire les 4 pattes :

<figure align="center">
  <img src="demontage-robot.png" width="500" title="demontage-robot.png"/>
</figure>

Lorsque j'ai pu assemblé la pièce 3D des côtes du bas et le ssc32-servo controller, j'étais très content parce que l'emboîtement s'est fait parfaitement :

<figure align="center">
  <img src="ssc32taille.jpeg" width="500" title="ssc32taille.jpeg"/>
</figure>

Nous avons ensuite continué l'assemblage entre les deux pièces qui viennent maintenir les boitier de servo-moteurs que j'appelle les bras avec les côtes du bas et le support de fixation des moteurs centraux. Nous avons dû bien évidemment poncer certaines surface de pièce 3D. J'ai oublié de prendre en compte la marge d'erreur de l'imprimante 3D qui est de environ 0.4 mm. Cette imprecision reportée sur plusieurs couche de matière entraîne des écarts de 1.3 mm :

<figure align="center">
  <img src="Montageducorps.jpeg" width="500" title="Montageducorps.jpeg"/>
</figure>

## Problèmes rencontrés

Premier soucis : mettre les insert dans le corps nous a été très compliqué, nous avons eu beaucoup d'erreur. 

Nous avons pu les résoudre en retouchant l'insert et en refondant le plastique pour replacer convenablement l'insert. Parfois, nous avons dû grossir le trou de la vis pour que l'alignement entre le pas de vis et l'insert soit plus optimal.

Deuxième soucis : nous avons cassé à moitié le bras orange au niveau où on place les vis parce que le design à ce niveau n'est pas assez épais. Avec un peu de colle ultra-forte, le problème est contourné. Les vis qui viennent maintenir l'ensemble renforce sa solidité.

<figure align="center">
  <img src="pièce_cassée.jpeg" width="500" title="pièce_cassée.jpeg"/>
</figure>  

Troisième soucis : nous avons cassé une autre pièce du montage, les côtes du bas.

 Explication : nous avons placés un insert sur un endroit délicat et pas très épais.
 
  Nous avons visser l'ensemble pour tester le pas de vis, mais en dévissant pour continuer le montage, l'insert n'était plus bloqué dans le plastique, on a donc forcé dessus pour faire sortir la vis. Un bout de la pièce est venu avec la vis. Mais c'est pas grave, une fois l'ensemble vissé ce n'est pas très génant :

<figure align="center">
  <img src="Nouveau_robot_pret.jpeg" width="500" title="Nouveau_robot_pret.jpeg"/>
</figure>  




