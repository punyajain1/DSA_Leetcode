class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights[0].size();

        vector<pair<int, int>> adj[n];
        // pushing stops,node,dist of a node into queus
        for(auto it:flights){
            //adj[from]={to,price}
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> pq;
        pq.push({0,{src,0}});
        vector<int> dist(n, 1e9);

        while(!pq.empty()){
            auto temp=pq.front();
            pq.pop();
            int s=temp.first; // Number of stops till now 
            int curr=temp.second.first; //curr node
            int cost=temp.second.second; //cost to reach current
            if (s>k) continue;
            for (auto it: adj[curr]){
                int t=it.first; // new node can be reached from curr
                int nc = it.second; // cost to reach new node

                // If a shorter path to the adjacent node is found and the number of stops taken is less then k , update the distance
                if (cost+nc < dist[t] && s<=k){
                    dist[t] = cost + nc; 
                    //push back stop+1 , new node , new cost 
                    pq.push({s+1, {t,cost+nc}});  
                }
            }
        }
        if(dist[dst]==1e9) return -1;

        return dist[dst];
    }
};