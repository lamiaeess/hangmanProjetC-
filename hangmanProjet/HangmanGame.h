#pragma once
#include <iostream>
#include <string>
#include "HangmanDisplay.h"

using namespace std;

class HangmanGame {
private:
    string word_to_guess;        // Mot que le joueur doit deviner
    string guessed_letters;      // Lettres correctement devin�es
    string incorrect_letters;    // Lettres incorrectes devin�es
    int max_tentative;            // Nombre maximal de tentatives autoris�es
    int current_tentative;        // Nombre de tentatives d�j� effectu�es

public:
    //Constructeur
    HangmanGame(const string& word, int max_attempts);
    //M�thode pour traiter une lettre propos�e par le joueur
    void make_guess(char letter);
    //V�rifie si le joueur a gagn�
    bool is_won() const;
    //V�rifie si le joueur a perdu
    bool is_lost() const;
    //Affiche l'�tat actuel du mot avec les lettres devin�es
    void display_word() const;

    // Affiche les lettres incorrectes devin�es
    void display_incorrect_letters() const;

    // Affiche le dessin de l'homme pendu en fonction des tentatives restantes
    void display_hangman() const;
};
