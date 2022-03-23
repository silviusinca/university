#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <stdlib.h>
#include <math.h>

using namespace std;

ofstream fout("rezultat.txt");

// functie prin care se verifica daca vectorul este sortat corect
bool test_sort(vector<int>& vect, int N) {
    int i;
    for (i = 0; i < N-1; i++)
        if (vect[i] > vect[i+1]) {
            fout << "Sortarea a esuat!\n";
            return false;
        }
    fout << "Sortarea a fost corecta!\n";
    return true;
}

// functie prin care se genereaza un vector de numere random
void generateNumbers(vector<int>& vect, int N, int Max) {
    vect.clear();
    int i;
    srand(time(0));
    for (i = 0; i < N; i++)
        vect.push_back(rand() % Max);
}

void afis(const vector<int>& vect) {
    for (auto num : vect) {
        fout << num << ' ';
    }
    fout << endl;
}

void bubbleSort(vector<int>& vect, int N) {
    fout << "--------------------------\n";
    fout << "Bubble Sort:\n";
    auto start = std::chrono::high_resolution_clock::now();
    int i, j, aux;
    for (i = 0; i < N; i++)
        for (j = 0; j < i; j++)
            if (vect[i] < vect[j])
                swap(vect[i], vect[j]);

    auto stop = std::chrono::high_resolution_clock::now();
    auto timp = (double)std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()/1000000;
    if (timp < 600) {  // daca sortarea dureaza mai mult de 10 minute sar peste;
        if (test_sort(vect, N))
            fout << "Timp de executare pentru Bubble Sort (in secunde): " << timp << endl;
    } else
        fout << "Sortarea dureaza prea mult!\n";
    fout << "--------------------------\n";
}

vector<vector<int>> generateShellSortGaps(int N) {
    vector<vector<int>> gaps;

    vector<int> sedgewick;
    vector<int> ciura = {1, 4, 10, 23, 57, 132, 301, 701};
    vector<int> tokuda = {1, 4, 9, 20, 45, 102, 230, 516, 1158, 2599, 5831, 13082, 29351, 65853, 147748, 331490, 743735};

    int k = 1, gap = 1;

    sedgewick.push_back(gap);
    while (gap < N / 2) {
        gap = pow(4, k) + 3 * pow(2, k-1) + 1;
        sedgewick.push_back(gap);
        k++;
    }

    int last_gap;
    gap = 701;
    while (gap < N / 2) {
        last_gap = gap;
        gap = 2.25*last_gap;
        ciura.push_back(gap);
    }

    k = 18;
    gap = 743735;
    while (gap < N / 2) {
        gap = (pow(2.2436, k) - 1) / 1.2436;
        tokuda.push_back(gap);
        k++;
    }

    reverse(sedgewick.begin(), sedgewick.end());
    reverse(ciura.begin(), ciura.end());
    reverse(tokuda.begin(), tokuda.end());

    gaps.push_back(sedgewick);
    gaps.push_back(ciura);
    gaps.push_back(tokuda);

    return gaps;
}

