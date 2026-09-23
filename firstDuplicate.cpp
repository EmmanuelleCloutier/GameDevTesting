#include <vector>

using namespace std;

int FirstDuplicate(const vector<int>& numbers)
{
    // On parcourt le tableau de gauche à droite.
    for (int i = 0; i < numbers.size(); i++)
    {
        // On regarde uniquement les éléments AVANT i.
        for (int j = 0; j < i; j++)
        {
            // Si numbers[i] est déjà apparu avant,
            // alors numbers[i] est la première deuxième apparition.
            if (numbers[i] == numbers[j])
            {
                return numbers[i];
            }
        }
    }

    // Aucun doublon.
    return -1;
}