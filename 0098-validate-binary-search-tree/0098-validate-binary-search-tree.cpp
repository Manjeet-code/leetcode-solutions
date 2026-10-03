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
    TreeNode* Prev = NULL;
    bool ans = true;
    void fun(TreeNode* root){
        if(root==NULL)
        return;

        fun(root->left);

        if(Prev==NULL){
            Prev=root;
        }
        else{
            if(root->val <= Prev->val)
            ans = false;
            Prev = root;
        }

        fun(root->right);
    }
    bool isValidBST(TreeNode* root) {
        fun(root);
        return ans;
    }
};