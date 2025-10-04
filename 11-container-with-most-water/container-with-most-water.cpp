class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int j=height.size()-1;
        int i=0;
        while(i<j){
            maxi=max(maxi,((j-i)* min(height[i],height[j])));
            height[i] < height[j] ? i++ : j-- ;
        }
        return maxi;
    }
};