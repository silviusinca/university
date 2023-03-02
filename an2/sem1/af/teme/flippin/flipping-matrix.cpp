#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, M[1005][1005];
vector<int> sel(n+1, 0);
vector<int> dreapta(n+1), stanga(n+1);
vector<int> pozitii(n+1, 0);

bool FindMatch(int nod) {
    if (sel[nod]) {
        return false;
    }
    sel[nod] = true;

    // caut vecinii nodului curent pentru care nu avem legatura
    for (int i = 1; i <= n; i++) {
        if (M[nod][i] && stanga[i] == 0) {
            dreapta[nod] = i;
            stanga[i] = nod;
            return true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (M[nod][i] && FindMatch(stanga[i])) {
            dreapta[nod] = i;
            stanga[i] = nod;
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> M[i][j];
        }
    }

    stanga.resize(n+1, 0);
    dreapta.resize(n+1, 0);

    bool k = true;
    while(k) {
        k = false;

        for (int i = 1; i <= n; i++) {
            sel[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            if (dreapta[i] == 0 and FindMatch(i)) {
                k = true;
            }
        }
    }

    // calculeaza numarul de match-uri
    int nr = 0;
    for (int i = 1; i <= n; i++) {
        if (dreapta[i]) {
            nr++;
        }
    }

    // daca nu se pot face n match-uri, atunci nu se pot realiza mutarile
    if (nr != n) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        pozitii[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (dreapta[i] == pozitii[i]) {
            continue;
        }

        // daca elementul nu este pe diagonala principala, caut linia care se potriveste
        int linie = 0;
        for (int j = 1; j <= n; j++) {
            if (pozitii[j] == dreapta[i]) {
                linie = j;
                break;
            }
        }

        cout << "R " << pozitii[i] << " " << pozitii[linie] << endl;
        swap(pozitii[linie], pozitii[i]);
    }

    return 0;
}