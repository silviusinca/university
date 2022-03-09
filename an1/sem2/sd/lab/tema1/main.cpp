#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include <stdlib.h>

using namespace std;

// functie prin care se verifica daca vectorul este sortat corect
bool test_sort(vector<int>& vect, int N) {
    int i;
    for (i = 0; i < N-1; i++)
        if (vect[i] > vect[i+1])
            return false;
    return true;
}

// functie prin care se genereaza un vector de numere random
void generateNumbers(vector<int>& vect, int N, int Max) {
    int i;
    srand(time(0));
    for (i = 0; i < N; i++) {
        vect.push_back(rand() % Max);
    }
}

void afis(const vector<int>& vect) {
    for (auto num : vect) {
        cout << num << ' ';
    }
    cout << endl;
}

void radixSort(vector<int>& vect, int N, int maxCifre) {

    // start cronometru
    auto start = std::chrono::high_resolution_clock::now();

    int i, j, m, p = 1, index, temp, count = 0;
    vector<int> pocket[10];
    for (i = 0; i < maxCifre; i++) {
        m = pow(10, i+1);
        p = pow(10, i);
        for(j = 0; j < N; j++) {
            temp = vect[j]%m;
            index = temp/p;
            pocket[index].push_back(vect[j]);
        }
        count = 0;
        for (j = 0; j<10; j++) {
            //delete from linked lists and store to array
            while (!pocket[j].empty()) {
                vect[count] = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }

//    afis(vect);
    // stop cronometru
    auto stop = std::chrono::high_resolution_clock::now();
    cout << "Timp de executare (in secunde): " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000000.00000000000000 << endl;

}

int main() {
    vector<int> v;
    int N = 1000000, Max = 1000000;
    generateNumbers(v, N, Max);
    radixSort(v, N, 6);

    return 0;
}
