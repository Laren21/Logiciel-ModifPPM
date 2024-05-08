#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "outil.h"
#include "image.h"

using namespace std;

int main()
{
    vector<vector<int>> rouge ={{111, 100, 100, 100}, {111, 0, 255, 255}, {111, 255, 255, 255}, {111, 255, 255, 255}};
    vector<vector<int>> vert  ={{111, 100, 100, 100}, {111, 255, 255, 255}, {111, 255, 255, 0},{111, 255, 0, 0}};
    vector<vector<int>> bleu  ={{111, 100, 100, 100}, {111, 0, 0, 0}, {111, 0, 0, 0}, {111, 0, 0, 0}};

    Image def(rouge, vert, bleu);

    cout << endl << endl << "--------Test de la procedure affichage-----------------" << endl;
    def.affichage();

    cout << endl << endl << "--------Test de la fonction CouleurPixel---------------" << endl;

    vector<int> CouleurVecteur = def.CouleurPixel(2, 2);

    cout << endl << "La couleur du pixel selectionner : ";
    for (size_t i = 0; i < CouleurVecteur.size(); i++)
    {
        cout << CouleurVecteur[i] << " ";
    }

    cout << endl << endl << "--------Test de la fonction composanteRouge------------" << endl;
    Image nouvImg = def.composanteRouge();
    nouvImg.affichage();

    cout << endl << endl << "--------Test Automatique de la fonction Detection------" << endl;
    bool verif = def.Detection(255, 0, 0);
    if (verif)
        cout << endl << "Apres verification : Au moins un pixel correspond a la couleur que vous avez entre";
    else
        cout << endl << "Apres verification : Aucun pixel ne correspond a la couleur que vous recherche";

    cout << endl << endl << "--------Test de la fonction NiveauxGris----------------" << endl;
    Image imageGris = def.NiveauxGris();
    imageGris.affichage();

    cout << endl << endl << "--------Test de la fonction noirEtBlanc----------------" << endl;
    Image ImageNoirEtBlanc = def.noirEtBlanc(120);
    ImageNoirEtBlanc.affichage();

    cout << endl << endl << "--------Test de la fonction luminosityDown-------------" << endl;
    Image NewDef=def.luminosityDown(1.5);
    NewDef.affichage();

    cout << endl << endl << "--------Test de la fonction contrasteDown--------------" << endl;
    Image NewDef2=def.contrasteDown(1.5);
    NewDef2.affichage();

    cout << endl << endl << "--------Test de la fonction rognerD--------------------" << endl;
    Image NewDef5=def.rognerD(2);
    NewDef5.affichage();

    cout << endl << endl << "--------Test de la fonction rognerG--------------------" << endl;
    Image NewDef3=def.rognerG(2);
    NewDef3.affichage();

    cout << endl << endl << "--------Test de la fonction rognerB--------------------" << endl;
    Image NewDef6=def.rognerB(2);
    NewDef6.affichage();

    cout << endl << endl << "--------Test de la fonction rognerH--------------------" << endl;
    Image NewDef4=def.rognerH(2);
    NewDef4.affichage();

    cout << endl << endl;
    def.affichage();

    cout << endl << endl << "--------Test de la fonction rotationD--------------------" << endl;
    Image NewDef7=def.rotationD();
    NewDef7.affichage();

    cout << endl << endl << "--------Test de la fonction rotationG--------------------" << endl;
    Image NewDef8=def.rotationG();
    NewDef8.affichage();

    cout << endl << endl << "--------Test de la fonction retournementH----------------" << endl;
    Image NewDef9=def.retournementH();
    NewDef9.affichage();

    cout << endl << endl << "--------Test de la fonction retournementV----------------" << endl;
    Image NewDef10=def.retournementV();
    NewDef10.affichage();

    cout << endl << endl << "--------Test de la fonction agrandissement----------------" << endl;
    try
    {
        Image NewDef11=def.agrandissement(1.5);
        NewDef11.affichage();
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << endl;
    }

    cout << endl << endl << "--------Test de la fonction retrecissement----------------" << endl;
    try
    {
        Image NewDef12=def.retrecissement(1.5);
        NewDef12.affichage();
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}
