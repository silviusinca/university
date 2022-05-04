#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

int main() {
    int nr_op, op, x;
    int P = 666013;// numarul prim pentru functia de disperise
    int gasit, cheie;
    vector<vector<int>> hash(P+5);

    fin >> nr_op;
    for (int i = 0; i < nr_op; i++) {
        fin >> op >> x;
        cheie = x % P;
        gasit = 0;
        int j;
        for (j = 0; j < hash[cheie].size() && !gasit; j++) {
            if (hash[cheie][j] == x)
                gasit = 1;
        }

        if (op == 1 && !gasit) hash[cheie].push_back(x);

        if (op == 2) {
            if (gasit) {
                swap(hash[cheie][j-1], hash[cheie].back());
                hash[cheie].pop_back();
            }
        }

        if (op == 3) fout << gasit << '\n';
    }
    return 0;
}
