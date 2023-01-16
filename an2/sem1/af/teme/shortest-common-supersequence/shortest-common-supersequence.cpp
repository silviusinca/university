#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        string sol = "";

        // intializam si cream matricea pentru programarea dinamica in care crestem matrice[i][j] in momentul in care gasim egalitate intre 2 carectere din siruri, altfel luam maximul
        // matricea va avea nr de linii = lungimea primului sir si cel de coloane = cu lungimea celui de-al doilea
        vector<vector<int>> matrice(m+1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    matrice[i][j] = 1 + matrice[i - 1][j - 1];
                }
                else {
                    matrice[i][j] = max(matrice[i - 1][j], matrice[i][j - 1]);
                }
            }
        }

        // traversam matricea de la ultimul element
        // daca gasim acelasi caracter il adaugam la solutie, 
        // altfel, daca nu sunt egale, vom adauga la solutie maximul care dintre matrice[i-1][j] si matrice[i][j-1]  
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {

                sol.push_back(str1[i - 1]); 
                i--;
                j--;
            }

            else if (matrice[i][j - 1] > matrice[i - 1][j]) {
                sol.push_back(str2[j-1]);  
                j--;                       
            }

            else {
                sol.push_back(str1[i - 1]);
                i--;                       
            }
        }

        // daca vreun string cumva nu ramane gol, il traversam si adaugam caracterul la solutie
        while (i > 0) {
            sol.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            sol.push_back(str2[j - 1]);
            j--;
        }
        // facem reverse
        reverse(sol.begin(),sol.end());

        return sol;
    }
};

