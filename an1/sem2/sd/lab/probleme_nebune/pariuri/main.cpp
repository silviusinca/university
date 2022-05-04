#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

ifstream fin("pariuri.in");
ofstream fout("pariuri.out");

int main() {

    unordered_map<long long, int> pariuri;
    int N, M, bani;
    long long timp;
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> M;
        for (int j = 0; j < M; j++) {
            fin >> timp >> bani;
//            pariuri.insert(timp, bani);
//            if (pariuri.find(timp) == pariuri.end())
//                pariuri.emplace(timp, bani);
//            else
            pariuri[timp] += bani;
        }
    }

    fout << pariuri.size() << endl;

    for (auto el : pariuri)
        fout << el.first << ' ' << el.second << ' ';

    return 0;
}
