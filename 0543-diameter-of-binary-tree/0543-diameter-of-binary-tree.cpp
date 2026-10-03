class Solution {
public:
    int res = 0;

    int height(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        // Diameter passing through current node
        int sum = left + right;

        res = max(res, sum);

        // Return height of current node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res;
    }
};