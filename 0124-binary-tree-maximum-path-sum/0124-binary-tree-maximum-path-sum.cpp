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
    int ans = INT_MIN;

    int helper(TreeNode* node) {
        if (node == NULL)
            return 0;

        int leftSum = max(0, helper(node->left));
        int rightSum = max(0, helper(node->right));

        // Update global answer
        ans = max(ans, leftSum + rightSum + node->val);

        // Return maximum path extending upwards
        return node->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};