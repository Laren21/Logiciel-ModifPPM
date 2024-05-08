#include "image.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Un constructeur qui prend en paramètre les couleurs RGB.
Image::Image(vector<vector<int>> rouge, vector<vector<int>> vert,
             vector<vector<int>> bleu)
{
    if ((rouge.size() != vert.size()) || (rouge.size() != bleu.size()) || vert.size() != bleu.size())
    {
        cerr << ("Les vecteurs de couleur n'ont pas la même taille");
    }
    cout << "Construction d'un objet Image" << endl;
    _rouge = rouge;
    _vert = vert;
    _bleu = bleu;
    _largeur = 4;
    _longueur = 4;
}

Image::Image(const string &nomFichier)
{
    //On va appeler la méthode loadPicture pour charger l'image depuis le fichier
    loadPicture(nomFichier, _rouge, _vert, _bleu);

    // Définir des valeurs par défaut pour la largeur et la hauteur (à ajuster selon vos besoins)
    _largeur = 4;
    _longueur = 4;

    cout << "Construction d'un objet Image a partir du fichier " << nomFichier << endl;
}

void Image::loadPicture(const string &picture, vector<vector<int>> &red,vector<vector<int>> &green,vector <vector<int>> &blue)
{
    //Declaration des variables
    string line; //Pour recuperer les lignes du fichier image au format .ppm, qui est code en ASCII.
    string format; //Pour recuperer le format de l'image : celui-ci doit être de la forme P3
    string name; //Au cas où l'utilisateur se trompe dans le nom de l'image a charger, on redemande le nom.
    int taille;
    vector <int> mypixels; //Pour recuperer les donnees du fichier de maniere lineaire. On repartira ensuite ces donnees dans les tableaux correspondants
    ifstream entree; //Declaration d'un "flux" qui permettra ensuite de lire les donnees de l'image.
    int hauteur; //Pour bien verifier que l'image est carree, et de taille respectant les conditions fixees par l'enonce
    //Initialisation des variables
    name = "images-ppm/" + picture;
    //Permet d'ouvrir le fichier portant le nom picture
    //Ouverture du fichier portant le nom picture
    entree.open(name);
    //On verifie que le fichier a bien été ouvert. Si cela n'est pas le cas, on redemande un nom de fichier valide.
    while (!entree)
    {
        //cin.rdbuf(oldbuf);
        cerr << "Erreur! Impossible de lire de fichier " << name << " ! " << endl;
        cerr << "Redonnez le nom du fichier a ouvrir SVP. Attention ce fichier doit avoir un nom du type nom.ppm." << endl;
        cin >> name;
        entree.open("images-ppm/" + name); //On relance
    }
    //Lecture du nombre definissant le format (ici P3)
    entree >> format;
    //On finit de lire la ligne (caractere d'espacement)
    getline(entree, line);
    //Lecture du commentaire
    getline(entree, line);
    //Lecture des dimensions
    entree >> taille >> hauteur;
    getline(entree, line); //On finit de lire la ligne (caractere d'espacement)
    //On verifie que l'image a une taille qui verifie bien les conditions requises par l'enonce.
    //Si cela n'est pas le cas, on redemande un fichier valide, et ce, tant que necessaire.
    while (format != "P3")
    {
        if (format != "P3")
        {
            cerr << "Erreur! L'image que vous nous avez donnee a un format ne verifiant pas les conditions requises." << endl;
            cerr << "L'image que vous nous avez donnee doit etre codee en ASCII et non en brut." << endl;
        }
        entree.close();
        //On va redemander un nom de fichier valide.
        do
        {
            cerr << "Veuillez redonner un nom de fichier qui respecte les conditions de format et de taille. Attention, ce nom doit etre de la forme nom.ppm." << endl;
            cin >> name;
            entree.open(name); //On relance
        }
        while(!entree);
        //Lecture du nombre definissant le format (ici P3)
        entree >> format;
        getline(entree, line); //On finit de lire la ligne (caractere d'espacement)
        //Lecture du commentaire
        getline(entree, line);
        //Lecture des dimensions
        entree >> taille >> hauteur; //On relance
        getline(entree, line); //On finit de lire la ligne (caractere d'espacement)
    }
    //Lecture de la valeur max
    getline(entree, line);
    //Lecture des donnees et ecriture dans les tableaux :
    //Pour plus de simplicite, on stocke d'abord toutes les donnees dans mypixels.
    //Dans l'ordre de lecture puis ensuite on les repartira dans les differents tableaux.
    //Les donnees stockees dans mypixels sont de la forme RGB RGB RGB ....
    //Il faudra donc repartir les valeurs R correspondant a la composante rouge de l'image.
    //Dans le tableau red, de même pour G et B.
    int pix;
    mypixels.resize(3*taille*hauteur); //Taille fixe : on alloue une fois pour toutes
    for (int i = 0; i < 3*taille*hauteur; i++)
    {
        entree >> pix;
        mypixels[i]=pix;
    }
    //Remplissage des 3 tableaux : on repartit maintenant les valeurs dans les bonnes composantes
    //Comme dans mypixels, les donnees sont stockees de la maniere suivante : RGB RGB RGB, il faut mettre
    //Les valeurs correspondant a la composante rouge dans red, ...
    //Ainsi, les valeurs de la composante rouge correspondent aux valeurs stockes aux indices
    //Congrus a 0 mod 3 dans mypixels, que les valeurs de la composante verte correspond aux valeurs
    //Stockes aux indices sont congrus a 1 mod 3, ...
    //Les valeurs d'une ligne
    int val;
    red.resize(hauteur);
    green.resize(hauteur);
    blue.resize(hauteur);
    for (int i = 0; i < hauteur; i++)
    {
        vector <int> ligneR(taille);
        vector <int> ligneB(taille);  //Les lignes ont toutes la même taille
        vector <int> ligneG(taille);
        for (int j = 0; j < taille; j++)
        {
            val =  mypixels[3*j + 3*taille*i];
            ligneR[j]=val;
            val = mypixels[3*j + 1 + 3*taille*i];
            ligneG[j]=val;
            val = mypixels[3*j + 2 + 3*taille*i];
            ligneB[j]=val;
        }
        red[i]=ligneR;
        green[i]=ligneG;
        blue[i]=ligneB;
    }
    //Informations a l'utilisateur pour dire que tout s'est bien passe
    cout << " L'image " << name << " a bien ete chargee dans les tableaux ." << endl;
    entree.close();
}

