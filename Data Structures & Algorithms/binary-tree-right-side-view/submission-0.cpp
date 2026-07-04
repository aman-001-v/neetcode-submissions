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
        queue<TreeNode*> memo;
        vector<int> result;
        if(root == nullptr) return result;
        bool flag = false;
        memo.push(root);
        while(!memo.empty()){
            int n = memo.size();
            for(int i = 0; i < n; i++){
                TreeNode* temp = memo.front();
                if(flag == false){
                    result.push_back(temp -> val);
                    flag = true;
                }
                memo.pop();
                if(temp -> right != nullptr) memo.push(temp -> right);
                if(temp -> left != nullptr) memo.push(temp -> left);
            }
            flag = false;
        }
        return result;
    }
};