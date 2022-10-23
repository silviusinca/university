#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>

/* Explicatie:
    In metoda check_dfs fortez parcurgerea astfel incat sa incerc sa parcurg graful identic cu permutarea data. Pornesc de la primul nod din permutare si pentru toate celelalte verific vecinii, si daca vreunul dintre ei se gaseste pe pozitia dorita in permutare continui dfs; daca nu, mai verific odata vecinii nodului si daca gasesc unul prin care nu am trecut inseamna ca permutarea nu este o parcuregere corecta


*/

using namespace std;

class Graph {
private:
    int N, M;
    vector<vector<int>> lista_ad;

public:
    Graph(int _N, int _M, vector<vector<int>> _lista_ad) : N(_N), M(_M), lista_ad(std::move(_lista_ad)) {}

    bool check_dfs(vector<int> permutare) {
        vector<int> sel(N+1, 0);
        stack<int> noduri;

        int i = 0;
        noduri.push(permutare[i++]);
        sel[noduri.top()] = 1;

        while (!noduri.empty() && i < permutare.size()) {
            int nod = noduri.top();
            bool gasit = false;
            int perm = permutare[i];

            for (int& vecin : lista_ad[nod]) {
                if (sel[vecin] == 0 && vecin == perm) {
                    sel[perm] = 1;
                    noduri.push(perm);
                    i++;
                    gasit = true;
                }
            }

            if (gasit == false) {
                for (int& vecin: lista_ad[nod])
                    if (sel[vecin] == 0) {
                        return false;
                    }
                noduri.pop();
            }
        }

        return i == permutare.size();
    }
};

int main() {
    ifstream fin("check.in");

    int N, M, a, b;
    vector<int> permutare;

    fin >> N >> M;

    vector<vector<int>> lista_ad(N+1);

    for (int i = 0; i < N; i++) {
        fin >> a;
        permutare.push_back(a);
    }

    for (int i = 1; i <= M; i++) {
        fin >> a >> b;
        lista_ad[a].push_back(b);
        lista_ad[b].push_back(a);
    }

    Graph graph = *new Graph(N, M, lista_ad);
    cout << graph.check_dfs(permutare);

    return 0;
}
