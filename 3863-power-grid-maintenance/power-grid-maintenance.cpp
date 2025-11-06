
class Solution {

    int findParent(int node, vector<int> &par) {
        if(par[node] == node) {
            return node;
        }
        return par[node] = findParent(par[node], par);
    }
    void unionByRank(int u, int v, vector<int> &par, vector<int> &rank) {
        if(u > v) {
            swap(u, v);
        }
        int up = findParent(u, par);
        int vp = findParent(v, par);
        if(up == vp) {
            return;
        }
        if(rank[up] < rank[vp]) {
            par[up] = vp;
        } 
        else if(rank[vp] < rank[up]) {
            par[vp] = up;
        } else {
            par[vp] = up;
            rank[up]++;
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> isActive(c + 1, true);
        vector<int> par(c + 1, 0);
        vector<int> rank(c + 1, 1);
        for(int i = 1; i <= c; i++) {
            par[i] = i;
        }
        for(auto it: connections) {
            unionByRank(it[0], it[1], par, rank);
        }
        unordered_map<int,set<int>> st;
        vector<int> ans;
        for(int i = 1; i <= c; i++) {
            int parent = findParent(i, par);
            st[parent].insert(i);
        }
        for(auto it: queries) {
            int mode = it[0];
            int node = it[1];
            int parent = findParent(node, par);
            if(mode == 2) {
                if(st[parent].find(node) != st[parent].end()) {
                    st[parent].erase(node);
                }
                isActive[node] = false;
                continue;
            }
            if(isActive[node]) {
                ans.push_back(node);
                continue;
            } 
            if(st[parent].size() != 0) {
                ans.push_back(*st[parent].begin());
                continue;
            }
            ans.push_back(-1);
        }
        return ans;
    }
};