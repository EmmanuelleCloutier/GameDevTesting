#include <string>
#include <vector>
#include <cmath>

using namespace std; 

struct Vector2
{
    float x;
    float y;
};

struct Enemy 
{
    string name;
    Vector2 position;
    bool bIsActive;
};

string FindClosestEnemy(
    const vector<Enemy>& enemies,
    Vector2 playerPosition,
    float maxRange)
{
    // Par défaut, aucune cible trouvée.
    string closestEnemy = "None";

    // La meilleure distance trouvée jusqu'à maintenant.
    float smalestRange = maxRange;

    // Check chaque ennemi disponible.
    for(int i = 0; i < enemies.size(); i++)
    {
        // Ignore les ennemis inactifs/morts.
        if(enemies[i].bIsActive == true)
        {
            // Différence de position entre l'ennemi et le joueur.
            float deltaX =
                enemies[i].position.x - playerPosition.x;

            float deltaY =
                enemies[i].position.y - playerPosition.y;

            // Distance = sqrt(dx² + dy²)
            // En C++, on fait x*x plutôt que x^2.
            float tempRange =
                sqrt(deltaX * deltaX + deltaY * deltaY);

            // Si cet ennemi est dans la portée ET
            // plus proche que notre meilleure cible actuelle...
            if(tempRange <= smalestRange)
            {
                // On sauvegarde directement son nom.
                closestEnemy = enemies[i].name;

                // Il devient notre nouvelle meilleure distance.
                smalestRange = tempRange;
            }
        }
    }

    // Si aucun ennemi n'a été trouvé,
    // closestEnemy est encore "None".
    return closestEnemy;
}