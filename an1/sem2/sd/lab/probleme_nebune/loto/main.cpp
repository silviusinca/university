#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

ifstream fin("loto.in");
ofstream fout("loto.out");

int main() {
    unordered_map<int, vector<int>> loto;
    vector<int> numere(3), vect;
    long long N, S;
    int ok = 1;

    fin >> N >> S;
    for (int i = 0; i < N; i++)
        fin >> vect[i];

    int s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j; k < N; k++) {
                s = vect[i] + vect[j] + vect[k];
                vector<int> aux {vect[i], vect[j], vect[k]};
                loto[s] = aux;
            }
        }
    }

    for (auto el : loto) {
        for (int i = 0; i < el.second.size(); i++)
            cout << el.second[i] << ' ';
    }

    if (ok) fout << -1;



    return 0;
}
