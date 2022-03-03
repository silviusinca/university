#include <iostream>
#include <vector>

using namespace std;

int verifStanga(vector<int> vect, int x) {
    int index = -1, mij, s = 0, d = vect.size()-1;

    while (s <= d) {
        mij = (s + d)/2;
        if (x == vect[mij]) {
            index = mij;
            d = mij - 1;
        }
        else if (x < vect[mij])
            d = mij - 1;
        else
            s = mij + 1;
    }
    return index;
}

int verifDreapta(vector<int> vect, int x) {
    int index = -1, mij, s = 0, d = vect.size()-1;

    while (s <= d) {
        mij = (s + d)/2;
        if (x == vect[mij]) {
            index = mij;
            s = mij + 1;
        }
        else if (x < vect[mij])
            d = mij - 1;
        else
            s = mij + 1;
    }
    return index;
}

int rez(vector<int> vect, int x) {
    int s = verifStanga(vect, x);
    if (s != -1) {
        int d = verifDreapta(vect, x);
        return d - s + 1;
    }
    return -1;
}

int main() {
    //                0  1  2  3  4  5  6  7  8  9  10 11
    vector<int> test {1, 2, 3, 4, 5, 6, 6, 8, 9, 10, 11, 12};
    cout << rez(test, 7);
    return 0;
}
