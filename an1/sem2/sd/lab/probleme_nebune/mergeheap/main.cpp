#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream fin("mergeheap.in");
ofstream fout("mergeheap.out");


/*
 * pentru problema voi realiza un heap simplu cu functii pentru:
     * inserare
     * extract de maxim (si minim)
     * heapify
 *
 * */

class MinHeap {
private:
    vector<long long> heap;
public:

    MinHeap(){}

    vector<long long> getHeap() {
        return heap;
    }

    void urca(long long index) {
        while (index != 0) {
            long long tata = (index-1) / 2;
            if (!heap.empty() && heap[tata] < heap[index]) {
                long long aux;
                aux = heap[tata];
                heap[tata] = heap[index];
                heap[index] = aux;
            } else {
                index = 0;
            }
        }
    }

    void coboara(long index) {
        int ok = 1;
        while (ok) {
            if (heap.size() > index * 2 + 1) { // verif daca pozitia este corecta sau nu
                long long stanga = heap[index * 2 + 1];
                if (index * 2 + 2 == heap.size() || heap[index * 2 + 2] < stanga) {
                    if (heap[index] < stanga) {
                        long long aux = heap[index];
                        heap[index] = heap[index * 2 + 1];
                        heap[index * 2 + 1] = aux;
                        coboara(index * 2 + 1);
                    }
                    ok = 0;
                } else {
                    if (heap[index] < heap[index * 2 + 2]) {
                        long long aux = heap[index];
                        heap[index] = heap[index * 2 + 2];
                        heap[index * 2 + 2] = aux;
                        coboara(index * 2 + 2);
                    }
                    ok = 0;
                }
            }
            ok = 0;
        }
    }

    void adauga(long long el) {
        heap.push_back(el);
        urca(heap.size() - 1);
    }

    void scoate(){
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        coboara(0);
//        heap.pop_back();
    }

    void heapify(long long index, long long size) {
        if (index <= size) {
            long long tata = index;
            if (index * 2 + 1 < size && heap[index * 2 + 1] > heap[tata])
                tata = index * 2 + 1;
            if (index * 2 + 2 < size && heap[index * 2 + 2] > heap[tata])
                tata = index * 2 + 2;
            if (tata != index) {
                long long aux = heap[index];
                heap[index] = heap[tata];
                heap[tata] = aux;
                heapify(tata, size);
            }
        }
    }

    void build(long long size) {
        long long i = size/2-1;
        while(i >= 0) {
            heapify(i, size);
            i--;
        }
    }

    void clearHeap() {
        heap.clear();
    }

    void mergeheap(MinHeap other) {
        for (long long i = 0; i < other.getHeap().size(); i++)
            heap.push_back(other.getHeap()[i]);
        build(heap.size());
//        other.clearHeap();
    }

};

int main() {

    long long n, q;
    fin >> n >> q;

    vector<MinHeap> heaps(n+1);

    long long m, op, x;
    for (int i = 1; i <= q; i++) {
        fin >> op;
        if (op == 1) {
            fin >> m >> x;
            heaps[m].adauga(x);
        }
        else if (op == 2) {
            fin >> m;
            fout << heaps[m].getHeap()[0] << '\n';
            cout << heaps[m].getHeap()[0] << '\n';
            heaps[m].scoate();
        }
        else if (op == 3) {
            fin >> m >> x; // m index prima multime, x index a doua multime
            heaps[m].mergeheap(heaps[x]);
            heaps[x].clearHeap();
        }
    }

    return 0;
}
