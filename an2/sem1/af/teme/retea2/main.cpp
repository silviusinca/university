#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <math.h>
#include <climits>

using namespace std;


double distanta(tuple<int, int> a, tuple<int, int> b) {
    return sqrt(1.0 * pow((get<0>(a) - get<0>(b)), 2) + 1.0 * pow((get<1>(a) - get<1>(b)), 2));
}

int main() {
    ifstream fin("retea2.in");
    ofstream fout("retea2.out");
    int n, m, x, y, bloc = -1;
    double cost = 0, dist_min = INT_MAX;

    fin >> n >> m;

    vector<tuple<int, int>> blocuri, centrale;
    vector<double> distante(m, INT_MAX); // m distante
    vector<int> sel(m);

    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        centrale.emplace_back(x, y); // .push_back(make_tuple(x, y));
    }

    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        blocuri.emplace_back(x, y);
    }

    // distanta de la blocuri la centrale
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            distante[i] = min(distante[i], distanta(blocuri[i], centrale[j]));
        }
    }

    for (int i = 0; i < m; i++) {
        bloc = -1, dist_min = INT_MAX; // bloc -> blocul nevizitat cu distanta minima fata de o centrala
        for (int j = 0; j < m; j++) {
            if (distante[j] < dist_min && sel[j] == 0) {
                bloc = j;
                dist_min = distante[j];
            }
        }

        cost += dist_min;
        sel[bloc] = 1;

        for (int j = 0; j < m; j++) {
            distante[j] = min(distante[j], distanta(blocuri[j], blocuri[bloc]));
        }
    }

    fout.precision(6);
    fout << fixed << cost;

    return 0;
}