//On sauvegarde l'objet cible en l'écrivant dans un flux de sortie.
void Image::savePicture(const string &nomFichier) const
{
    ofstream sortie("images-ppm/" + nomFichier);

    // Vérifier si le fichier est ouvert avec succès.
    if (!sortie)
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier pour l'enregistrement." << endl;
    }

    // Écrire l'en-tête du fichier ppm
    sortie << "P3" << endl;
    sortie << "# Fichier image genere par votre programme" << endl;
    sortie << _largeur << " " << _longueur << endl;
    sortie << "255" << endl;

    // Écrire les valeurs RGB dans le fichier
    for (int i = 0; i < _longueur; i++)
    {
        for (int j = 0; j < _largeur; j++)
        {
            sortie << _rouge[i][j] << " " << _vert[i][j] << " " << _bleu[i][j] << " ";
        }
        sortie << endl;
    }

    cout << "L'image a bien ete enregistree dans le fichier " << nomFichier << endl;
}

//On affiche un objet cible avec cette procédure.
void Image::affichage() const
{
    //Affichage récursif pour chaque composante.
    for (size_t i = 0; i < _rouge.size(); i++)
    {
        for (size_t j = 0; j < _rouge[i].size(); j++)
            cout << _rouge[i][j] << "\t";
    }

    cout << endl;

    for (size_t i = 0; i < _vert.size(); i++)
    {
        for (size_t j = 0; j < _vert[i].size(); j++)
            cout << _vert[i][j] << "\t";
    }

    cout << endl;

    for (size_t i = 0; i < _bleu.size(); i++)
    {
        for (size_t j = 0; j < _bleu[i].size(); j++)
            cout << _bleu[i][j] << "\t";
    }

    cout << endl;
}

