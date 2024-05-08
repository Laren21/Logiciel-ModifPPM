#include "image.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "filtre.h"

using namespace std;

Filtre::Filtre(const vector<vector<float>>& act, int ray){
    action = act;
    rayon = ray;
}

vector<vector<float>> Filtre::application(const vector<vector<float>>& image) const {
    int rows = image.size();
    int cols = image[0].size();
    vector<vector<float>> resultat(rows, vector<float>(cols, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int m = -rayon; m <= rayon; ++m) {
                for (int n = -rayon; n <= rayon; ++n) {
                    int row = i + m;
                    int col = j + n;

                    // Vérifier si la position est valide
                    if (row >= 0 && row < rows && col >= 0 && col < cols) {
                        resultat[i][j] += action[m + rayon][n + rayon] * image[row][col];
                    }
                }
            }
        }
    }

    return resultat;
}
