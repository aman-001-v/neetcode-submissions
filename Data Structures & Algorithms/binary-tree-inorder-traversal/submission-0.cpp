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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> memo;
        vector<int> result;
        TreeNode* curr = root;
        while(!memo.empty() || curr != nullptr){
           while(curr != nullptr){
            memo.push(curr);
            curr = curr -> left;
           }
           curr = memo.top();
           memo.pop();
           result.push_back(curr -> val);
           curr = curr -> right;
        }
        return result;
    }
};