class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int j=height.size()-1;
        int i=0;
        while(i<j){
            int a=(j-i)*min(height[i],height[j]);
            maxi=max(maxi,a);
            height[i]<height[j]? i++:j--;
        }
        return maxi;
    }
};