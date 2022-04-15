#include <iostream>
#include <fstream>
#include <deque>
#include <vector>

using namespace std;

ifstream fin("vila2.in");
ofstream fout("vila2.out");

int main() {

    int n, k, varsta, maxi = 0;

    fin >> n >> k;

    vector<int> v;
    deque<int> vmin, vmax;

    for (int i = 0; i < n; i++) {
        fin >> varsta;
        v.push_back(varsta);
    }

    for (int i = 0; i < n; i++) {
        while (!vmax.empty() && v[i] > v[vmax.front()])
            vmax.pop_front();
        vmax.push_front(i);

        while (i - k > vmax.back())
            vmax.pop_back();

        while (!vmin.empty() && v[i] <= v[vmin.front()])
            vmin.pop_front();

        vmin.push_front(i);

        while (i - k > vmin.back())
            vmin.pop_back();

        maxi = max(maxi, abs(v[vmax.back()] - v[vmin.back()]));
    }

    fout << maxi;

    fin.close();
    fout.close();

    return 0;
}
