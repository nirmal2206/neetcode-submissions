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
    unordered_map<int, int> mp;
    int preIdx = 0;
    TreeNode* constructBTree(vector<int>& preorder, int left, int right){
        if(left > right) return nullptr;

        int rootVal = preorder[preIdx++];
        int mid = mp[rootVal];
        TreeNode* root = new TreeNode(rootVal);

        root->left = constructBTree(preorder, left, mid-1);
        root->right = constructBTree(preorder, mid+1, right);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size();++i){
            mp[inorder[i]] = i;
        }
        return constructBTree(preorder, 0, inorder.size()-1);
    }
};
