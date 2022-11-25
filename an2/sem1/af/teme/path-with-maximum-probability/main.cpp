#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<tuple<double, int>, vector<tuple<double, int>>, greater<>> minHeap;
        vector<double> distance(n, 0);
        vector<int> sel(n, 0);
        vector<vector<tuple<int, double>>> adj_list(n);

        for (int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj_list[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        distance[start] = -1;
        minHeap.push(make_tuple(-1, start));

        while (!minHeap.empty()) {
            auto aux = minHeap.top();
            double dist = get<0>(aux);
            int node = get<1>(aux);
            minHeap.pop();

            if (!sel[node]) {
                sel[node] = 1;
                for (auto el : adj_list[node]) {
                    int neighbour = get<0>(el);
                    double nextDist = dist * get<1>(el);
                    if (not sel[neighbour] and nextDist < distance[neighbour]) {
                        distance[neighbour] = nextDist;
                        minHeap.push(make_tuple(nextDist, neighbour));
                    }
                }
            }
        }

        return -distance[end];
    }
};

int main() {
    ifstream fin("date.in");

    int n, m, start, end, i, x, y;

    fin >> n >> m;
    vector<vector<int>> edges(m);
    vector<double> succProb;

    for (i = 0; i < m; i++) {
        fin >> x >> y;
        edges[i].push_back(x);
        edges[i].push_back(y);
    }

    double prob;
    for (i = 0; i < m; i++) {
        fin >> prob;
        succProb.push_back(prob);
    }

    fin >> start >> end;

    Solution sol;

    auto xx = sol.maxProbability(n, edges, succProb, start, end);

    cout << xx;

    return 0;
}
