#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;
class gestionMots
{
private: 
    static const int MAX_WORDS = 1000; //nombre de mots maximale que la class peut stocker
    string words[MAX_WORDS];//tableaux pour stocker les mots lu 
    int word_count;// compteur de nombre de mots
public:
    //Constructeur qui prend le chemin d'un fichier en paramètre
    gestionMots(const string&);
    //Méthode pour obtenir un mot aléatoire
    string getrondom_word();
};

