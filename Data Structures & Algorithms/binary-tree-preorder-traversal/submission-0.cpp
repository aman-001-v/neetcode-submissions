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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> memo;
        vector<int> result;
        TreeNode* curr = root;
        while(!memo.empty() || curr != nullptr){
            while(curr != nullptr){
                result.push_back(curr -> val);
                memo.push(curr);
                curr = curr -> left;
            }
            curr = memo.top() -> right;
            memo.pop();
        }
        return result;
    }
};