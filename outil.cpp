#include <iostream>
#include <fstream>
#include <string>
#include "outil.h"

using namespace std;

//Sous-programme pour saisir le nom du fichier image au format ppm.
string saisirNomFichier()
{
    string nomFichier;
    cout << "Entrez le nom du fichier image au format ppm : ";
    cin >> nomFichier;
    return nomFichier;
}

//Sous-programme pour afficher le menu des fonctionnalités.
void afficherMenu()
{
    cout << "-------- Menu : --------\n";
    cout << "1. Affichage de l'image\n";
    cout << "2. Donner la couleur d'un pixel\n";
    cout << "3. Detecter la presence d'une couleur dans l'image\n";
    cout << "4. Conservation des pixels avec du rouge\n";
    cout << "5. Transformer votre image en nuance de gris\n";
    cout << "6. Transformer votre image en noir et blanc\n";
    cout << "7. Augmenter la luminosite d'une image\n";
    cout << "8. Diminuer la luminosite d'une image\n";
    cout << "9. Augmenter le contraste d'une image\n";
    cout << "10. Diminuer le contraste d'une image\n";
    cout << "11. Tourner l'image vers la droite\n";
    cout << "12. Tourner l'image vers la gauche\n";
    cout << "13. Retourner l'image horizontalement\n";
    cout << "14. Retourner l'image verticalement\n";
    cout << "15. Rogner l'image a droite\n";
    cout << "16. Rogner l'image a gauche\n";
    cout << "17. Rogner l'image en bas\n";
    cout << "18. Rogner l'image en haut\n";
}

//Sous-programme pour saisir le choix de l'utilisateur.
int saisirChoix()
{
    int choix=0;
    while (choix<1 || choix >18)
    {
        cout << "Entrez le numero de l'option choisie : ";
        cin >> choix;
        cout << endl;
    }
    return choix;
}

//Fonction pour demander à l'utilisateur s'il veut recommencer.
bool recommencer()
{
    string reponse;
    do{
        cout << endl;
        cout << "Voulez-vous effectuer d'autres modifications ? (oui/non) : ";
        cin >> reponse;
    }while (reponse != "oui" && reponse !="non");
    return (reponse == "oui");
}