//On cherche à donner la couleur d'un pixel dont les coordonnées sont placées en paramètre.
vector<int> Image::CouleurPixel(int i, int j) const
{
    vector<int> couleur;
    int valrouge;
    for (size_t i = 0; i < _rouge.size(); i++)
    {
        for (size_t j = 0; j < _rouge.size(); j++)
        {
            valrouge = _rouge[i][j];
        }
    }
    couleur.push_back(valrouge);

    int valvert;
    for (size_t i = 0; i < _vert.size(); i++)
    {
        for (size_t j = 0; j < _vert.size(); j++)
        {
            valvert = _vert[i][j];
        }
    }
    couleur.push_back(valvert);

    int valbleu;
    for (size_t i = 0; i < _bleu.size(); i++)
    {
        for (size_t j = 0; j < _bleu.size(); j++)
        {
            valbleu = _bleu[i][j];
        }
    }

    couleur.push_back(valbleu);
    return couleur;
}

//On crée une nouvelle image avec uniquement du rouge toute les autres couleurs sont mises en noir.
Image Image::composanteRouge()
{
    vector<vector<int>> vertvide {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    vector<vector<int>> bleuvide {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    Image nouvelleImage(_rouge, vertvide, bleuvide);
    return nouvelleImage;
}

//On recherche un pixel avec les bonnes composantes RGB.
bool Image::Detection(int rouge, int vert, int bleu) const
{
    bool verification;
    for (size_t i = 0; i < _rouge.size(); i++)
    {
        for (size_t j = 0; j < _rouge[i].size(); j++)
        {
            if (_rouge[i][j] == rouge && _vert[i][j] == vert && _bleu[i][j] == bleu)
                verification = true;
        }
    }
    return verification;
}

//On crée un objet image avec différentes nuances de gris.
Image Image::NiveauxGris()
{
    vector<vector<int>> gris;

    for (size_t i = 0; i < _rouge.size(); i++)
    {
        vector<int> ligneGris;

        for (size_t j = 0; j < _rouge[i].size(); j++)
        {
            int niveauGris = (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3;
            ligneGris.push_back(niveauGris);
        }

        gris.push_back(ligneGris);
    }

    Image imageGris(gris, gris, gris);
    return imageGris;
}

//On crée un objet image en noir et blanc.
Image Image::noirEtBlanc(int seuil)
{
    vector<vector<int>> noirBlanc;

    for (size_t i = 0; i < _rouge.size(); i++)
    {
        vector<int> ligneNoirBlanc;

        for (size_t j = 0; j < _rouge[i].size(); j++)
        {
            int niveauGris = (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3;

            int pixelNoirBlanc;
            //On veille à ne pas avoir de valeur négative.
            if (niveauGris <= seuil)
            {
                pixelNoirBlanc = 0;
            }
            else
            {
                pixelNoirBlanc = 255;
            }

            ligneNoirBlanc.push_back(pixelNoirBlanc);
        }

        noirBlanc.push_back(ligneNoirBlanc);
    }

    Image imageNoirBlanc(noirBlanc, noirBlanc, noirBlanc);
    return imageNoirBlanc;
}

//M�thode pour augmenter la luminosit� d'un objet image.
Image Image::luminosityUp(double factor) const
{
    //On va cr�er une copie de l'objet cible avec les m�mes dimensions.
    Image nouvelleImage = *this;

    for (size_t i = 0; i < nouvelleImage._rouge.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._rouge[i].size(); ++j)
        {
            //On va calculer la nouvelle valeur du pixel avec le facteur de luminosit�.
            int newPixelValue = nouvelleImage._rouge[i][j] * factor;

            //On s'assure que la nouvelle valeur ne d�passe pas 255.
            if (newPixelValue > 255)
            {
                nouvelleImage._rouge[i][j] = 255;
            }
            else
            {
                nouvelleImage._rouge[i][j] = newPixelValue;
            }
        }
    }
    for (size_t i = 0; i < nouvelleImage._vert.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._vert[i].size(); ++j)
        {
            int newPixelValue = nouvelleImage._vert[i][j] * factor;
            if (newPixelValue > 255)
            {
                nouvelleImage._vert[i][j] = 255;
            }
            else
            {
                nouvelleImage._vert[i][j] = newPixelValue;
            }
        }
    }
    for (size_t i = 0; i < nouvelleImage._bleu.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._bleu[i].size(); ++j)
        {
            int newPixelValue = nouvelleImage._bleu[i][j] * factor;
            if (newPixelValue > 255)
            {
                nouvelleImage._bleu[i][j] = 255;
            }
            else
            {
                nouvelleImage._bleu[i][j] = newPixelValue;
            }
        }
    }
    return nouvelleImage;
}

//M�thode pour diminuer la luminosit� d'un objet image.
Image Image::luminosityDown(double facteur) const
{
    //On va cr�er une copie de l'objet cible avec les m�mes dimensions.
    Image nouvelleImage = *this;

    for (size_t i = 0; i < nouvelleImage._rouge.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._rouge[i].size(); ++j)
        {
            //On va calculer la nouvelle valeur du pixel avec le facteur de luminosit�.
            int newPixelValue = nouvelleImage._rouge[i][j] * (facteur);
            //On s'assure que la nouvelle valeur ne soit pas inf�rieur � 0.
            if (newPixelValue < 0)
            {
                nouvelleImage._rouge[i][j] = 100;
            }
            else
            {
                nouvelleImage._rouge[i][j] = newPixelValue;
            }
        }
    }
    for (size_t i = 0; i < nouvelleImage._vert.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._vert[i].size(); ++j)
        {
            int newPixelValue = nouvelleImage._vert[i][j] * (facteur);
            if (newPixelValue < 0)
            {
                nouvelleImage._vert[i][j] = 100;
            }
            else
            {
                nouvelleImage._vert[i][j] = newPixelValue;
            }
        }
    }
    for (size_t i = 0; i < nouvelleImage._bleu.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._bleu[i].size(); ++j)
        {
            int newPixelValue = nouvelleImage._bleu[i][j] * (facteur);
            if (newPixelValue < 0)
            {
                nouvelleImage._bleu[i][j] = 100;
            }
            else
            {
                nouvelleImage._bleu[i][j] = newPixelValue;
            }
        }
    }
    return nouvelleImage;
}

