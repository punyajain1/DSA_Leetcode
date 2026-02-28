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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* parent = nullptr;
        TreeNode* curr = root;
        while(curr && curr->val!=key){
            parent = curr;
            if(curr->val<key) curr = curr->right;
            else curr = curr->left;
        }
        if(!curr) return root;

        if(!curr->left && !curr->right){
            if(!parent) return nullptr;
            if(parent->left == curr) parent->left = nullptr;
            else parent->right = nullptr;
            delete curr;
        }

        else if(!curr->left || !curr->right){
            TreeNode* child = curr->left ? curr->left : curr->right;
            if(!parent) return child;
            if(parent->left == curr) parent->left = child;
            else parent->right = child;
            delete curr;
        }

        else{
            TreeNode* successor = curr->right;
            TreeNode* successorParent = curr;
            while(successor->left){
                successorParent = successor;
                successor = successor->left;
            }
            curr->val = successor->val;
            if(successorParent->left == successor) successorParent->left = successor->right;
            else successorParent->right = successor->right;
            delete successor;
        }
        return root;
    }
};