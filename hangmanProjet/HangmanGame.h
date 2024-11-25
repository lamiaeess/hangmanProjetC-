#pragma once
#include <iostream>
#include <string>
#include "HangmanDisplay.h"

using namespace std;

class HangmanGame {
private:
    string word_to_guess;        // Mot que le joueur doit deviner
    string guessed_letters;      // Lettres correctement devinées
    string incorrect_letters;    // Lettres incorrectes devinées
    int max_tentative;            // Nombre maximal de tentatives autorisées
    int current_tentative;        // Nombre de tentatives déjà effectuées

public:
    //Constructeur
    HangmanGame(const string& word, int max_attempts);
    //Méthode pour traiter une lettre proposée par le joueur
    void make_guess(char letter);
    //Vérifie si le joueur a gagné
    bool is_won() const;
    //Vérifie si le joueur a perdu
    bool is_lost() const;
    //Affiche l'état actuel du mot avec les lettres devinées
    void display_word() const;

    // Affiche les lettres incorrectes devinées
    void display_incorrect_letters() const;

    // Affiche le dessin de l'homme pendu en fonction des tentatives restantes
    void display_hangman() const;
};
