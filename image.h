#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Image{
    ///Les attributs membre de la classe
    vector<vector<int>> _rouge;
    vector<vector<int>> _vert;
    vector<vector<int>> _bleu;
    int _longueur;
    int _largeur;

public:
    ///Les constructeurs
    Image(vector<vector<int>> rouge, vector<vector<int>> vert,vector<vector<int>> bleu);
    Image(const string &nomFichier);

    ///Méthodes de consultation
    void affichage()const;
    vector<int> CouleurPixel(int i, int j)const;
    bool Detection(int rouge, int vert, int bleu)const;

    ///Méthodes qui vont modifier la classe
    Image composanteRouge();
    Image NiveauxGris();
    Image noirEtBlanc(int);
    Image luminosityUp(double factor) const;
    Image luminosityDown(double factor) const;
    Image contrasteUp(double facteur) const;
    Image contrasteDown(double facteur) const;
    Image rognerD (int nb)const;
    Image rognerG (int nb)const;
    Image rognerB (int nb)const;
    Image rognerH (int nb)const;
    Image rotationD() const;
    Image rotationG() const;
    Image retournementH() const;
    Image retournementV() const;
    Image agrandissement(int facteur) const;
    Image retrecissement(int facteur) const;

    ///Méthode pour la gestion du fichier .ppm
    void savePicture(const string &nomFichier) const;
    void loadPicture(const string &picture, vector<vector<int>> &red,vector<vector<int>> &green,vector <vector<int>> &blue);
};

#endif // IMAGE_H_INCLUDED
