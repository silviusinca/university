#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
/*
folosesc un bfs din sursa in destinatie pe capacitati: pornesc cu o capacitate data c si merg pe acele noduri care formeaza muchii 
cu capacitati mai mari decat c, adica aleg drumurile pe care se poate merge cu cel putin greutatea c
gasesc greutatea minima pt. care bfs gaseste drum prin cautare binara, apoi fac bfs pe greutatile mai mari sa vad daca pot alege alta
*/

ifstream fin("transport2.in");
ofstream fout("transport2.out");

struct vecin {
    int nod, capacitate; 
};

vector<vector<vecin>> lista_ad; 
vector<int> sel;

int n;

int bfs(int c) {
    queue<int> q;

    fill(sel.begin(), sel.end(), 0);
    q.push(1);
    sel[1] = 1;

    while (!q.empty()) {
        int nod = q.front();
        q.pop();

        if (nod == n)
            return nod;

        for (int i = 0; i < lista_ad[nod].size(); i++) {
            int vecin = lista_ad[nod][i].nod;

            if (sel[vecin] == 0 && lista_ad[nod][i].capacitate >= c) {
                // daca vecinul nu e vizitat si drumul nod->vecin are o capacitate >= decat greutatea camionului
                // atunci el isi poate continua traseul pe drumul care trece prin vecin
                sel[vecin] = 1;
                q.push(vecin);
            }
        }
    }

    return 0;
}

int main() {
    int m, rez, st = 1, dr = -1;
    
    fin >> n >> m;
    lista_ad.resize(n+1);
    sel.resize(n+1, 0);
    int x, y, c;

    for (int i = 0; i < m; i++) {
        fin >> x >> y >> c;
        vecin aux;
        aux.nod = y;
        aux.capacitate = c;
        lista_ad[x].push_back(aux);
        aux.nod = x;
        lista_ad[y].push_back(aux);
        dr = max(dr, c);
    }

    while (st <= dr) {
        int m = (st + dr) / 2;
        // daca am gasit drum pt greutatea curenta
        if (bfs(m) == n) {
            // pastrez greutatea si continui sa caut o capacitate mai mare
            rez = m; 
            st = m + 1; 
        }
        else {
            // daca nu am drum inseamna ca am nevoie de o greutatea mai mica
            dr = m - 1; 
        }
    }

    fout << rez;


    return 0;
}