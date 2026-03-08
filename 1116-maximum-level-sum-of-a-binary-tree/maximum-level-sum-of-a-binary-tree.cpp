/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void solve(TreeNode* root,int l){
        if(root==nullptr) return;
        if(v.size()<=l) v.push_back(0);
        v[l]+=root->val;
        solve(root->left,l+1);
        solve(root->right,l+1);
    }
    int maxLevelSum(TreeNode* root) {
        int maxi=INT_MIN;
        int ans=0;
        solve(root,0);
        for(int i=0;i<v.size();i++){
            if(maxi<v[i]){
                maxi=v[i];
                ans=i;
            }
        }
        return ans+1;
    }
};