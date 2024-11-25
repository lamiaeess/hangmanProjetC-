#include "HangmanDisplay.h"

void HangmanDisplay::display_word(const string& word, const string& guessed_letters, int console_width) {
    // Cr�e une cha�ne vide pour stocker le mot � afficher (avec les lettres devin�es et des tirets pour les lettres non devin�es)
    string display_word = "";

    // Parcourt chaque caract�re du mot � deviner
    for (char c : word) {
        // V�rifie si la lettre a �t� devin�e, soit en majuscule soit en minuscule
        if (guessed_letters.find(toupper(c)) != string::npos || guessed_letters.find(tolower(c)) != string::npos) {
            display_word += c;  // Si la lettre a �t� devin�e, l'ajoute � la cha�ne display_word
        }
        else {
            display_word += "-";  // Sinon, ajoute un tiret pour repr�senter la lettre non devin�e
        }
    }

    // Calcule la longueur du mot affich�
    int word_length = display_word.length();

    // Calcule l'espacement (padding) n�cessaire pour centrer le mot dans la largeur de la console
    int padding = (console_width - word_length) / 2;

    // Affiche le mot avec les tirets pour les lettres non devin�es, centr� dans la console
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
