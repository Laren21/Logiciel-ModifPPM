#ifndef FILTRE_H_INCLUDED
#define FILTRE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Filtre {
private:
    vector<vector<float>> action;
    int rayon;

public:
    Filtre(const vector<vector<float>>& action, int rayon);
    vector<vector<float>> application(const vector<vector<float>>& image) const;
};

#endif // FILTRE_H_INCLUDED
