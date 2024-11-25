#include "HangmanGame.h"

// Constructeur
HangmanGame::HangmanGame(const string& word, int max_attempts)
    : word_to_guess(word), max_tentative(max_attempts), current_tentative(0) {}

// Méthode pour traiter une lettre proposée par le joueur
void HangmanGame::make_guess(char letter) {
    letter = toupper(letter); // Conversion en majuscule pour uniformiser

    // Vérifie si la lettre a déjà été proposée (correcte ou incorrecte)
    if (guessed_letters.find(letter) != string::npos || incorrect_letters.find(letter) != string::npos) {
        cout << "Cette lettre a déjà été proposée.\n";
        return;  // Si oui, aucune action n'est effectuée
    }
    // Vérifie si la lettre fait partie du mot à deviner
    if (word_to_guess.find(toupper(letter)) != string::npos || word_to_guess.find(tolower(letter)) != string::npos) {
        guessed_letters += letter;  // Ajoute la lettre aux devinettes correctes
    }
    else {
        incorrect_letters += letter;  // Ajoute la lettre aux devinettes incorrectes
        current_tentative++;           // Incrémente le compteur de tentatives
    }
}

// Vérifie si le joueur a gagné (toutes les lettres du mot ont été devinées)
bool HangmanGame::is_won() const {
    for (char c : word_to_guess) 
    {
        if (guessed_letters.find(toupper(c)) == string::npos && guessed_letters.find(tolower(c)) == string::npos) {
            return false;
        }
    }
    return true;
}

// Vérifie si le joueur a perdu (nombre de tentatives maximal atteint)
bool HangmanGame::is_lost() const {
    return current_tentative >= max_tentative;
}

// Affiche l'état actuel du mot avec les lettres devinées
void HangmanGame::display_word() const {
    HangmanDisplay::display_word(word_to_guess, guessed_letters);
}

// Affiche les lettres incorrectes devinées
void HangmanGame::display_incorrect_letters() const {
    HangmanDisplay::display_incorrect_letters(incorrect_letters);
}

// Affiche le dessin de l'homme pendu en fonction des tentatives restantes
void HangmanGame::display_hangman() const {
    HangmanDisplay::display_hangman(max_tentative - current_tentative);
}
