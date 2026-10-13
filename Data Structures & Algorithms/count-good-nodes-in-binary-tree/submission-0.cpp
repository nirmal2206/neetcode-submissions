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
    int goodNodes(TreeNode* root) {
        return goodNodesDfs(root, INT_MIN);
    }

    int goodNodesDfs(TreeNode* node, int maxSoFar){
        if(!node) return 0;

        int count = (node->val >= maxSoFar) ? 1:0;
        maxSoFar = max(maxSoFar, node->val);

        return count + goodNodesDfs(node->left, maxSoFar) + goodNodesDfs(node->right, maxSoFar);
    }
};
