#include <iostream>
#include <fstream>

std::ifstream fin("deque.in");
std::ofstream fout("deque.out");

int N, K, deq[5000001], vect[5000001];
int main() {
    long long suma = 0;

    fin >> N >> K;

    int i = 0;
    while (fin >> vect[i++]);

    int fata = 0, spate = -1;

    for (i = 0; i < N; i++) {
        while (vect[i] <= vect[deq[spate]] && fata <= spate) {
            spate--;
        }
        spate++;
        deq[spate] = i;

        if (deq[fata] == i - K) {
            fata++;
        }
        if (i+1 >= K) {
            suma += vect[deq[fata]];
        }
    }

    fout << suma;

    return 0;
}
