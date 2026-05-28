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
    void dfs(TreeNode* root , int x){
        if(!root){ return; }
        x=max(x,root->val);
        if(root->val >= x){ cnt++;}
        dfs(root->left,x);
        dfs(root->right,x);
    }
    int goodNodes(TreeNode* root) {
        int x=root->val;
        dfs(root,x);
        return cnt;
    }
};