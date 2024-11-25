#include "gestionMots.h"

gestionMots::gestionMots(const string& chemin_fichier): word_count(0)
{
    ifstream file(chemin_fichier);
    if (!file) {
        cerr << "Error: Cannot open file.\n";
        exit(1);
    }

    string word;
    while (getline(file, word) && word_count < MAX_WORDS) {
        if (!word.empty()) {
            words[word_count++] = word;
        }
    }

    if (word_count == 0) {
        cerr << "Error: No words found in the file.\n";
        exit(1);
    }

}

string gestionMots::getrondom_word() {
    if (word_count == 0) {
        // Lev�e d'une exception si aucun mot n'est disponible
        throw runtime_error("Erreur : Aucun mot disponible pour s�lection al�atoire.");
    }

    srand(static_cast<unsigned>(time(0))); // Initialisation de la graine al�atoire
    int random_index = rand() % word_count; // G�n�ration d'un index al�atoire valide

    return words[random_index]; // Retourne le mot � l'index al�atoire
}

