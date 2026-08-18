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
        bool ans = true;
        calculateHeightDiff(root, ans);
        return ans;
    }
    int calculateHeightDiff(TreeNode* node, bool& ans){
        if(!node) return 0;
        int leftHeight = calculateHeightDiff(node->left, ans);
        if(ans == false) return 0;

        int rightHeight = calculateHeightDiff(node->right, ans);
        if(ans == false) return 0;

        if(abs(leftHeight - rightHeight) > 1) {
            ans = false;
            return 0;
        }

        return 1+max(leftHeight, rightHeight);
    }
};
