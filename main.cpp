/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "outil.h"
#include "image.h"

using namespace std;

int main(){

    string fichierIn;
    cout << "Saisissez le nom du fichier a ouvrir : ";
    cin >> fichierIn;

    Image img (fichierIn);

    int choix;
    do
    {
        //On afficher le menu.
        afficherMenu();

        //On saisir le choix de l'utilisateur.
        choix = saisirChoix();

        //Traitement du choix de l'utilisateur.
        switch (choix){
        case 1:
            //Execution de la fonction
            img.affichage();
            break;
        case 2:
        {
            //Execution de la fonction
            int pixX, pixY;
            cout << "Saisissez un pixel dont vous souhaitez trouver la couleur (coordonnee x) : ";
            cin >> pixX;
            cout << "Saisissez un pixel dont vous souhaitez trouver la couleur (coordonnee y) : ";
            cin >> pixY;
            vector<int> resultat = img.CouleurPixel(pixX, pixY);
            cout << "Valeur Rouge : " << resultat[0] << endl;
            cout << "Valeur Vert : " << resultat[1] << endl;
            cout << "Valeur Bleu : " << resultat[2] << endl;
            break;
        }
        case 3:
            //Execution de la fonction
            int rdet, vdet, bdet;
            cout << "Saisissez une valeur de rouge pour la detection : ";
            cin >> rdet;
            cout << "Saisissez une valeur de vert pour la detection : ";
            cin >> vdet;
            cout << "Saisissez une valeur de bleu pour la detection : ";
            cin >> bdet;
            if (img.Detection(rdet, vdet, bdet))
                cout << "L'image possede la couleur recherchee";
            else
                cout << "L'image ne possede pas la couleur recherchee";
            break;
        case 4:
            //Execution de la fonction
            cout << "Voici l'image en rouge :" << endl;
            img = img.composanteRouge();  // Met jour l'image avec la composante rouge
            img.affichage();
            break;
        case 5:
            //Execution de la fonction
            cout << "Voici l'image en gris :" << endl;
            img = img.NiveauxGris();  // Met jour l'image avec les niveaux de gris
            img.affichage();
            break;
        case 6:
            //Execution de la fonction
            int seuil;
            cout << "Saisissez un seuil pour distinguer les pixels noirs des blancs : ";
            cin >> seuil;
            cout << "Voici l'image en noir et blanc :" << endl;
            img = img.noirEtBlanc(seuil);  // Met jour l'image en noir et blanc
            img.affichage();
            break;

            break;
        case 7:
            //Execution de la fonction
            double LumUp;
            cout << "Saisissez un facteur d'augmentation de la luminosite (sup a 1) : ";
            cin >> LumUp;
            img = img.luminosityUp(LumUp);
            img.affichage();
            break;
        case 8:
            //Execution de la fonction
            double LumDown;
            cout << "Saisissez une factor de diminution de la luminosite (inf a 1) : ";
            cin >> LumDown;
            img = img.luminosityDown(LumDown);
            img.affichage();
            break;
        case 9:
            //Execution de la fonction
            double conUp;
            cout << "Saisissez une facteur d'augmentaion du contraste (sup a 1) : ";
            cin >> conUp;
            img = img.contrasteUp(conUp);
            img.affichage();
            break;
        case 10:
            //Execution de la fonction
            double conDown;
            cout << "Saisissez un facteur de diminution du contraste (inf a 1) : ";
            cin >> conDown;
            img = img.contrasteDown(conDown);
            img.affichage();
            break;
        case 11:
            //Execution de la fonction
            img = img.rotationD();
            img.affichage();
            break;
        case 12:
            //Execution de la fonction
            img = img.rotationG();
            img.affichage();
            break;
        case 13:
            //Execution de la fonction
            img = img.retournementH();
            img.affichage();
            break;
        case 14:
            //Execution de la fonction
            img = img.retournementV();
            img.affichage();
            break;
        case 15:
            //Execution de la fonction
            int rpixD;
            cout << "De combien de pixel voulez-vous rogner l'image ? : ";
            cin >> rpixD;
            img = img.rognerD(rpixD);
            img.affichage();
            break;
        case 16:
            //Execution de la fonction
            int rpixG;
            cout << "De combien de pixel voulez-vous rogner l'image ? : ";
            cin >> rpixG;
            img = img.rognerG(rpixG);
            img.affichage();
            break;
        case 17:
            //Execution de la fonction
            int rpixB;
            cout << "De combien de pixel voulez-vous rogner l'image ? : ";
            cin >> rpixB;
            img = img.rognerD(rpixB);
            img.affichage();
            break;
        case 18:
            //Execution de la fonction
            int rpixH;
            cout << "De combien de pixel voulez-vous rogner l'image ? : ";
            cin >> rpixH;
            img = img.rognerD(rpixH);
            img.affichage();
            break;
       }
    }
    while (recommencer());
    string repSave;

    //Bloc conditionnel pour demander à l'utilisateur ce qu'il souhaite faire.
    do{
        cout << "Souhaitez-vous enregistrer vos modifications ? (oui/non) : ";
        cin >> repSave;
    }while (repSave != "oui" && repSave !="non");
        if (repSave=="oui"){
            string fichierOut;
            cout << "Saisissez le nom du fichier dans lequel vous voulez sauvegarder les changements : ";
            cin >> fichierOut;
            img.savePicture(fichierOut);
        }
        else {
            cout << "Arret du programme...";
        }

    return 0;
}
*/
