#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

/* Explicatie
    Ma folosesc de sortarea topologica si la finalul metodei verific daca am mai multe zerouri in vectorul de order; daca am mai multe zerouri inseamna ca sunt cursuri pe care nu le pot lua deoarece depind exista alte cursuri care depind de ele si se creaza un ciclu
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses, 0);
        vector<vector<int>> adj_list(numCourses);

        for (auto & prereq : prerequisites) {
            degrees[prereq[0]]++;
            adj_list[prereq[0]].push_back(prereq[1]);
            adj_list[prereq[1]].push_back(prereq[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order(numCourses);
        int count = 0;
        while(!q.empty()) {
            int i = q.front();
            order[count++] = i;
            q.pop();

            for (int & j : adj_list[i]) {
                degrees[j]--;
                if (degrees[j] == 0) {
                    q.push(j);
                }
            }
        }

        vector<int> aux(numCourses, 0);
        if (order.size() == 1)
            return {0};

        int zeroCnt = 0;
        for (int i = 0; i < numCourses; i++) {
            if (order[i] == 0)
                zeroCnt++;
        }
        if (zeroCnt > 1)
            return {};

        return order;
    }

    /* aici am refacut metoda pentru cerinta b: la final cand verific cate zerouri sunt in order, daca am mai multe noduri care au order[nod] = 0 le introduc intr-un vector si il returnez */

    vector<int> findOrderV2(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses, 0);
        vector<vector<int>> adj_list(numCourses);

        for (auto & prereq : prerequisites) {
            degrees[prereq[0]]++;
            adj_list[prereq[0]].push_back(prereq[1]);
            adj_list[prereq[1]].push_back(prereq[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order(numCourses);
        int count = 0;
        while(!q.empty()) {
            int i = q.front();
            order[count++] = i;
            q.pop();

            for (int & j : adj_list[i]) {
                degrees[j]--;
                if (degrees[j] == 0) {
                    q.push(j);
                }
            }
        }

        if (order.size() == 1)
            return {0};

        int zeroCnt = 0;

        for (int i = 0; i < numCourses; i++) {
            if (order[i] == 0)
                zeroCnt++;
        }

        vector<int> circulare;
        if (zeroCnt > 1) {
            for (int i = 0; i < numCourses; i++) {
                if(order[i] == 0)
                    circulare.push_back(i);
            }
            return circulare;
        }


        return {};
    }
};

int main() {
    ifstream fin("date.in");
    int numCourses, numPrereq;

    fin >> numCourses >> numPrereq;

    vector<vector<int>> prerequisites(numPrereq);

    int a, b, i = 0;
    while(fin >> a >> b) {
        prerequisites[i].push_back(a);
        prerequisites[i].push_back(b);
        i++;
    }

    Solution sol;

    for (auto el : sol.findOrder(numCourses, prerequisites))
        cout << el << ' ';

    vector<int> circulare = sol.findOrderV2(numCourses, prerequisites);
    for (auto el : circulare)
        cout << el << ' ';

    return 0;
}
