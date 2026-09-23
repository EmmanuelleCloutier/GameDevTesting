#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Player
{
    int id;
    int health;
};

struct DamageEvent
{
    int attackerId;
    int targetId;
    int damage;
};

vector<int> ProcessCombat(
    vector<Player>& players,
    const vector<DamageEvent>& events)
{
    vector<int> deadPlayers;

    // -------------------------------------------------
    // ÉTAPE 1
    // Créer une table :
    //
    // Player ID -> position dans le vector players
    //
    // Exemple :
    // ID 10 -> index 0
    // ID 25 -> index 1
    // ID 42 -> index 2
    // -------------------------------------------------

    unordered_map<int, int> playerIndex;

    for (int i = 0; i < players.size(); i++)
    {
        playerIndex[players[i].id] = i;
    }


    // -------------------------------------------------
    // ÉTAPE 2
    // Traiter chaque événement.
    // -------------------------------------------------

    for (int i = 0; i < events.size(); i++)
    {
        // On récupère directement l'index de l'attaquant.
        int attackerIndex =
            playerIndex[events[i].attackerId];

        // Même chose pour la target.
        int targetIndex =
            playerIndex[events[i].targetId];


        // -------------------------------------------------
        // Attacker mort ?
        // -------------------------------------------------

        if (players[attackerIndex].health <= 0)
        {
            // Ignore cet event et passe au suivant.
            continue;
        }


        // -------------------------------------------------
        // Target déjà morte ?
        // -------------------------------------------------

        if (players[targetIndex].health <= 0)
        {
            continue;
        }


        // -------------------------------------------------
        // Appliquer les dégâts.
        // -------------------------------------------------

        players[targetIndex].health -= events[i].damage;


        // -------------------------------------------------
        // Est-ce que la target vient de mourir ?
        // -------------------------------------------------

        if (players[targetIndex].health <= 0)
        {
            // Health ne peut pas être négatif.
            players[targetIndex].health = 0;

            // Ajouter son ID dans l'ordre des morts.
            deadPlayers.push_back(
                players[targetIndex].id
            );
        }
    }

    return deadPlayers;
}