//M�thode pour augmenter le contraste de l'image.
Image Image::contrasteUp(double facteur) const
{
    //On va cr�er une copie de l'objet cible avec les m�mes dimensions.
    Image nouvelleImage = *this;

    for (size_t i = 0; i < nouvelleImage._rouge.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._rouge[i].size(); ++j)
        {
            //On applique la formule en veillant � ce que les valeurs restent entre 0 et 255 inclus.
            double nouvelleValeur = 128.0 + (facteur) * (nouvelleImage._rouge[i][j] - 128.0);
            if (nouvelleValeur > 255.0)
            {
                nouvelleImage._rouge[i][j] = 255;
            }
            else if (nouvelleValeur < 0.0)
            {
                nouvelleImage._rouge[i][j] = 0;
            }
            else
            {
                nouvelleImage._rouge[i][j] = int(nouvelleValeur);
            }
        }
    }
    for (size_t i = 0; i < nouvelleImage._vert.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._vert[i].size(); ++j)
        {
            double nouvelleValeur = 128.0 + (facteur) * (nouvelleImage._vert[i][j] - 128.0);
            if (nouvelleValeur > 255.0)
            {
                nouvelleImage._vert[i][j] = 255;
            }
            else if (nouvelleValeur < 0.0)
            {
                nouvelleImage._vert[i][j] = 0;
            }
            else
            {
                nouvelleImage._vert[i][j] = int(nouvelleValeur);
            }
        }
    }
    for (size_t i = 0; i < nouvelleImage._bleu.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._bleu[i].size(); ++j)
        {
            double nouvelleValeur = 128.0 + (facteur) * (nouvelleImage._bleu[i][j] - 128.0);
            if (nouvelleValeur > 255.0)
            {
                nouvelleImage._bleu[i][j] = 255;
            }
            else if (nouvelleValeur < 0.0)
            {
                nouvelleImage._bleu[i][j] = 0;
            }
            else
            {
                nouvelleImage._bleu[i][j] = int(nouvelleValeur);
            }
        }
    }
    return nouvelleImage;
}

