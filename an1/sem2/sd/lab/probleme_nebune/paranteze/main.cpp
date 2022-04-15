#include <fstream>
#include <iostream>
#include <stack>

std::ifstream fin("paranteze.in");
std::ofstream fout("paranteze.out");

int main() {
    int N;
    std::string sir;
    std::stack<std::pair<char, int>> stiva;
    fin >> N >> sir;

    int opmax = 0;

    stiva.push(std::make_pair('0', 0));

    int poz = 1;
    for (auto ch : sir) {
        if (!stiva.empty() && ((stiva.top().first == '{' && ch == '}') || (stiva.top().first == '[' && ch == ']') || (stiva.top().first == '(' && ch == ')'))) {
            stiva.pop();
            opmax = std::max(opmax, poz - stiva.top().second);
        } else stiva.push(std::make_pair(ch, poz));
        poz++;
    }

    std::cout<<opmax;
    fout << opmax;

    fin.close();
    fout.close();
    return 0;
}
