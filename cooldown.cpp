#include <string>
#include <vector>

using namespace std;

struct Ability
{ 
    string name;
    float cooldownRemaining; 
};

vector<string> UpdateCooldowns(vector<Ability>& abilities, float deltaTime)
{
    // Ce vector va contenir le NOM des abilities
    // qui viennent de terminer leur cooldown.
    vector<string> tempcooldown;

    float tempremainingtime;

    // On parcourt toutes les abilities.
    // i < abilities.size() permet d'aller de 0 jusqu'au dernier élément.
    for (int i = 0; i < abilities.size(); i++)
    {
        // IMPORTANT :
        // Si le cooldown est déjà à 0, l'ability était déjà disponible.
        // On ne veut donc PAS l'ajouter à tempcooldown.
        if (abilities[i].cooldownRemaining > 0)
        {
            // On calcule le nouveau cooldown.
            tempremainingtime = abilities[i].cooldownRemaining - deltaTime;

            // Si le cooldown atteint 0 ou descend sous 0,
            // l'ability vient de devenir disponible.
            if (tempremainingtime <= 0)
            {
                // Un cooldown ne doit jamais être négatif.
                tempremainingtime = 0;

                // tempcooldown est un vector<string>.
                // On ajoute donc le NOM de l'ability.
                tempcooldown.push_back(abilities[i].name);
            }

            // On modifie le VRAI cooldown dans le vector abilities.
            abilities[i].cooldownRemaining = tempremainingtime;
        }
    }

    // On retourne les noms des abilities
    // qui viennent de devenir disponibles.
    return tempcooldown;
}