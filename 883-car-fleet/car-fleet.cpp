class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pair;
        for (int i = 0; i < n; i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        int fleets = 1;
        double prevTime = (double)(target - pair[0].first) / pair[0].second;
        // time = dis/speed
        //dis = (target - current pos)
        for (int i = 1; i < n; i++) {
            double currTime = (double)(target - pair[i].first) / pair[i].second;
            if (currTime > prevTime) {
                //if another cars time > previos car time then we will make new fellt
                //A car forms a new fleet only if it takes longer than the fleet in front of it.
                //If it takes the same time or less, it will eventually catch up and merge into that fleet.
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};