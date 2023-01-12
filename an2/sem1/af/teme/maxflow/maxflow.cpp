#include <queue>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxflow.in");
ofstream fout("maxflow.out");


// folosim bfs pentru a face un algoritm de tip Edmonds-Karp si gasim un drum de la start la destinatie
// ne folosim de muchiile reziduale pentru a ne putea intoarce intre noduri

int parinte[1001], sel[1001];
vector<vector<int>> matrice_ad(1001, vector<int>(1001, 0));
queue<int> q;
int M, N, maxFlux;

int bfs() {
    memset(sel, 0, sizeof(sel));
    memset(parinte, 0, sizeof(parinte));
    q.push(1);
    sel[1] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == N) return 1;

        for (int i = 1; i <= N; i++) {
            if (!sel[i] && matrice_ad[node][i] > 0) {
                q.push(i);
                sel[i] = 1;
                parinte[i] = node;
            }
        }
    }
    return 0;
}

int main() {
    fin >> N >> M;

    int end = N;

    for (int i = 0; i < M; i++) {
        int x, y, capacitate;
        fin >> x >> y >> capacitate;
        matrice_ad[x][y] = capacitate;
    }

    while (bfs()) {
        for (int i = 1; i < N; i++) {
            if (sel[i] == 1 && matrice_ad[i][end] > 0) {
                int node = end;
                int flux = INT_MAX;
                parinte[end] = i;
                while (parinte[node] > 0) {
                    flux = min(flux, matrice_ad[parinte[node]][node]);
                    node = parinte[node];
                }
                if (flux) {
                    node = end;
                    while (parinte[node] > 0) {
                        matrice_ad[parinte[node]][node] -= flux;
                        matrice_ad[node][parinte[node]] += flux;
                        node = parinte[node];
                    }
                }
                maxFlux += flux;
            }
        }
    }

    cout << maxFlux;

    return 0;
}