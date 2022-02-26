#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;


vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c;
    int i = 0, j = 0;

    while (i != a.size() && j != b.size()) {
        if (a[i] < b[j]) {
            c.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            c.push_back(b[j]);
            j++;
        } else {
            c.push_back(a[i]);
            c.push_back(a[i]);
            i++; j++;
        }
    }
    while (i < a.size()) {
        c.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        c.push_back(b[j]);
        j++;
    }

    return c;
}

int main() {
/*
    long long v[100] = {0};
    srand(time(0));
    for (int i = 0; i < 100; ++i) {
        v[i] = rand() % 1000;
        cout << v[i] << ' ';
    }
 */

    vector<int> a, b, c;

    for (int i = 0; i < 25; i += 2)
        a.push_back(i);

    for (int i = 1; i < 25; i += 2)
        b.push_back(i);

    c = merge(a, b);

    for (auto i : c) {
        cout << i << ' ';
    }

    return 0;
}
