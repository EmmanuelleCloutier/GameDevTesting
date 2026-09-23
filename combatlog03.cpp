#include <string>
#include <vector>

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

bool checkPlayerDeath(const Player& player)
{
    // Cette fonction vérifie seulement l'état du joueur.
    return player.health <= 0;
}

vector<int> ProcessCombat(
    vector<Player>& players,
    const vector<DamageEvent>& events)
{
    vector<int> DeadPlayer;

    for(int i = 0; i < events.size(); i++)
    {
        // Chercher l'attaquant
        for(int y = 0; y < players.size(); y++)
        {
            if(events[i].attackerId == players[y].id)
            {
                // Si l'attaquant est mort,
                // on ne traite PAS l'attaque.
                if(!checkPlayerDeath(players[y]))
                {
                    // Chercher la target
                    for(int k = 0; k < players.size(); k++)
                    {
                        if(events[i].targetId == players[k].id)
                        {
                            // La target doit être vivante.
                            if(!checkPlayerDeath(players[k]))
                            {
                                // Appliquer les dégâts.
                                players[k].health -= events[i].damage;

                                // Empêcher health de devenir négatif.
                                if(players[k].health <= 0)
                                {
                                    players[k].health = 0;

                                    // Elle vient de mourir.
                                    DeadPlayer.push_back(players[k].id);
                                }
                            }

                            // Target trouvée :
                            // inutile de continuer à chercher.
                            break;
                        }
                    }
                }

                // Attacker trouvé :
                // inutile de continuer à chercher.
                break;
            }
        }
    }

    return DeadPlayer;
}