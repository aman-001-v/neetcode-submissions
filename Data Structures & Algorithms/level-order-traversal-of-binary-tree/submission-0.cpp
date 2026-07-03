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
    vector<vector<int>> memo;
    void passfunc(TreeNode* r , int n){
        if(r == nullptr) return;
        cout << r -> val << " , " ;
        if(memo.size() < n+1){
            memo.resize(n+1);
        }
        (memo[n]).push_back(r -> val);
        passfunc(r -> left , n + 1);
        passfunc(r -> right , n + 1);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        passfunc(root , 0);
        return memo;
    }
};