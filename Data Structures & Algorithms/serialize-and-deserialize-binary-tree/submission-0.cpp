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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream ss(data);
        return deserializeHelper(ss);
    }

    void serializeHelper(TreeNode* root, string& s){
        if(!root){
            s+="#,";
            return;
        }

        s+=to_string(root->val)+",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    TreeNode* deserializeHelper(stringstream& ss){
        string token;
        getline(ss, token, ',');

        if(token=="#") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));

        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);

        return node;
    }

};
