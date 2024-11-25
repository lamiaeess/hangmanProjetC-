#include "HangmanGame.h"

// Constructeur
HangmanGame::HangmanGame(const string& word, int max_attempts)
    : word_to_guess(word), max_tentative(max_attempts), current_tentative(0) {}

// M�thode pour traiter une lettre propos�e par le joueur
void HangmanGame::make_guess(char letter) {
    letter = toupper(letter); // Conversion en majuscule pour uniformiser

    // V�rifie si la lettre a d�j� �t� propos�e (correcte ou incorrecte)
    if (guessed_letters.find(letter) != string::npos || incorrect_letters.find(letter) != string::npos) {
        cout << "Cette lettre a d�j� �t� propos�e.\n";
        return;  // Si oui, aucune action n'est effectu�e
    }
    // V�rifie si la lettre fait partie du mot � deviner
    if (word_to_guess.find(toupper(letter)) != string::npos || word_to_guess.find(tolower(letter)) != string::npos) {
        guessed_letters += letter;  // Ajoute la lettre aux devinettes correctes
    }
    else {
        incorrect_letters += letter;  // Ajoute la lettre aux devinettes incorrectes
        current_tentative++;           // Incr�mente le compteur de tentatives
    }
}

// V�rifie si le joueur a gagn� (toutes les lettres du mot ont �t� devin�es)
bool HangmanGame::is_won() const {
    for (char c : word_to_guess) 
    {
        if (guessed_letters.find(toupper(c)) == string::npos && guessed_letters.find(tolower(c)) == string::npos) {
            return false;
        }
    }
    return true;
}

// V�rifie si le joueur a perdu (nombre de tentatives maximal atteint)
bool HangmanGame::is_lost() const {
    return current_tentative >= max_tentative;
}

// Affiche l'�tat actuel du mot avec les lettres devin�es
void HangmanGame::display_word() const {
    HangmanDisplay::display_word(word_to_guess, guessed_letters);
}

// Affiche les lettres incorrectes devin�es
void HangmanGame::display_incorrect_letters() const {
    HangmanDisplay::display_incorrect_letters(incorrect_letters);
}

// Affiche le dessin de l'homme pendu en fonction des tentatives restantes
void HangmanGame::display_hangman() const {
    HangmanDisplay::display_hangman(max_tentative - current_tentative);
}
