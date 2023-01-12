#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

/*
 * 
 *
 * */

using namespace std;

ifstream fin ("drumuri2.in");
ofstream fout ("drumuri2.out");

int n,m;
vector<vector<int>> lista_ad;
vector<vector<int>> capacitati;
vector<int> parinte;

int bfs(){
    vector<bool> sel;
    sel.resize(n*2+2, 0);
    parinte.resize(n*2+2);
    queue<int> q;
    q.push(0);
    sel[0] = 1;
    parinte[0] = -1;

    while(!q.empty()){
        int nod = q.front();
        q.pop();
        for (int i = 0; i < lista_ad[nod].size(); i++){
            int nod_aux = lista_ad[nod][i];
            if (capacitati[nod][nod_aux] > 0 && sel[nod_aux] == 0){
                parinte[nod_aux] = nod;
                q.push(nod_aux);
                sel[nod_aux] = 1;
                if (nod_aux == n*2+1) {
                    return 1;
                }
            }
        }
    }
    return 0;
};

int main() {
    fin >> n >> m;

    lista_ad.resize(n*2+2);
    capacitati.resize(n*2+2, vector<int>(n*2+2, 0));

    for (int i = 1; i <= n; i++) {
        capacitati[0][i] = 1;
        lista_ad[0].push_back(i);
    }

    for (int i = n+1; i <= n*2; i++) {
        capacitati[i][n * 2 + 1] = 1;
        lista_ad[i].push_back(n*2+1);
        lista_ad[i].push_back(i-n);
        capacitati[i][i - n] = 1;
    }

    for (int i = 0; i < m; i++) {
        int sursa,destinatie;
        fin >> sursa >> destinatie;
        capacitati[sursa][n + destinatie] = 1;
        lista_ad[sursa].push_back(n + destinatie);
    }

    int maxFlow = 0;

    while (bfs()) {
        int flow = INT_MAX;
        int i = n * 2 + 1;
        while (i) {
            int nod = parinte[i];
            flow = min(flow, capacitati[nod][i]);
            i = parinte[i];
        }
        i = n * 2 + 1;
        while (i) {
            int nod = parinte[i];
            capacitati[nod][i] -= flow;
            capacitati[i][nod] += flow;
            lista_ad[i].push_back(nod);
            i = parinte[i];
        }
        maxFlow += flow;
    }
    int rez = abs(n - maxFlow);
    cout << rez;
}