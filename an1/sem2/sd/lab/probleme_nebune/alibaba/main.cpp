#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

std::ifstream fin("alibaba.in");
std::ofstream fout("alibaba.out");

int main() {

    int n, k, c = 0, i;
    std::string nr;
    std::stack<char> stiva;
    fin >> n >> k;
    fin.get();
    fin >> nr;

    for (i = 0; i < n; i++) {
        while (!stiva.empty() && nr[i] > stiva.top() && c < k) {
            stiva.pop();
            c++;
        }
        stiva.push(nr[i]);
    }

    std::vector<char> rez;

    while (stiva.size() > n-k)
        stiva.pop();

    while(!stiva.empty()) {
        rez.push_back(stiva.top());
        stiva.pop();
    }

    std::reverse(rez.begin(), rez.end());

    for (auto ch : rez)
        fout << ch;

    fin.close();
    fout.close();

    return 0;
}
