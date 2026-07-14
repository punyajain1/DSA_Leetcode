class Solution {
public:
    int dfs(int i,vector<int>&v, vector<int>&p , vector<vector<int>>&adj ,vector<int>&ans){
        if(p[i]==1) return 0;
        if(v[i]==1) return 1;
        p[i]=1;
        v[i]=1;

        for(auto it:adj[i]){
            if(dfs(it,v,p,adj,ans)==0) return 0;
        }
        p[i]=0;
        ans.push_back(i);
        return 1;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>v(numCourses,0);
        vector<int>p(numCourses,0);
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(v[i]==0){
                if(!dfs(i,v,p,adj,ans)) return {};
            }
        }
        return ans;
    }
};