#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("drumuri2.in");
ofstream fout("drumuri2.out");

int N, M;

int bfs(vector<vector<int>> &capacitate, vector<vector<int>> &lista_ad, vector<int> &parinte) {
    vector<int> sel(N * 2 + 2, 0);
    queue<int> bfs;
    parinte.resize(N * 2 + 2);
    bfs.push(0);
    sel[0] = 1;
    parinte[0] = -1;

    while (!bfs.empty()) {
        int nod = bfs.front();
        bfs.pop();
        
        if (nod == N * 2 + 1)
            return 1;

        for (auto nodAux: lista_ad[nod]) {
            if (!sel[nodAux] && capacitate[nod][nodAux] > 0) {
                bfs.push(nodAux);
                sel[nodAux] = 1;
                parinte[nodAux] = nod;
            }
        }
    }
    return 0;
}

int main() {
    fin >> N >> M;
    int nodParinte, maxFlux = 0;
    vector<int> parinte;
    vector<vector<int>> lista_ad(N * 2 + 2), capacitate(N * 2 + 2, vector<int>(N * 2 + 2, 0));

    for (int i = 1; i <= N; i++) {
        capacitate[0][i] = 1;
        lista_ad[0].push_back(i);
    }

    for (int i = N + 1; i <= N * 2; i++) {
        capacitate[i][N * 2 + 1] = 1;
        lista_ad[i].push_back(N * 2 + 1);
        lista_ad[i].push_back(i - N);
        capacitate[i][i - N] = 1;
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        fin >> x >> y;
        capacitate[x][N + y] = 1;
        lista_ad[x].push_back(N + y);
    }

    while (bfs(capacitate, lista_ad, parinte)) {
        int flux = INT_MAX, nod = M + N + 1;
        
        while (nod) {
            nodParinte = parinte[nod];
            flux = min(flux, capacitate[nodParinte][nod]);
            nod = parinte[nod];
        }

        if (flux) {
            nod = M + N + 1;
            while (nod) {
                nodParinte = parinte[nod];
                capacitate[nodParinte][nod] -= flux;
                capacitate[nod][nodParinte] += flux;
                lista_ad[nod].push_back(nodParinte);
                nod = parinte[nod];
            }
        }
        maxFlux += flux;
    }
    int rez = abs(N - maxFlux);
    fout << rez;
    return 0;
}