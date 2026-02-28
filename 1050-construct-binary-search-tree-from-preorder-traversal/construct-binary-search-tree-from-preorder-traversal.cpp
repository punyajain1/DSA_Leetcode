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
    TreeNode* solve(vector<int>& preorder, int& i, int min, int max){
        if(i>=preorder.size()) return NULL;
        if(preorder[i] < min || preorder[i] > max) return nullptr;

        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = solve(preorder, i, min, root->val);
        root->right = solve(preorder, i, root->val, max);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        int i=0;
        return solve(preorder,i,INT_MIN,INT_MAX);
    }
};