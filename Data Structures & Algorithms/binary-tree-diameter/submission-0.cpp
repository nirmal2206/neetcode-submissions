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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        calculateHeight(root, maxDia);
        return maxDia;
    }

    int calculateHeight(TreeNode* node, int& maxDia){

        if(!node) return 0;

        int leftHeight = calculateHeight(node->left, maxDia);
        int rightHeight = calculateHeight(node->right, maxDia);

        maxDia = max(maxDia, leftHeight+rightHeight);

        return 1+max(leftHeight,rightHeight);
    }
};
