#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


class Graph {
private:
    int N, M, K;
    vector<vector<pair<int, int>>> adj_list;
    vector<int> catun, dist;
    priority_queue<pair<int, int>> heap;


public:
    Graph(int _N, int _M, vector<vector<pair<int, int>>> _adj_list, int _K, vector<int> _catun, priority_queue<pair<int, int>> _heap, vector<int> _dist) : N(_N), M(_M), adj_list(std::move(_adj_list)), K(_K), catun(_catun), heap(_heap), dist(_dist) {
    }

    void dijkstra() {
        while (!heap.empty()) {
            int node = heap.top().second;
            heap.pop();

            for (auto pair: adj_list[node]) {
                int neighbour = pair.first;
                int length = pair.second;

                if (dist[node] + length < dist[neighbour]) {
                    dist[neighbour] = dist[node] + length;
                    catun[neighbour] = catun[node];
                    heap.push({-dist[neighbour], neighbour});
                }

                if (dist[node] + length == dist[neighbour] && catun[node] < catun[neighbour]) {
                    catun[neighbour] = catun[node];
                    heap.push({-dist[neighbour], neighbour});
                }
            }
        }
    }

    vector<int> getCatun() {
        return catun;
    }

};

int main() {
    ifstream fin("catun.in");
    ofstream fout("catun.out");

    int N, M, K, x, y, z;

    fin >> N >> M >> K;

    vector<int> catun(N+1);
    priority_queue<pair<int, int>> heap;
    vector<vector<pair<int, int>>> adj_list(N+1);
    vector<int> dist(N+1, INT_MAX);

    for (int i = 0; i < K; i++) {
        fin >> x;
        catun[x] = x;
        dist[x] = 0;
        heap.push(make_pair(0, x));
    }

    for (int i = 0; i < M; i++) {
        fin >> x >> y >> z;
        adj_list[x].push_back({y, z});
        adj_list[y].push_back({x, z});
    }

    Graph graph(N, M, adj_list, K, catun, heap, dist);

    graph.dijkstra();
    catun = std::move(graph.getCatun());

    for (int i = 1; i <= N; i++) {
        if (i == catun[i])
            fout << 0 << ' ';
        else
            fout << catun[i] << ' ';
    }


    return 0;
}
