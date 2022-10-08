#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

class Graf {
private:
    int N, M;
    vector<vector<int>> lista_ad;

public:
    Graf(int N, int M, vector<vector<int>> lista_ad) {
        this->N = N;
        this->M = M;
        this->lista_ad = std::move(lista_ad);
    }

    void dfs(const int &nod, vector<int> &viz) {
        viz[nod] = 1;
        for (auto vec : lista_ad[nod]) {
            if (viz[vec] == 0)
                dfs(vec, viz);
        }
    }

    int nrCompConex() {
        int nr = 0;
        vector<int> viz(N+1, 0);
        for (int i = 1; i <= N; i++) {
            if (viz[i] == 0) {
                nr++;
                dfs(i, viz);
            }
        }
        return nr;
    }
};

int main() {
    int N, M, x, y;
    ifstream fin("dfs.in");
    ofstream fout("dfs.out");

    fin >> N >> M;

    vector<vector<int>> lista_ad(N);

    for (int i = 0; i < M; i++) {
        fin >> x >> y;
        lista_ad[x].push_back(y);
    }

    Graf graf = *new Graf(N, M, lista_ad);
    int rasp = graf.nrCompConex();

    fout << rasp;

    return 0;
}
