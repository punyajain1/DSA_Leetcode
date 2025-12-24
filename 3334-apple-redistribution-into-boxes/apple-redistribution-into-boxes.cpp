class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        sort(capacity.begin(), capacity.end(), greater<int>());
        int t_w=0;
        for(int i=0;i<n;i++){
            t_w+=apple[i];
        }
        int c=0;
        for(auto it:capacity){
            if(t_w<=0) break;
            t_w-=it;
            c++;
        }
        return c;
    }
};