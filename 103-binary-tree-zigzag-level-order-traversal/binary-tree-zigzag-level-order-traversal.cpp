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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (root == NULL) return v;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            vector<int> temp;
            while(!s1.empty()){
                TreeNode* t=s1.top();
                s1.pop();
                temp.push_back(t->val);
                if(t->left){
                    s2.push(t->left);
                }
                if(t->right){
                    s2.push(t->right);
                }
            }
            if(!temp.empty()) v.push_back(temp);
            temp.clear();
            while(!s2.empty()){
                TreeNode* t=s2.top();
                s2.pop();
                temp.push_back(t->val);
                if(t->right){
                    s1.push(t->right);
                }
                if(t->left){
                    s1.push(t->left);
                }
            }
            if(!temp.empty()) v.push_back(temp);
        }
        return v;
    }
};