class Disjoint{
    vector<int>parent, rank;
    public:
    Disjoint(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 0; i <= n; i++)parent[i] = i;
    }
    
    int find(int node) {
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells, int ret = 0) {
        int n = row * col;
        Disjoint ds(n+1);
        for(int i = 0; i < row; i++)
            ds.unionByRank(i * col + 0 + 1, 0), ds.unionByRank(i * col + col, n+1);
        vector<vector<bool>> vis(row, vector<bool>(col, false));  

        for(auto &it : cells) {
            int i = it[0] - 1, j = it[1] - 1;
            int cell = i * col + j + 1;
            vis[i][j] = true;

            for(int x = -1; x <= 1; x++) {
                for(int y = -1; y <= 1; y++) {

                    int ni = i + x, nj = j + y;
                    if(min(ni, nj) >= 0 && ni < row && nj < col && vis[ni][nj]) {
                        int ncell = ni * col + nj + 1;
                        ds.unionByRank(cell, ncell);
                    }

                }
            }
            
            if(ds.find(0) == ds.find(n+1)) return ret;
            ret++;
        }

        return ret;
    }
};