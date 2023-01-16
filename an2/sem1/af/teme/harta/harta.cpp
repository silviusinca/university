#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("harta.in");
ofstream fout("harta.out");

int N;

bool bfs(vector<vector<int>> &capacitate, vector<vector<int>> &lista_ad, vector<int> &parinte) {
    vector<bool> sel;
    queue<int> bfs;
    sel.resize(2 * N + 2, false);
    parinte.resize(2 * N + 2);
    bfs.push(0);
    sel[0] = true;
    parinte[0] = -1;

    while (!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();
        if (node == 2 * N + 1)
            return true;
        for (auto nodAux: lista_ad[node]) {
            if (!sel[nodAux] && capacitate[node][nodAux] > 0) {
                bfs.push(nodAux);
                sel[nodAux] = true;
                parinte[nodAux] = node;
            }
        }
    }
    return false;
}

int main() {
    fin >> N;
    int nodParinte, maxFlux = 0;
    vector<int> parinte(2 * N + 2);
    vector<vector<int>> lista_ad, capacitate;
    lista_ad.resize(2 * N + 2);
    capacitate.resize(2 * N + 2, vector<int>(2 * N + 2, 0));

    for (int i = 1; i <= N; i++) {
        int x, y;
        fin >> y >> x;
        capacitate[0][i] = y;
        lista_ad[0].push_back(i);
        capacitate[i + N][2 * N + 1] = x;
        lista_ad[i + N].push_back(2 * N + 1);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = N + 1; j <= 2 * N; j++) {
            if (i != j - N) {
                capacitate[i][j] = 1;
                lista_ad[i].push_back(j);
            }
        }
    }

    while (bfs(capacitate, lista_ad, parinte)) {
        int flux = INT32_MAX, node = 2 * N + 1;
        while (node) {
            nodParinte = parinte[node];
            flux = min(flux, capacitate[nodParinte][node]);
            node = parinte[node];
        }
        if (flux) {
            node = 2 * N + 1;
            while (node) {
                nodParinte = parinte[node];
                if (!capacitate[node][nodParinte])
                    lista_ad[node].push_back(nodParinte);
                capacitate[nodParinte][node] -= flux;
                capacitate[node][nodParinte] += flux;
                node = parinte[node];
            }
        }
        maxFlux += flux;
    }

    fout << maxFlux << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < lista_ad[i].size(); j++) {
            if (capacitate[i][lista_ad[i][j]] == 0 && lista_ad[i][j] > N) {
                fout << i << " " << lista_ad[i][j] - N << endl;
            }
        }
    }
    return 0;
}