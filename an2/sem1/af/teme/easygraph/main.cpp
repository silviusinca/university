#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
private:
    int N, M;
    vector<vector<int>> adj_list;
    vector<long long> sel, dist, val;
    long long suma;

public:
    Graph(int _N, int _M, vector<vector<int>> _adj_list, vector<long long> _val) : N(_N), M(_M), adj_list(std::move(_adj_list)), val(std::move(_val)) {}

    void init() {
        suma = INT_MIN;
        dist.resize(N + 1);
        sel.resize(N + 1, 0);
    }

    void dfs(int st) {
        sel[st] = true;
        dist[st] = val[st];
        for (auto node: adj_list[st]) {
            if (!sel[node])
                dfs(node);
            if (dist[st] < dist[node] + val[st])
                dist[st] = dist[node] + val[st];
        }
        if (suma < dist[st]) {
            suma = dist[st];
        }
    }

    bool isVisited(int node) {
        return sel[node] == 1;
    }

    long long getSuma() {
        return suma;
    }
};

int main() {
    ifstream fin("easygraph.in");
    ofstream fout("easygraph.out");

    int T, N, M, x, y;

    fin >> T;

    for (int i = 0; i < T; i++) {
        fin >> N >> M;
        vector<vector<int>> adj_list(N+1);
        vector<long long> val(N+1);

        for (int j = 1; j <= N; j++)
            fin >> val[j];

        for (int j = 0; j < M; j++) {
            fin >> x >> y;
            adj_list[x].push_back(y);
        }

        Graph gf(N, M, adj_list, val);
        gf.init();

        for (int j = 1; j <= N; j++) {
            if (!gf.isVisited(j))
                gf.dfs(j);
        }
        fout << gf.getSuma() << "\n";
    }


    return 0;
}
