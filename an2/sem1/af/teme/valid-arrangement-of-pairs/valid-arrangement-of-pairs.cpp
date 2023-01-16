#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

/*
 * 
 - consideram multimea perechilor ca fiind muchiile unui graf orientat si aplicam algoritmul lui Hierholzer pentru a afla 
 daca avem un ciclu eulerian sau nu ([[5,1],[4,5],[11,9],[9,4]])
*/
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, list<int>> graf;
        unordered_map<int, int> muchii;
        unordered_map<int, int> grade;

        // construim graful si calculam gradele
        for (auto pereche : pairs) {
            graf[pereche[0]].push_back(pereche[1]);
            muchii[pereche[0]]++;
            grade[pereche[1]]--;
            grade[pereche[0]]++;
        }
        /*
            -  pentru a afisa raspunsul corect ne folosim de algoritmul lui Hierholzer’s cu care construim circuitul
            - ne ducem pe muchii nevizitate si le eliminam pana ne blocam; apoi revenim la cel mai apropiat nod care are muchii nevizitate(in else-ul din while) si repetam procesul pana am folosit toate muchiile
        */
        int count = 0;
        stack<int> currPath;
        vector<int> circuit;
        for (auto i : grade) {
            if (i.second != 0) {
                count++;
                if (i.second>0) {
                    currPath.push(i.first);
                }
            }
        }

        if (count % 2 != 0 || count > 2)
            return {};

        if (currPath.empty())
            currPath.push(pairs[0][0]);

        int currV = currPath.top();
        while (!currPath.empty()) {
            if (muchii[currV]) {
                currPath.push(currV);
                muchii[currV]--;

                int nextV = graf[currV].back();
                graf[currV].pop_back();
                currV = nextV;
            }
            else {
                circuit.push_back(currV);
                currV = currPath.top();
                currPath.pop();
            }
        }

        vector<vector<int>> res;
        for (int i = circuit.size() - 1; i > 0; i--) {
            res.push_back({circuit[i], circuit[i - 1]});
        }

        return res;
    }
};