//M�thode pour diminuer le contraste de l'image.
Image Image::contrasteDown(double facteur) const
{
    //On va cr�er une copie de l'objet cible avec les m�mes dimensions.
    Image nouvelleImage = *this;

    for (size_t i = 0; i < nouvelleImage._rouge.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._rouge[i].size(); ++j)
        {
            //On applique la formule en veillant � ce que les valeurs restent entre 0 et 255 inclus.
            double nouvelleValeur = 128.0 + (facteur) * (nouvelleImage._rouge[i][j] - 128.0);
            if (nouvelleValeur > 255.0)
            {
                nouvelleImage._rouge[i][j] = 255;
            }
            else if (nouvelleValeur < 0.0)
            {
                nouvelleImage._rouge[i][j] = 0;
            }
            else
            {
                nouvelleImage._rouge[i][j] = int(nouvelleValeur);
            }
        }
    }
    for (size_t i = 0; i < nouvelleImage._vert.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._vert[i].size(); ++j)
        {
            double nouvelleValeur = 128.0 + (facteur) * (nouvelleImage._vert[i][j] - 128.0);
            if (nouvelleValeur > 255.0)
            {
                nouvelleImage._vert[i][j] = 255;
            }
            else if (nouvelleValeur < 0.0)
            {
                nouvelleImage._vert[i][j] = 0;
            }
            else
            {
                nouvelleImage._vert[i][j] = int(nouvelleValeur);
            }
        }
    }
    for (size_t i = 0; i < nouvelleImage._bleu.size(); ++i)
    {
        for (size_t j = 0; j < nouvelleImage._bleu[i].size(); ++j)
        {
            double nouvelleValeur = 128.0 + (facteur) * (nouvelleImage._bleu[i][j] - 128.0);
            if (nouvelleValeur > 255.0)
            {
                nouvelleImage._bleu[i][j] = 255;
            }
            else if (nouvelleValeur < 0.0)
            {
                nouvelleImage._bleu[i][j] = 0;
            }
            else
            {
                nouvelleImage._bleu[i][j] = int(nouvelleValeur);
            }
        }
    }
    return nouvelleImage;
}


//On va créer une copie de l'image rogné de nb colonnes de droite.
Image Image::rognerD (int nb)const
{
    Image NouvelleImage (_rouge, _vert, _bleu);
    for (int i = 0 ; i<_rouge.size() ; i++)
    {
        for (int cpt = 0 ; cpt<nb ; cpt++)
        {
            NouvelleImage._rouge[i].pop_back();
            NouvelleImage._vert[i].pop_back();
            NouvelleImage._bleu[i].pop_back();
        }
    }
    return NouvelleImage;
}

//On va créer une copie de l'image rogné sur les lignes de gauche.
Image Image::rognerG (int nb)const
{
    vector<vector<int>> CP_rouge(_rouge.size());
    vector<vector<int>> CP_vert(_rouge.size());
    vector<vector<int>> CP_bleu(_rouge.size());

    for ( int i = 0 ; i < _rouge.size() ; i++)
    {
        for (int j = nb ; j < _rouge[0].size() ; j++)
        {
            CP_rouge[i].push_back(_rouge[i][j]);
            CP_vert[i].push_back(_vert[i][j]);
            CP_bleu[i].push_back(_bleu[i][j]);
        }
    }
    Image NouvelleImage(CP_rouge, CP_vert, CP_bleu);
    return NouvelleImage;
}

