#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");

int parinte[20001];
int matrice_ad[20001][20001];
int n, m, e, nod;
int sel[20001];

int bfs() {
    queue<int> q;

    memset(sel, 1, sizeof(sel));
    memset(parinte, 0, sizeof(parinte));

    q.push(0);
    sel[0] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == n)
            return 1;
        for (int i = 0; i < n; i++) {
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
    int maxFlux = 0, flux;
    fin >> n >> m >> e;

    for (int i = 0; i < e; i++) {
        int x, y;
        fin >> x >> y;
        matrice_ad[x][n + y] = 1;
    }

    for (int i = 1; i <= n; i++) {
        matrice_ad[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i != j) {
                matrice_ad[i][n + j] = 1; 
            }
        }
    }

    while (bfs())
        for (int i = 1; i <= m + n; i++) 
            if (sel[n + i] && matrice_ad[n + i][m + n] > 0) {
                
                flux = INT_MAX;
                int node = n + m;

                while (parinte[node] > 0) {
                    flux = min(flux, matrice_ad[parinte[node]][node]);
                    node = parinte[node];
                }

                if (flux) {
                    node = n + m;
                    while (parinte[node] > 0) {
                        matrice_ad[parinte[node]][node] -= flux;
                        matrice_ad[node][parinte[node]] += flux;
                        node = parinte[node];
                    }
                }

                maxFlux += flux;
            }
        
    

    cout << maxFlux << endl;
    for (int i = 1; i <= n; i++)
        for (int j = n + 1; j <= n + m; j++)
            if (matrice_ad[i][n + j] == 0 && matrice_ad[n + j][i] == 1)
                fout << i << " " << j << endl;

    return 0;
}