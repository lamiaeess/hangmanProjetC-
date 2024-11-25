#pragma once
#include <iostream>
#include <string>
using namespace std;

class HangmanDisplay {
public:
    //Affiche le mot avec les lettres devin�es et remplace les autres par des tirets
    static void display_word(const string& word, const string& guessed_letters, int console_width = 80);
    //Affiche l'�tat du pendu en fonction des tentatives restantes
    static void display_hangman(int attempts_left);
    //Affiche les lettres incorrectes d�j� devin�es
    static void display_incorrect_letters(const string& incorrect_letters);
};
