# Projet de création d'un logiciel pour modifier des images  

<p align="center">
    <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" alt="Logo C++" style="width:600px;height:600px;">
</p>  

## Décomposition des fichiers    
* Dans le dossier principal on trouve directement les codes sources C++ dans plusieurs fichiers différents.  
* Dans le dossier principal les codes sources sont reliés par différents fichiers header au fichier main qui gère le menu.  
* Les images qui peuvent être utilisées sont disponibles dans le sous-dossier "Images-ppm".  

## Déroulement du projet   

### Répartition des tâches :  
Dans ce projet l'équipe est constituée de 2 personnes. Chacun s'occupe de développer ses fonctionnalités dans des fichiers sources en C++ différents. Puis les codes sont mis en commun et les ajustements finals faits en équipe. Une personne reste chargée de la validation des méthodes. L'autre personne s'occupe du côté utilisateur (création du menu etc...).  

### Conception du logiciel :  
Le logiciel devra être réalisé en C++ et comportera un main avec des tests pour s'assurer de la fiabilité des méthodes incrémentées. Un autre main sera utiliser pour la création d'un menu qui sera cette fois-ci utilisée par l'utilisateur. L'utilisateur devra choisir une image à modifier, choisir une méthode à appeler sur cette image, puis sauvegarder. La visualisation des modifications peut être faite en ouvrant les images dans le fichier "Images-ppm" sur des logiciels comme GIMP par exemple.  

### Réalisation du logiciel :  
Les tests sont effectués en même temps que la création des méthodes pour être plus rapide dans le déroulement global du projet, mais aussi éviter les oublies eventuelles. Chaque membre se voit attribuer un ensemble de méthodes à développer. Une fois le développement effectué un membre créer en parallèle les tests. Une fois que tous les tests sont validés un autre membre est chargées d'incrémenter dans le menu les méthodes associé aux tests fraichement validés.  

## Notice détaillé d'utilisation 

### Utilisation du programme :  
Ce programme permet d'effectuer diverses opérations sur une image à partir d'un fichier image spécifié. Les opérations comprennent l'affichage de l'image, l'extraction de la couleur d'un pixel, la détection d'une couleur spécifique, et plusieurs transformations telles que la conversion en noir et blanc, l'ajustement de la luminosité, du contraste, le rognage, la rotation et le retournement.

### Prérequis :  
Un compilateur C++ compatible avec les bibliothèques standard C++ est nécessaire. Les fichiers d'en-tête "outil.h" et "image.h" doivent être inclus dans le même répertoire que le programme principal.  

Pour la compilation vous pouvez utiliser le compilateur g++, par exemple :

> bash :

    g++ votre_programme.cpp -o votre_programme

!!! LES IMAGES IMPORTEE ET ENREGISTREE DOIVENT ETRE SITUEE A L'EMPLACEMENT SUIVANT : ./images-ppm/  

### L'exécution :   
Exécutez le programme compilé. Puis saisissez le nom du fichier image que vous souhaitez traiter.  

### Le menu principal :  
> Le programme propose un menu interactif avec les options suivantes :  

    1.Afficher l'image.  
    2.Extraire la couleur d'un pixel spécifique.  
    3.Détecter la présence d'une couleur spécifique.  
    4.Convertir l'image en composante rouge.  
    5.Convertir l'image en niveaux de gris.  
    6.Convertir l'image en noir et blanc.  
    7.Augmenter la luminosité de l'image.  
    8.Diminuer la luminosité de l'image.  
    9.Augmenter le contraste de l'image.  
    10.Diminuer le contraste de l'image.  
    11.Rogner l'image à droite.  
    12.Rogner l'image à gauche.  
    13.Rogner l'image en bas.  
    14.Rogner l'image en haut.  
    15.Faire une rotation à droite.  
    16.Faire une rotation à gauche.  
    17.Effectuer un retournement horizontal.  
    18.Effectuer un retournement vertical.  
    19.Agrandir l'image.  
    20.Rétrécir l'image.  

### Enregistrement des modifications :  
À la fin des modifications, le programme demande si vous souhaitez enregistrer les changements. Si oui, spécifiez le nom du fichier de sortie.  
