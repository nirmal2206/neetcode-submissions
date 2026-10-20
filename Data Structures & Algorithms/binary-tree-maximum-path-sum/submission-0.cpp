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
    int ans = INT_MIN;
    int dfs(TreeNode* node){
        if(!node) return 0;

        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // best path that peaks at this node or best path where curr node is the fork
        ans = max(ans, node->val + left +right);

        // best single branch(left or right) to return to the parent node
        return node->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