void shellSort(vector<int>& vect, int N, vector<int> gaps) {
    auto start = std::chrono::high_resolution_clock::now();

    for (auto gap : gaps) {
        for (int i = gap; i < N; i++) {
            int temp = vect[i], j;
            for (j = i; j >= gap; j -= gap) {
                if (temp < vect[j - gap])
                    vect[j] = vect[j - gap];
                else
                    break;
            }
            vect[j] = temp;
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto timp = (double)std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()/1000000;
    if (timp < 600) {  // daca sortarea dureaza mai mult de 10 minute sar peste;
        if (test_sort(vect, N))
            fout << "Timp de executare pentru Shell Sort (in secunde): " << timp << endl;
    } else
        fout << "Sortarea dureaza prea mult!\n";
}

void countingSort(vector<int>& vect, int N, int Max) {
    fout << "--------------------------\n";
    fout << "Counting Sort:\n";
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> count(Max+1, 0);
    vector<int> aux(N); // vector auxiliar

    // vector pentru aparitii
    for (auto el : vect)
        count[el]++;

    // aflu pe ce pozitie in vectorul sortat apare numarul
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = N-1; i >= 0; i--) {
        aux[count[vect[i]]] = vect[i];
        count[vect[i]]--;
    }

    vect = aux;

    auto stop = std::chrono::high_resolution_clock::now();
    auto timp = (double)std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()/1000000;
    if (timp < 600) {  // daca sortarea dureaza mai mult de 10 minute sar peste;
        if (test_sort(vect, N))
            fout << "Timp de executare pentru Counting Sort (in secunde): " << timp << endl;
    } else
        fout << "Sortarea dureaza prea mult!\n";
    fout << "--------------------------\n";
}

void merge(vector<int>& vect, int st, int dr, int mij) {
    int i, j, p;

    vector<int> vectStanga(mij - st + 1);
    vector<int> vectDreapta(dr - mij);

    for (i = 0; i < mij - st + 1; i++)
        vectStanga.push_back(vect[st + i]);
    for (j = 0; j < dr - mij; j++)
        vectDreapta.push_back(vect[mij + 1 + j]);

    i = 0; j = 0; p = st;

    while (i < mij - st + 1 && j < dr - mij) {
        if (vectStanga[i] < vectDreapta[j]) {
            vect[p] = vectStanga[i];
            i++;
        } else {
            vect[p] = vectDreapta[j];
            j++;
        }
        p++;
    }

    while (i < mij - st + 1) {
        vect[p] = vectStanga[i];
        i++;
        p++;
    }

    while (j < dr - mij) {
        vect[p] = vectDreapta[j];
        j++;
        p++;
    }
}

void mergeSort(vector<int>& vect, int st, int dr) {
    if (st < dr) {
        int mij = (st + dr) / 2;
        mergeSort(vect, st, mij);
        mergeSort(vect, mij + 1, dr);
        merge(vect, st, dr, mij);
    }
}

void radixSort(vector<int>& vect, int N, int baza) {
    fout << "--------------------------\n";
    fout << "Radix Sort in baza " << baza << ":\n";
    auto start = std::chrono::high_resolution_clock::now();
    int maxi = vect[0];
    for (auto el: vect)
        if (maxi < el)
            maxi = el;

    for (int indexCifra = 1; maxi / indexCifra > 0; indexCifra *= baza) {
        vector<int> count(baza, 0);
        vector<int> aux(N);

        for (auto el : vect)
            count[(el / indexCifra) % baza]++;

        for (int i = 1; i < baza; i++)
            count[i] += count[i - 1];

        for (int i = N-1; i >= 0; i--) {
            aux[count[(vect[i] / indexCifra) % baza] - 1] = vect[i];
            count[(vect[i] / indexCifra) % baza]--;
        }
        vect = aux;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto timp = (double)std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()/1000000;
    if (timp < 600) {  // daca sortarea dureaza mai mult de 10 minute sar peste;
        if (test_sort(vect, N))
            fout << "Timp de executare pentru Radix Sort in baza " << baza << " (in secunde): " << timp << endl;
    } else
        fout << "Sortarea dureaza prea mult!\n";
//    afis(vect);
    fout << "--------------------------\n";
}

int main() {
    ifstream fin("teste.txt");
    vector<int> v, aux;
    int N = -1, Max = -1, nr_teste;
    fin >> nr_teste;
    for (int i = 1; i <= nr_teste; i++) {
        fin >> N >> Max;
        fout << "==================================================\n";
        fout << "TEST " << i << ": " << N << " numere cu Max " << Max << endl;
        generateNumbers(aux, N, Max);

        fout << "--------------------------\n";
        auto start2 = std::chrono::high_resolution_clock::now();
        fout << "Basic sort din C++:\n";
        v = aux;
        std::sort(v.begin(), v.end());
        auto stop2 = std::chrono::high_resolution_clock::now();
        auto timp2 = (double)std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2).count()/1000000;
        if (timp2 < 600) {  // daca sortarea dureaza mai mult de 10 minute sar peste;
            if (test_sort(v, N))
                fout << "Timp de executare pentru sort-ul basic din C++ Sort (in secunde): " << timp2 << endl;
        } else
            fout << "Sortarea dureaza prea mult!\n";
        fout << "--------------------------\n";

        if (N >= 1000000)  // 10^6
            fout << "Bubble Sort: sortarea ar dura mult prea mult timp: peste 20 de minute\n";
        else {
            v = aux;
            bubbleSort(v, N);
        }

        vector<vector<int>> gaps = generateShellSortGaps(N);
        fout << "--------------------------\n";
        fout << "Shell Sort utilizand Sedgewick gap sequence:\n";
        v = aux;
        shellSort(v, N, gaps[0]);
        fout << "--------------------------\n";
        fout << "--------------------------\n";
        fout << "Shell Sort utilizand Ciura gap sequence:\n";
        v = aux;
        shellSort(v, N, gaps[1]);
        fout << "--------------------------\n";
        fout << "--------------------------\n";
        fout << "Shell Sort utilizand Tokuda gap sequence:\n";
        v = aux;
        shellSort(v, N, gaps[2]);
        fout << "--------------------------\n";

        if (N >= 10000000)  // 10^7
            fout << "Nu se poate sorta cu Counting Sort: N e peste 10^7!\n";
        else {
            v = aux;
            countingSort(v, N, Max);
        }

        fout << "--------------------------\n";
        fout << "Merge Sort:\n";
        v = aux;
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(v, 0, v.size() - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto timp = (double)std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()/1000000;
        if (timp < 600) {  // daca sortarea dureaza mai mult de 10 minute sar peste;
            if (test_sort(v, N))
                fout << "Timp de executare pentru Merge Sort (in secunde): " << timp << endl;
        } else
            fout << "Sortarea dureaza prea mult!\n";
        fout << "--------------------------\n";
//
        v = aux;
        radixSort(v, N, 2);
        v = aux;
        radixSort(v, N, 4);
        v = aux;
        radixSort(v, N, 8);
        v = aux;
        radixSort(v, N, 10);
        v = aux;
        radixSort(v, N, 16);
        fout << "==================================================\n";
    }
    fout << "Done";
    fin.close();
    fout.close();
    cout << "Done";
    return 0;
}
