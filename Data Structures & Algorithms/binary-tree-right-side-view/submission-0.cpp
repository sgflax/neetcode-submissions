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
    vector<int> rightSideView(TreeNode* root) {
        //level order traversal
        vector<int> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* right = nullptr;
            int size = q.size();

            for(int i = 0; i < size; ++i){
                TreeNode* front = q.front();
                q.pop();
                if(front){
                    right = front;
                    q.push(front->left);
                    q.push(front->right);
                }
            }
            if(right){
                res.push_back(right->val);
            }
        }

        return res;

    }
};
