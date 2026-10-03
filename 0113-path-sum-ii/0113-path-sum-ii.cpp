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
    vector<vector<int>> res;

    void fun(TreeNode* root, int sum, vector<int>& diary, int targetSum) {
        if(root == NULL)
            return;

        sum = sum + root->val;
        diary.push_back(root->val);

        // Leaf node
        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) {
                res.push_back(diary);
            }

            diary.pop_back();
            return;
        }

        // Explore left and right
        fun(root->left, sum, diary, targetSum);
        fun(root->right, sum, diary, targetSum);

        // Backtracking
        diary.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> diary;
        int sum = 0;

        fun(root, sum, diary, targetSum);

        return res;
    }
};