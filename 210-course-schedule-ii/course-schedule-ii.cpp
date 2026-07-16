class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses);
        //using khans algo
        for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                ind[it]++;
            }
        }
        vector<int> ans;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto it:adj[t]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};