#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* Explicatie:
    Am facut o metoda pentru a calcula distanta folosindu-ma de o varianta iterativa a bfs-ului in care calculez distanta de la un nod start la toate punctele de control, si dupa verific care e cea mai mica distanta. 
*/

int distanta(int n, int start, vector<int> puncte_control, vector<vector<int>> lista_ad) {
    int distanta = n+1;
    queue<int> q;
    vector<int> sel(n+1, 0);

    q.push(start);
    sel[start] = 1;

    vector<int> dist(n+1), dist_puncte_control(puncte_control.size());
    dist[start] = 0;
    int i = 0;
    while (!q.empty()) {
        int nod = q.front();
        q.pop();

        for (auto vecin : lista_ad[nod]) {
            if (sel[vecin] == 0) {
                q.push(vecin);
                sel[vecin] = 1;
                dist[vecin] = dist[nod] + 1;
                if (count(puncte_control.begin(), puncte_control.end(), vecin)) { // daca vecin = unul dintre punctele de control, atunci distanta pana la punctul respectiv = dist[vecin]
                    dist_puncte_control[i++] = dist[vecin];
                }
            }
        }
    }

    for (auto d : dist_puncte_control) // aici compar distantele si o returnez dupa pe cea mai mica
        if (d < distanta)
            distanta = d;

    return distanta;
}

int main() {
    ifstream fin("graf.in");
    int n, m, a, b;

    fin >> n >> m;
    vector<vector<int>> muchii(m);
    vector<vector<int>> lista_ad(n+1);

    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        muchii[i].push_back(a);
        muchii[i].push_back(b);
    }

    for (auto muchie : muchii) {
        lista_ad[muchie[0]].push_back(muchie[1]);
        lista_ad[muchie[1]].push_back(muchie[0]);
    }

    vector<int> puncte;
    while(fin >> a)
        puncte.push_back(a);

    for (int i = 1; i <= n; i++) {
        cout << distanta(n, i, puncte, lista_ad) << ' ';
    }


    return 0;
}
