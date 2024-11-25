#include "HangmanDisplay.h"

void HangmanDisplay::display_word(const string& word, const string& guessed_letters, int console_width) {
    // Crée une chaîne vide pour stocker le mot à afficher (avec les lettres devinées et des tirets pour les lettres non devinées)
    string display_word = "";

    // Parcourt chaque caractère du mot à deviner
    for (char c : word) {
        // Vérifie si la lettre a été devinée, soit en majuscule soit en minuscule
        if (guessed_letters.find(toupper(c)) != string::npos || guessed_letters.find(tolower(c)) != string::npos) {
            display_word += c;  // Si la lettre a été devinée, l'ajoute à la chaîne display_word
        }
        else {
            display_word += "-";  // Sinon, ajoute un tiret pour représenter la lettre non devinée
        }
    }

    // Calcule la longueur du mot affiché
    int word_length = display_word.length();

    // Calcule l'espacement (padding) nécessaire pour centrer le mot dans la largeur de la console
    int padding = (console_width - word_length) / 2;

    // Affiche le mot avec les tirets pour les lettres non devinées, centré dans la console
    cout << string(padding, ' ') << display_word << endl;
}


void HangmanDisplay::display_hangman(int tentative_restante) {
    switch (tentative_restante) {
    case 5:
        cout << " ________\n";
        cout << " |        |\n";
        cout << " |        O\n";
        cout << " |\n";
        cout << " |\n";
        cout << " |\n";
        cout << " |\n";
        cout << " __________\n";
        break;
    case 4:
        cout << " ________\n";
        cout << " |        |\n";
        cout << " |        O\n";
        cout << " |        |\n";
        cout << " |\n";
        cout << " |\n";
        cout << " |\n";
        cout << " __________\n";
        break;
    case 3:
        cout << " ________\n";
        cout << " |        |\n";
        cout << " |        O\n";
        cout << " |       /|\n";
        cout << " |\n";
        cout << " |\n";
        cout << " |\n";
        cout << " __________\n";
        break;
    case 2:
        cout << " ________\n";
        cout << " |        |\n";
        cout << " |        O\n";
        cout << " |       /|\\\n";
        cout << " |\n";
        cout << " |\n";
        cout << " |\n";
        cout << " __________\n";
        break;
    case 1:
        cout << " ________\n";
        cout << " |        |\n";
        cout << " |        O\n";
        cout << " |       /|\\\n";
        cout << " |       /\n";
        cout << " |\n";
        cout << " |\n";
        cout << " __________\n";
        break;
    case 0:
        cout << " ________\n";
        cout << " |        |\n";
        cout << " |        O\n";
        cout << " |       /|\\\n";
        cout << " |       / \\\n";
        cout << " |\n";
        cout << " |\n";
        cout << " __________\n";
        break;
    default:
        break;
    }
}


void HangmanDisplay::display_incorrect_letters(const string& incorrect_letters) {
    cout << "Incorrect letters: ";
    for (char c : incorrect_letters) {
        cout << c << " ";
    }
    cout << endl;
}
