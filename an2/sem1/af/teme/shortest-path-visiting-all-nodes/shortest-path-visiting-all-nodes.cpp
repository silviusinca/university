#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/*
 * Vom face un fel de bfs, doar ca avem voie sa ne intoarcem si sa revizitam nodurile pentru a gasi solutia
 * Ne folosim de 2 stringuri in care vom avea statusul vizitelor, daca am vizitat sau nu nodurile
 *
 *
 * */
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        string statusCurent = "";
        string vizitate = "";
        queue<pair<int, string>> queue;
        set<pair<int, string>> set;

        for (int i = 0; i < graph.size(); i++) {
            statusCurent += '0';
            vizitate += '1';
        }

        for (int i = 0; i < graph.size(); i++) {
            string aux = statusCurent;
            aux[i] = '1';
            pair<int, string> pereche = make_pair(i, aux);
            queue.push(pereche);
            set.insert(pereche);
        }

        int length = 0;

        while (!queue.empty()) {

            int size = queue.size();
            for (int i = 0; i < size; i++) {
                pair<int, string> front = queue.front();
                queue.pop();

                if (front.second == vizitate) {
                    return length;
                }

                for (auto p : graph[front.first]) {
                    string aux = front.second;
                    aux[p] = '1';
                    pair<int, string> pereche = make_pair(p, aux);
                    if (set.count(pereche) == 0) {
                        queue.push(pereche);
                        set.insert(pereche);
                    }
                }
            }
            length++;
        }
        return -1;
    }
};
