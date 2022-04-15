#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string input;

    vector<char> camere(10, '0');

    cin >> n >> input;

    for (int i = 0; i < n; i++) {
        if (input[i] == 'L') {
            int j = 0;
            while (camere[j] == '1')
                j++;
            camere[j] = '1';
        }
        else if (input[i] == 'R') {
            int j = 9;
            while (camere[j] == '1')
                j--;
            camere[j] = '1';
        }
        else {
            camere[input[i] - '0'] = '0';
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << camere[i];
    }


    return 0;
}
