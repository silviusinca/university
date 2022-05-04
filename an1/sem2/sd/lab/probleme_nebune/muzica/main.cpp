#include <fstream>
#include <unordered_set>

using namespace std;

int main() {
    ifstream fin("muzica.in");
    ofstream fout("muzica.out");
    unordered_set<long long> muzicav(100002);
    long long A, B, C, D, E, melodie, i, N, M, nr = 0;
    ios_base::sync_with_stdio(false);
    fin >> N >> M;
    fin >> A >> B >> C >> D >> E;
    for (i = 0; i < N; i++) {
        fin >> melodie;
        muzicav.insert(melodie);
    }
    if (muzicav.find(A) != muzicav.end()) {
        nr++;
        muzicav.erase(A);
    }
    if (muzicav.find(B) != muzicav.end()) {
        nr++;
        muzicav.erase(B);
    }
    for (i = 2; i < M; i++) {
        melodie = (C * B + D * A) % E;
        if (muzicav.find(melodie) != muzicav.end()) {
            nr++;
            muzicav.erase(melodie);
        }
        A = B;
        B = melodie;
    }
    fout << nr;
    return 0;
}
