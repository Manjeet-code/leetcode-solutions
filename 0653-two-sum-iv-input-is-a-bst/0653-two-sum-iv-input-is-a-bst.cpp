class Solution {
public:
    vector<int> temp;

    void fun(TreeNode* root) {
        if (root == NULL)
            return;

        fun(root->left);
        temp.push_back(root->val);
        fun(root->right);
    }

    bool findTarget(TreeNode* root, int k) {

        // Inorder traversal gives sorted array
        fun(root);

        int i = 0;
        int j = temp.size() - 1;

        while (i < j) {

            int sum = temp[i] + temp[j];

            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                i++;
            }
            else {
                j--;
            }
        }

        return false;
    }
};