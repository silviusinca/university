#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream fin("harta.in");
ofstream fout("harta.out");

int n;
vector<pair<int, int>> grade;
int matrice_ad[205][205];
int parinte[101];
int sel[101];

// formam doua multimi: prima mulțime o legam la nodul de start si a doua de nodul destinatie.
// intre nodurile din cele 2 multimi adaugam muchii cu capacitatea = 1

int bfs() {
    queue<int> q;
    memset(sel, false, sizeof(sel));
    memset(parinte, -1, sizeof(parinte));

    q.push(0);
    sel[0] = 1;

    while (!q.empty()) {

        int node = q.front();
        q.pop();
        if (node == n)
            return 1;

        for (int i = 0; i < n; i++)
            if (!sel[i] && matrice_ad[node][i] > 0) {
                q.push(i);
                sel[i] = 1;
                parinte[i] = node;
            }
    }

    return 0;
}

int main() {
    fin >> n;
    grade.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        fin >> x >> y;
        grade[i] = {x, y};
    }

    for (int i = 1; i <= n; i++) {
        matrice_ad[0][i] = grade[i].first;
        matrice_ad[i + n][2 * n + 1] = grade[i].second;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                matrice_ad[i][n + j] = 1;
            }
        }
    }

    int maxFlux = 0;
    while (bfs()) {
        for (int i = 1; i <= 2 * n + 1; i++) {
            if (sel[i] && matrice_ad[i][2 * n + 1] > 0) {
                int flux = INT_MAX;

                int node = parinte[i];
                while (node != -1) {
                    flux = min(flux, matrice_ad[parinte[node]][node]);
                    node = parinte[node];
                }
                if (flux) {
                    node = parinte[i];
                    while (node != -1) {
                        matrice_ad[parinte[node]][node] -= flux;
                        matrice_ad[node][parinte[node]] += flux;
                        node = parinte[node];
                    }
                    maxFlux += flux;
                }
            }
        }
    }
    
    cout << maxFlux << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            if (matrice_ad[j][i]) {
                cout << i << ' ' << j - n << endl;
                cout << "what";
            }
        }
    }
    return 0;
}