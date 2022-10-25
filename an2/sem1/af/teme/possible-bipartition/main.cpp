#include <iostream>
#include <fstream>
#include <vector>

#define BLUE 1
#define RED (-1)

using namespace std;

class Graph {
private:
    int N, M;
    vector<vector<int>> adj_list;
    vector<vector<int>> bipartition;
public:
    Graph(int _N, int _M, vector<vector<int>> _adj_list) : N(_N), M(_M), adj_list(std::move(_adj_list)) {
        this->bipartition.resize(_N+1);
    }

    // am facut un dfs la care am adaugat 2 parametrii noi, un vector de culori si un int pentru culoare: culoare = {-1, 1}
    void color_dfs(const int &node, vector<int> &sel, vector<int> &colors, int color) {
        sel[node] = 1;
        colors[node] = color;
        bipartition[color+1].push_back(node);
        for (auto neighbour: adj_list[node]) {
            if (sel[neighbour] == 0) {
                color_dfs(neighbour, sel, colors, -color); // aici colorez vecinul cu culoarea opusa
            }
        }
    }

    vector<vector<int>> get_bipartitions() {
        return bipartition;
    }

};

class Solution {
public:

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> dislikes_list(n+1);

        // fac o lista de adiacenta din dislikes
        for (int i = 0; i < dislikes.size(); i++) {
            dislikes_list[dislikes[i][0]].push_back(dislikes[i][1]);
            dislikes_list[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        Graph graph(n, dislikes.size(), dislikes_list);
        vector<int> colors(n+1), sel(n+1, 0);

        // ma folosesc de un for in caz ca sunt mai multe componente conexe
        for (int i = 1; i <= n; i++) {
            if (sel[i] == 0)
                graph.color_dfs(i, sel, colors, BLUE);
        }

        // verific pentru fiecare nod daca vecinii lui au culori diferite
        for (int node = 1; node <= n; node++) {
            for (auto neighbour : dislikes_list[node]) {
                if (colors[node] == colors[neighbour])
                    return false;
            }
        }

        return true;
    }

    vector<vector<int>> possibleBipartitionV2(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> dislikes_list(n+1);
        vector<vector<int>> impartire;

        for (int i = 0; i < dislikes.size(); i++) {
            dislikes_list[dislikes[i][0]].push_back(dislikes[i][1]);
            dislikes_list[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        Graph graph(n, dislikes.size(), dislikes_list);
        vector<int> colors(n+1), sel(n+1, 0);

        for (int i = 1; i <= n; i++) {
            if (sel[i] == 0)
                graph.color_dfs(i, sel, colors, BLUE);
        }

        for (int node = 1; node <= n; node++) {
            for (auto neighbour : dislikes_list[node]) {
                if (colors[node] == colors[neighbour])
                    return {};
            }
        }

        return graph.get_bipartitions(); // la fel ca algoritmul trecut doar ca aici returnez cei 2 vectori ce contin o varianta de bipartitie
    }
};


int main() {
    ifstream fin("date.in");
    int n, dis;

    fin >> n >> dis;

    vector<vector<int>> dislikes(dis);

    for (int i = 0; i < dis; i++) {
        int a, b;
        fin >> a >> b;
        dislikes[i].push_back(a);
        dislikes[i].push_back(b);
    }

    Solution sol;

    cout << sol.possibleBipartition(n, dislikes) << endl;

    vector<vector<int>> partitions = sol.possibleBipartitionV2(n, dislikes);
    for (int i = 0; i<=2; i+=2) {
        for (auto el : partitions[i])
            cout << el << ' ';
        cout << endl;
    }

    return 0;
}
