#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// struct auxiliar pentru a reprezenta o muchie in graf
struct aux {
    int vecin;
    int index;
};

const int nMax = 100005;

// cream un graf in care nodurile sunt sufixe/prefixe ale cuvintelor
vector<aux> graf[nMax];
vector<int> sol;
vector<int> sel(nMax, 0);

// dfs pentru a verifica daca este sau nu graf eulerian
void dfs(int nod) {
    while(!graf[nod].empty()) {
        int vec = graf[nod].back().vecin;
        int index = graf[nod].back().index;
        graf[nod].pop_back();
        if(!sel[index]) {
            sel[index] = 1;
            dfs(vec);
        }
    }
    sol.push_back(nod);
}

int main() {
    unordered_map<string, int> hash;
    unordered_map<int, string> invers;
    vector<int> gradin(nMax, 0);
    vector<int> gradext(nMax, 0);

    int n, k;
    cin >> n >> k;
    int N = n, nod = 0, nrMuchii = 0;
    // citim si formam graful, aflam gradele interne si externe
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        string prefix = s, sufix = s;
        prefix.pop_back();
        sufix.erase(sufix.begin());

        if (!hash[prefix]) {
            nod++;
            hash[prefix] = nod;
            invers[nod] = prefix;
        }
        if (!hash[sufix]) {
            nod++;
            hash[sufix] = nod;
            invers[nod] = sufix;
        }
        nrMuchii++;
        graf[hash[prefix]].push_back({hash[sufix], nrMuchii});
        gradin[hash[sufix]]++;
        gradext[hash[prefix]]++;
    }

    n = nod;
    int dif = 0; // pentru a verifica daca exista un ciclu eulerian
    int radacina = 1;

    for (int i = 1; i <= n; i++) {
        if (gradin[i] != gradext[i])
            dif++;
        if (gradext[i] == gradin[i] + 1)
            radacina = i;
    }

    // vefificam daca dif > 2, adica daca toate nodurile in afara de primul si ultimul au gradin = gradext
    if (dif > 2) {
        cout << -1;
        return 0;
    }

    dfs(radacina);

    // nu am nevoie de primul prefix pentru ca a fost deja afisat
    sol.pop_back();
    reverse(sol.begin(), sol.end());

    if (invers[radacina].size() + sol.size() < N + k - 1) {
        cout << -1;
        return 0;
    }

    // afisare
    cout << invers[radacina];
    for(auto i : sol)
        cout << invers[i].back();

    return 0;
}
