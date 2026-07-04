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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> memo;
        vector<vector<int>> result;
        if(root == nullptr) return result;
        memo.push(root);
        int n = 0;
        while(!memo.empty()){
            int s = memo.size();
            result.resize(n+1);
            for(int i = 0; i< s; i++){
                TreeNode* temp = memo.front();
                memo.pop();
                if(temp -> left != nullptr) memo.push(temp -> left);
                if(temp -> right != nullptr) memo.push(temp -> right);
                result[n].push_back(temp -> val);
            }
            n++;
        }
        return result;
    }
};