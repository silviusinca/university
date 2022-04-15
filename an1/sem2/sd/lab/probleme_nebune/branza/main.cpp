#include <iostream>
#include <fstream>
#include <deque>

std::ifstream fin("branza.in");
std::ofstream fout("branza.out");

int main() {
    long long N, S, T, cost, cantitate;
    std::deque<std::pair<long long, long long>> deq; // deque facut din pair de zi si cost;

    fin >> N >> S >> T; // n nr zile; s cost de depozitare; t timp cat de mult poate depozita;

    long long zi = 0, cost_minim = 0;
    while (fin >> cost >> cantitate) {
//        int costDepozitare = S * (zi - deq.back().first) + deq.back().second;
        while (!deq.empty() && (cost <= S * (zi - deq.back().first) + deq.back().second)) {
//            std::cout << deq.back().first << '\n';
            deq.pop_back();
        }

        deq.emplace_back(std::make_pair(zi,cost));

        if (deq.front().first < zi - T) {
            deq.pop_front();
        }
//        std::cout << deq.front().first << ' ' << deq.front().second << '\n';

//        for (auto el : deq)
//            std::cout << el.first << ' ' << el.second << '\n';
//        std::cout<< "===========\n";

        cost_minim += (S * (zi - deq.front().first) + deq.front().second) * cantitate;
        zi++;
    }

//    for (auto el : deq)
//        std::cout << el.first << ' ' << el.second << '\n';

    fout << cost_minim;
//    std::cout << cost_minim;

    return 0;
}
