#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.length();
        int t2 = text2.length();
        vector<vector<int>> vect(t1+1, vector<int>(t2+1, 0));
        for (int i = 1; i <= t1; i++) {
            for (int j = 1; j <= t2; j++) {
                if (text1[i - 1] == text2[j-1]) {
                    vect[i][j] = vect[i - 1][j - 1] + 1;
                }
                else {
                    vect[i][j] = max(vect[i - 1][j], vect[i][j - 1]);
                }
            }
        }
        return vect[t1][t2];
    }
};