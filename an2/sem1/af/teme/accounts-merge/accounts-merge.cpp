#include <vector>
#include <string>
#include <set>

using namespace std;

// unim conturile care au mail-uri identice si cream componente conexe pentru fiecare user, nodurile fiind mail-uri

class Solution {
public:
    // verific daca avem 2 conturi cu cel putin un mail asemanator
    int compare(vector<string> &firstAccout, vector<string> &secondAccount) {
        // daca au nume diferite automat fals
        if (firstAccout[0] != secondAccount[0]) {
            return 0;
        }
        for (auto account : secondAccount) {
            // sarim peste secondAccount[0] care este numele persoanei
            if (account == secondAccount[0])
                continue;
            for (auto mail : firstAccout) {
                if (mail == account) {
                    return 1;
                }
            }
        }
        return 0;
    }
    
	// DFS
    void dfs(vector<int> adj_list[], int node, vector<int> &connected, int* sel) {
        sel[node] = 1;
        connected.push_back(node);
        for (auto &neighbour : adj_list[node]) {
            if (!sel[neighbour]) {
                dfs(adj_list, neighbour, connected, sel);
            }
        }
    }
    
    void merge(vector<int> &connected, vector<vector<string>> &res, vector<vector<string>> &accounts) {
        vector<string> aux(1);
        aux[0] = accounts[connected[0]][0]; // numele
		
        // folosim set pentru a avea mail-uri unice
        set<string> set;
        for (auto &node : connected) {
            for (int i = 1; i < accounts[node].size(); i++) {
                set.insert(accounts[node][i]);
            }
        }
        
        for (auto &elem : set) { 
            aux.push_back(elem);
        }
        res.push_back(aux);
    }
	
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> adj_list[accounts.size()];
        
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = i+1; j < accounts.size(); j++) {
                // verificam daca apartin aceluiasi user
                int check = compare(accounts[i], accounts[j]);
				// si daca apartin ii facem lista de adiacenta
                if (check) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        
        vector<vector<string>> res;
        int sel[accounts.size()];
        memset(sel, 0, sizeof(sel));
		
        // folosind dfs aflam componentele conexe
        for (int i = 0; i < accounts.size(); i++) {
            vector<int> con; // stocam indicii componentelor pe care le unim
            if (!sel[i]) {
                dfs(adj_list, i, con, sel);
                merge(con, res, accounts);
            }
        }
        
        return res;
    }
};