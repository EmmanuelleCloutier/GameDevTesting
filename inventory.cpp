#include <vector>
#include <string>

using namespace std; 

struct Item
{
    string name;
    int quantity;
};

bool AddItem(vector<Item>& inventory, string itemName, int amount, int MaxInventory)
{
    bool bCanAddItem = false; 

    // On cherche d'abord dans TOUT l'inventaire
    // pour voir si l'objet existe déjà.
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].name == itemName)
        {
            // L'objet existe déjà :
            // on augmente simplement sa quantité.
            inventory[i].quantity += amount;

            bCanAddItem = true;

            // On l'a trouvé, donc inutile de continuer la boucle.
            break;
        }
    }

    // IMPORTANT :
    // On vérifie APRÈS la boucle.
    //
    // Si bCanAddItem est encore false,
    // ça signifie qu'on a parcouru tout l'inventaire
    // sans trouver l'objet.
    if (bCanAddItem == false)
    {
        // Il faut maintenant vérifier s'il reste de la place.
        if (inventory.size() < MaxInventory)
        {
            // Le vector contient des Item,
            // donc on crée un nouvel Item avec {nom, quantité}.
            inventory.push_back({itemName, amount});

            bCanAddItem = true;
        }
    }

    // true  = objet ajouté ou quantité augmentée
    // false = nouvel objet impossible car inventaire plein
    return bCanAddItem; 
}