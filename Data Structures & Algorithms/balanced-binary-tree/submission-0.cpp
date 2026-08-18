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
    bool isBalanced(TreeNode* root) {
        return calculateHeightDiff(root) != -1;
    }
    int calculateHeightDiff(TreeNode* node){
        if(!node) return 0;
        int leftHeight = calculateHeightDiff(node->left);
        if(leftHeight == -1) return -1;

        int rightHeight = calculateHeightDiff(node->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;

        return 1+max(leftHeight, rightHeight);
    }
};
