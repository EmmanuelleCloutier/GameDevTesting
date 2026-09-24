#include <iostream>        // cin, cout
#include <vector>          // vector
#include <string>          // string
#include <algorithm>       // sort, min, max, reverse
#include <unordered_map>   // unordered_map
#include <unordered_set>   // unordered_set
#include <map>             // map
#include <set>             // set
#include <queue>           // queue, priority_queue
#include <stack>           // stack
#include <cmath>           // sqrt, pow, abs

using namespace std;

// VECTOR
vector<int> values;
values.push_back(x);
values.size();
values[i];

// MAP
unordered_map<int, int> counts;
counts[x]++;
counts.find(x) != counts.end();

// SET
unordered_set<int> seen;
seen.insert(x);
seen.find(x) != seen.end();

// SORT
sort(values.begin(), values.end());

// BOUCLE
for (int i = 0; i < values.size(); i++)
{
}

// ÉLÉMENT PRÉCÉDENT
values[i - 1];

// MIN / MAX
min(a, b);
max(a, b);