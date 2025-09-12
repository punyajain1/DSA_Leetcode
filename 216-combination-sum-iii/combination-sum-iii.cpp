class Solution {
public:
    void sum (vector<vector<int>> &v, int k,int i, int n , vector<int> &ans){
        if (k==0 && n==0){
            v.push_back(ans);
            return;
        }
        if (k==0 || n<=0) return;
        for(int j=i;j<=9;j++){
            //for 1-> recursion 2,3,4,5,6,7,8,9
            //for 2-> recursion 3,4,5,6,7,8,9
            
            ans.push_back(j);
            sum(v,k-1,j+1,n-j,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int> ans;
        sum(v,k,1,n,ans);
        return v;
    }
};