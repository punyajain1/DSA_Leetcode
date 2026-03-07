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
    int cnt=0;
    void solve(TreeNode* root,long long m){
        if(!root) return;
        m-=root->val;
        if(m==0){
            cnt++;
        }
        solve(root->left, m);
        solve(root->right, m);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        solve(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return cnt;
    }
};