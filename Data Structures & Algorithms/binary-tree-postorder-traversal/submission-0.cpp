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
    vector<int> postorderTraversal(TreeNode* root) {
        stack <TreeNode*> memo;
        vector<int> result;
        TreeNode* curr = root;
        while(!memo.empty() || curr != nullptr){
            if(curr != nullptr){
                memo.push(curr);
                curr = curr -> left;
            }
            else{
                TreeNode* temp = memo.top() -> right;
                if(temp == nullptr){
                    temp = memo.top();
                    memo.pop();
                    result.push_back(temp -> val);
                    while(!memo.empty() && temp == memo.top() -> right){
                        temp = memo.top();
                        memo.pop();
                        result.push_back(temp -> val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return result;
    }
};