#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> vect(m+1, vector<int>(n + 1, 0));

        string sol = "";

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    vect[i][j] = 1 + vect[i - 1][j - 1];
                }
                else {
                    vect[i][j] = max(vect[i - 1][j], vect[i][j - 1]);
                }
            }
        }

        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {

                sol.push_back(str1[i - 1]); 
                i--;
                j--;
            }

            else if (vect[i][j - 1] > vect[i - 1][j]) {
                sol.push_back(str2[j-1]);  
                j--;                       
            }

            else {
                sol.push_back(str1[i - 1]);
                i--;                       
            }
        }

        while (i > 0) {
            sol.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            sol.push_back(str2[j - 1]);
            j--;
        }
        reverse(sol.begin(),sol.end());

        return sol;
    }
};

