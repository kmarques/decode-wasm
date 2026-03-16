/**
 * Objectif : Créer un validateur de mot de passe en C++ ultra-rapide.
 * 1. C++ : Fonction  analyser_mdp(string mdp) .
 * 2. Logique : Vérifie la longueur, majuscules, chiffres et renvoie un statut texte ("Faible", "Moyen", "Fort").
 * 3. JS : Branché sur un  <input type="password">  via l'événement  keyup.
 */

#include <emscripten/bind.h>
#include <string>

using namespace std;

string analyser_mdp(const string mdp)
{
    int score = 0;
    // Vérifie la longueur du mot de passe
    if (mdp.length() >= 8)
        score++;
    // Vérifie la présence de majuscules
    if (string("ABCDEFGHIJKLMNOPQRSTUVWXYZ").find_first_of(mdp) != string::npos)
        score++;
    // Vérifie la présence de chiffres
    if (string("0123456789").find_first_of(mdp) != string::npos)
        score++;

    switch (score)
    {
    case 0:
        return "Très Faible";
    case 1:
        return "Faible";
    case 2:
        return "Moyen";
    case 3:
        return "Fort";
    default:
        return "Inconnu";
    }
}

EMSCRIPTEN_BINDINGS(my_module)
{
    emscripten::function("analyser_mdp", &analyser_mdp);
}