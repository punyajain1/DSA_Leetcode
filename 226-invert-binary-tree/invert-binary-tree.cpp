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
    void solve(TreeNode* r1,TreeNode* r2){
        if(r1==NULL) return;
        if(r1->right) r2->left = new TreeNode(r1->right->val);
        if(r1->left) r2->right= new TreeNode(r1->left->val);
        solve(r1->right,r2->left);
        solve(r1->left,r2->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* r2= new TreeNode(root->val);
        solve(root,r2);
        return r2;
    }
};