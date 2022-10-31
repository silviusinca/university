#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* Explicatie
    - rezolvarea obtine doar 90 de puncte pe infoarena, am time limit exceded la ultimele 2 teste;
*/

// am creat o clasa pentru algoritmul Tarjan;
class Tarjan {
private:
    int N, M, id, ctc_count;
    vector<vector<int>> adj_list;
    vector<int> ids;
    vector<int> low;
    vector<bool> sel;
    stack<int> st;
    vector<int> ctc;
    unordered_map<int, vector<int>> componente;

public:
/*  aici imi initializez ce am nevoie:
        - N, M = noduri, muchii
        - adj_list = lista de adiacenta
        - ids = id-urile fiecarui nod
        - low = retin pentru fiecare nod cel mai mic nod la care poate ajunge in componenta tare conexa in care se afla
        - sel = vector in care retin prin ce noduri am trecut deja
        - ctc_count = numarul de elemente tari conexe
        - componente = un hash cu componentele tari conexe gasite
 */
    Tarjan(int N, int M, vector<vector<int>> adj_list) {
        this->N = N;
        this->M = M;
        this->adj_list = std::move(adj_list);
        this->ids.resize(N+1, -1);
        this->low.resize(N+1, 0);
        this->sel.resize(N+1, false);
        this->id = 0;
        this->ctc_count = 0;
        componente.reserve(N+1);
    }

    void dfs(int node) {
        st.push(node);
        sel[node] = true;
        ids[node] = id;
        low[node] = id++;

        for (auto neighbour : adj_list[node]) {
            if (ids[neighbour] == -1) // daca e nevizitat apelez dfs; toate nodurile au id = -1 de la inceput
                dfs(neighbour);
            if (sel[neighbour])
                low[node] = min(low[node], low[neighbour]); // low[nod] va fi nodul cu id-ul cel mai mic la care ma pot duce
        }

        // daca am id[node] = low[node] inseamna ca am o componenta tare conexa noua deoarece nu mai exista alt vecin cu id mai mic la care ma pot duce
        if (ids[node] == low[node]) {
            while(!st.empty()) {
                // eliberez stiva care contine nodurile din componenta tare conexa gasita si le adaug in "componente"
                int el = st.top();
                sel[el] = false;
                componente[ctc_count].push_back(el); 
                st.pop();
                if (el == node)
                    break;
            }
            ctc_count++;
        }
    }

    // fac un dfs pentru fiecare nod
    unordered_map<int, vector<int>> findCtc() {
        for (int i = 1; i <= N; i++) {
            if (ids[i] == -1) {
                dfs(i);
            }
        }
        return componente;
    }

    int get_ctc_count() const { 
        return this->ctc_count; // iau numarul de componente
    }
};

int main() {
    ifstream fin("ctc.in");
    ofstream fout("ctc.out");

    int n, m, a, b;
    fin >> n >> m;

    vector<vector<int>> lista_ad(n + 1);

    for (int i = 1; i <= m; i++) {
        fin >> a >> b;
        lista_ad[a].push_back(b);
    }

    Tarjan tarjan(n, m, lista_ad);
    unordered_map<int, vector<int>> ctc = tarjan.findCtc();
    int count = tarjan.get_ctc_count();

    fout << count << '\n';

    for (const auto& componenta : ctc) {
        for (auto nod : componenta.second)
            fout << nod << ' ';
        fout << endl;
    }

    return 0;
}
