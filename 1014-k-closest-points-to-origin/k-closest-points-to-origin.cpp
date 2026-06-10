class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;
        for (auto p:points){
            int d=(p[0]*p[0] + p[1]*p[1]);
            pq.push({d, p});

            if (pq.size()>k){
                pq.pop();
            }
        }
        int n=pq.size();
        while(n>0){
            ans.push_back(pq.top().second);
            pq.pop();
            n--;
        }
        return ans;
    }
};