//On va créer une copie de l'image rogné de nb lignes du bas.
Image Image::rognerB (int nb)const
{
    Image NouvelleImage (_rouge, _vert, _bleu);
    for (int i = 0 ; i<nb ; i++)
    {
        NouvelleImage._rouge.pop_back();
        NouvelleImage._vert.pop_back();
        NouvelleImage._bleu.pop_back();
    }
    return NouvelleImage;
}

//On va créer une copie de l'image rogné sur les lignes du haut.
Image Image::rognerH (int nb)const
{
    vector<vector<int>> CP_rouge(_rouge.size()-nb);
    vector<vector<int>> CP_vert(_rouge.size()-nb);
    vector<vector<int>> CP_bleu(_rouge.size()-nb);

    for (int i = nb ; i < _rouge.size() ; i++)
    {
        for (int j = 0 ; j < _rouge[0].size() ; j++)
        {
            CP_rouge[i-nb].push_back(_rouge[i][j]);
            CP_vert[i-nb].push_back(_vert[i][j]);
            CP_bleu[i-nb].push_back(_bleu[i][j]);
        }
    }
    Image NouvelleImage(CP_rouge, CP_vert, CP_bleu);
    return NouvelleImage;
}

Image Image::rotationD() const
{
    //La nouvelle image aura les dimensions inversées.
    int newHaut = _rouge[0].size();
    int newLarg = _rouge.size();

    //Initialisation des nouvelles matrices de couleur avec des pixels nuls.
    vector<vector<int>> newRouge(newHaut, vector<int>(newLarg, 0));
    vector<vector<int>> newVert(newHaut, vector<int>(newLarg, 0));
    vector<vector<int>> newBleu(newHaut, vector<int>(newLarg, 0));

    //Transfert des pixels en effectuant la rotation.
    for (int i = 0; i < _rouge.size(); ++i)
    {
        for (int j = 0; j < _rouge[i].size(); ++j)
        {
            newRouge[j][newLarg - 1 - i] = _rouge[i][j];
            newVert[j][newLarg - 1 - i] = _vert[i][j];
            newBleu[j][newLarg - 1 - i] = _bleu[i][j];
        }
    }
    //Création d'une nouvelle image avec les pixels rotatifs.
    return Image(newRouge, newVert, newBleu);
}

//La méthode pour effectuer la rotation de l'image de 90 degrés vers la gauche.
Image Image::rotationG() const
{
    //La nouvelle image aura les dimensions inversées.
    int newHaut = _rouge[0].size();
    int newLarg = _rouge.size();

    //Initialisation des nouvelles matrices de couleur avec des pixels nuls.
    vector<vector<int>> newRouge(newHaut, vector<int>(newLarg, 0));
    vector<vector<int>> newVert(newHaut, vector<int>(newLarg, 0));
    vector<vector<int>> newBleu(newHaut, vector<int>(newLarg, 0));

    //Transfert des pixels en effectuant la rotation.
    for (int i = 0; i < _rouge.size(); ++i)
    {
        for (int j = 0; j < _rouge[i].size(); ++j)
        {
            newRouge[newHaut - 1 - j][i] = _rouge[i][j];
            newVert[newHaut - 1 - j][i] = _vert[i][j];
            newBleu[newHaut - 1 - j][i] = _bleu[i][j];
        }
    }
    //Création d'une nouvelle image avec les pixels rotatifs.
    return Image(newRouge, newVert, newBleu);
}

//La méthode pour effectuer le retournement horizontal de l'image.
Image Image::retournementH() const
{
    int hauteur = _rouge.size();
    int largeur = _rouge[0].size();

    vector<vector<int>> newRouge(hauteur, vector<int>(largeur, 0));
    vector<vector<int>> newVert(hauteur, vector<int>(largeur, 0));
    vector<vector<int>> newBleu(hauteur, vector<int>(largeur, 0));

    for (int i = 0; i < hauteur; ++i)
    {
        for (int j = 0; j < largeur; ++j)
        {
            newRouge[i][largeur - 1 - j] = _rouge[i][j];
            newVert[i][largeur - 1 - j] = _vert[i][j];
            newBleu[i][largeur - 1 - j] = _bleu[i][j];
        }
    }
    return Image(newRouge, newVert, newBleu);
}

