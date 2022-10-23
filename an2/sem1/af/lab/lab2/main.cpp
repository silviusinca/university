#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("sortaret.in");
ofstream fout("sortaret.out");
int main() {
    int N, M, X, Y;
    fin >> N >> M;

    vector<int> grade(N+1, 0);
    vector<vector<int>> lista_ad(N+1, {0});

    for (int i = 1; i <= M; i++) {
        fin >> X >> Y;
        lista_ad[X].push_back(Y);
        lista_ad[Y].push_back(X);
        grade[Y]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (grade[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int i = q.front();
        fout << i << ' ';
        q.pop();

        for (int j = 0; j < lista_ad[i].size(); j++) {
            grade[lista_ad[i][j]]--;
            if (grade[lista_ad[i][j]] == 0) {
                q.push(lista_ad[i][j]);
            }
        }
    }
    return 0;
}
