#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "gestionMots.h"       
#include "HangmanGame.h"        
#include "HangmanDisplay.h"     

using namespace std;

int main() {
    string difficulty;
    cout << "Choose difficulty (easy, medium, hard): ";
    cin >> difficulty;

    string file_path;
    if (difficulty == "easy") {
        file_path = "facile.txt";//Fichier pour niveau facile
    }
    else if (difficulty == "medium") {
        file_path = "moyen.txt";//Fichier pour niveau moyen
    }
    else if (difficulty == "hard") {
        file_path = "difficile.txt";//Fichier pour niveau difficile
    }
    else {
        cout << "Invalid difficulty level! Defaulting to easy.\n";
        file_path = "easy_words.txt";
    }

    gestionMots word_manager(file_path);//Gestion des mots avec le fichier donné
    char play_again;

    do {
        string random_word = word_manager.getrondom_word();  
        HangmanGame game(random_word, 6);//Initialisation du jeu avec le mot et le nombre de tentatives

        cout << "Welcome to Hangman!\n";

        while (!game.is_won() && !game.is_lost()) {
            system("cls");
            cout << "HANGMAN\n";
            game.display_hangman();  // Affiche l'homme pendu
            game.display_word();     // Affiche le mot avec les lettres devinées
            game.display_incorrect_letters();  // Affiche les lettres incorrectes

            cout << "\nEnter a letter: ";
            char guess;
            cin >> guess;
            game.make_guess(guess);  // Traitement de la lettre proposée
        }

        if (game.is_won()) {
            cout << "Congratulations, you won! The word was: " << random_word << "\n";
        }
        else {
            cout << "Game over. The word was: " << random_word << "\n";
            game.display_hangman();  // Affiche l'homme pendu complet si perdu
        }

        cout << "Play again? (y/n): ";
        cin >> play_again;
    } while (tolower(play_again) == 'y');  // Demande si l'utilisateur veut rejouer

    return 0;
}