//La méthode pour effectuer le retournement vertical de l'image.
Image Image::retournementV() const
{
    int hauteur = _rouge.size();
    int largeur = _rouge[0].size();

    vector<vector<int>> newRouge(hauteur, vector<int>(largeur, 0));
    vector<vector<int>> newVert(hauteur, vector<int>(largeur, 0));
    vector<vector<int>> newBleu(hauteur, vector<int>(largeur, 0));

    for (int i = 0; i < hauteur; ++i)
    {
        for (int j = 0; j < largeur; ++j)
        {
            newRouge[hauteur - 1 - i][j] = _rouge[i][j];
            newVert[hauteur - 1 - i][j] = _vert[i][j];
            newBleu[hauteur - 1 - i][j] = _bleu[i][j];
        }
    }
    return Image(newRouge, newVert, newBleu);
}

//La méthode pour effectuer l'agrandissement de l'image. (Non fonctionnel)
Image Image::agrandissement(int facteur) const
{
    if (facteur <= 0)
    {
        throw invalid_argument("Le facteur d'agrandissement doit etre un entier positif.");
    }

    int hauteur = _rouge.size();
    int largeur = _rouge[0].size();

    vector<vector<int>> newRouge(hauteur * facteur, vector<int>(largeur * facteur, 0));
    vector<vector<int>> newVert(hauteur * facteur, vector<int>(largeur * facteur, 0));
    vector<vector<int>> newBleu(hauteur * facteur, vector<int>(largeur * facteur, 0));

    for (int i = 0; i < hauteur; ++i)
    {
        for (int j = 0; j < largeur; ++j)
        {
            for (int fi = 0; fi < facteur; ++fi)
            {
                for (int fj = 0; fj < facteur; ++fj)
                {
                    newRouge[i * facteur + fi][j * facteur + fj] = _rouge[i][j];
                    newVert[i * facteur + fi][j * facteur + fj] = _vert[i][j];
                    newBleu[i * facteur + fi][j * facteur + fj] = _bleu[i][j];
                }
            }
        }
    }
    return Image(newRouge, newVert, newBleu);
}

//La méthode pour effectuer le rétrécissement de l'image. (Non fonctionnel)
Image Image::retrecissement(int facteur) const
{
    if (facteur <= 0)
    {
        throw invalid_argument("Le facteur de retrecissement doit etre un entier positif.");
    }

    int hauteur = _rouge.size();
    int largeur = _rouge[0].size();

    vector<vector<int>> newRouge(hauteur / facteur, vector<int>(largeur / facteur, 0));
    vector<vector<int>> newVert(hauteur / facteur, vector<int>(largeur / facteur, 0));
    vector<vector<int>> newBleu(hauteur / facteur, vector<int>(largeur / facteur, 0));

    for (int i = 0; i < hauteur; i += facteur)
    {
        for (int j = 0; j < largeur; j += facteur)
        {
            int sumRouge = 0, sumVert = 0, sumBleu = 0;
            int count = 0;

            for (int fi = 0; fi < facteur; ++fi)
            {
                for (int fj = 0; fj < facteur; ++fj)
                {
                    int row = i + fi;
                    int col = j + fj;

                    if (row < hauteur && col < largeur)
                    {
                        sumRouge += _rouge[row][col];
                        sumVert += _vert[row][col];
                        sumBleu += _bleu[row][col];
                        count++;
                    }
                }
            }

            newRouge[i / facteur][j / facteur] = sumRouge / count;
            newVert[i / facteur][j / facteur] = sumVert / count;
            newBleu[i / facteur][j / facteur] = sumBleu / count;
        }
    }
    return Image(newRouge, newVert, newBleu);
}
