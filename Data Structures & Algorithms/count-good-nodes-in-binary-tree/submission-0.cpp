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
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int max){
        if(!node) return 0;

        int res;
        if(node->val >= max){
            res = 1;
            max = node->val;
        } else {
            res = 0;
        }
        res += dfs(node->left, max);
        res += dfs(node->right, max);

        return res;

    }
    
};
