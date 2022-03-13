#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include <stdlib.h>
#include <math.h>

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

void bubbleSort(vector<int>& vect, int N) {
    auto start = std::chrono::high_resolution_clock::now();
    int i, j, aux;
    for (i = 0; i < N; i++)
        for (j = 0; j < i; j++)
            if (vect[i] < vect[j]) {
                aux = vect[i];
                vect[i] = vect[j];
                vect[j] = aux;
            }

    auto stop = std::chrono::high_resolution_clock::now();
    cout << "Timp de executare (in secunde): " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000000.00000000000000 << endl;

}

/**
# Sort an array a[0...n-1].
gaps = [701, 301, 132, 57, 23, 10, 4, 1]  // Ciura gap sequence

# Start with the largest gap and work down to a gap of 1
# similar to insertion sort but instead of 1, gap is being used in each step
foreach (gap in gaps)
{
    # Do a gapped insertion sort for every elements in gaps
    # Each gap sort includes (0..gap-1) offset interleaved sorting.
    for (offset = 0; offset < gap; offset++)
      for (i = offset; i < n; i += gap)
      {
          # save a[i] in temp and make a hole at position i
          temp = a[i]
          # shift earlier gap-sorted elements up until the correct location for a[i] is found
          for (j = i; j >= gap and a[j - gap] > temp; j -= gap)
          {
              a[j] = a[j - gap]
          }
          # put temp (the original a[i]) in its correct location
          a[j] = temp
       }
}


 4^k + 3 * 2^(k-1) + 1
*/

void shellSort(vector<int>& v, int N, int Max) {
    vector<int> gaps;
    int k = 1, gap = 1;
    gaps.push_back(gap);
    while (gap <= Max) {
        gap = pow(4, k) + 3 * pow(2, k-1) + 1;
        gaps.push_back(gap);
        k++;
    }

    int i;
    for (i = gaps.size()-1; i >= 0; i--) {

    }

}

int main() {
    vector<int> v;
    int N = 1000, Max = 100000;
    generateNumbers(v, N, Max);
    bubbleSort(v, N);
    cout << test_sort(v, N);

    return 0;
}
