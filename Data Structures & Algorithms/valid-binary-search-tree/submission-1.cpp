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
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return inOrder(root, prev);
    }

    bool inOrder(TreeNode* node, long long& prev){
        if(!node) return true;
        if(!inOrder(node->left, prev)) return false;
        if(node->val <= prev) return false;
        prev = node->val;
        return inOrder(node->right, prev);
    }
};
