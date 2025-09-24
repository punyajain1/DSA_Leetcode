class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0,b=1,c=0;
        for (auto &num: nums) {
            a ^= num;
        }
        while (not(a & b)) {
            b <<= 1;
        }
        for (auto &num: nums){
		    if (num & b) c ^= num;
        }
	    return {c, a ^ c};
    }
};