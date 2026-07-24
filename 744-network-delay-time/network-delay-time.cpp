class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto it:times){
            //adj[ui]={vi,wi}
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        //push time , node
        pq.push({0, k});
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int cost=temp.first; //time till now 
            int curr=temp.second; //curr node
            if (cost > dist[curr]) continue;
            
            for(auto it:adj[curr]){
                int t=it.first; // new node can be reached from curr
                int wi=it.second; // weight to reach new node
                if (cost+wi < dist[t]){
                    dist[t] = cost + wi;
                    pq.push({dist[t], t});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            ans=max(dist[i],ans);
        }
        return ans;
    }
};