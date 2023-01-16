#include <vector>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");

int N, M;

int bfs(vector<vector<int>> &capacitate, vector<vector<int>> &lista_ad, vector<int> &parinte) {
    vector<int> sel;
    queue<int> bfs;
    sel.resize(N + M + 2, 0);
    parinte.resize(N + M + 2);
    bfs.push(0);
    sel[0] = 1;
    parinte[0] = -1;

    while (!bfs.empty()) {
        int nod = bfs.front();
        bfs.pop();
        if (nod == N + M + 1)
            return 1;
        for (auto vecin: lista_ad[nod]) {
            if (!sel[vecin] && capacitate[nod][vecin] > 0) {
                bfs.push(vecin);
                sel[vecin] = 1;
                parinte[vecin] = nod;
            }
        }
    }
    return 0;
}

int main() {
    vector<int> parinte(N+M+2);
    vector<vector<int>> capacitate(N + M + 2, vector<int>(N + M + 2, 0)), lista_ad(N + M + 2);
    int nodeParent, E, maxFlux = 0;
    fin >> N >> M >> E;


    for (int i = 1; i <= N; i++) {
        capacitate[0][i] = 1; 
        lista_ad[0].push_back(i);
    }


    for (int i = N + 1; i <= N + M; i++) {
        capacitate[i][N + M + 1] = 1;
        lista_ad[i].push_back(N + M + 1);
        lista_ad[i].push_back(i - N); 
        capacitate[i][i - N] = 1;
    }


    for (int i = 0; i < E; i++) {
        int x, y;
        fin >> x >> y;
        capacitate[x][N + y] = 1;
        lista_ad[x].push_back(N + y);
    }


    while (bfs(capacitate, lista_ad, parinte)) {
        int flux = INT_MAX, nod = M + N + 1;
        while (nod) {
            nodeParent = parinte[nod];
            flux = min(flux, capacitate[nodeParent][nod]);
            nod = parinte[nod];
        }
        if (flux) {
            nod = M + N + 1;
            while (nod) {
                nodeParent = parinte[nod];
                capacitate[nodeParent][nod] -= flux;
                capacitate[nod][nodeParent] += flux;
                lista_ad[nod].push_back(nodeParent);
                nod = parinte[nod];
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
