class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size() - 1;
        int first=-1;
        int last=-1;
        vector<int> ans;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                first = mid;
                h=mid-1;
            }else if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        l=0;
        h=nums.size() - 1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                last=mid;
                l=mid+1;
            }else if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};