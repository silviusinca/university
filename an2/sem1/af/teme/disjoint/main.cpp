#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> tata;

int radacina(int nod) {
    if(tata[nod] == 0)
        return nod;
    tata[nod] = radacina(tata[nod]);
    return tata[nod];
}

int main() {
    ifstream fin("disjoint.in");
    ofstream fout("disjoint.out");
    int n, m, op, x, y;

    fin >> n >> m;

    tata.resize(n+1);

    for (int i = 1; i <= m; i++) {
        fin >> op >> x >> y;

        if (op == 1) {
            int tx = radacina(x);
            int ty = radacina(y);
            tata[ty] = tx;
        }
        else if (op == 2) {
            if (radacina(x) == radacina(y))
                fout << "DA\n";
            else
                fout << "NU\n";
        }
    }

    return 0;
}
