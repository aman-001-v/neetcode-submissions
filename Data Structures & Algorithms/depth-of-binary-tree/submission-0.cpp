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
    int maxDep = 0;
    void passfunc(TreeNode* r , int n){
        if(r == nullptr){
            maxDep = max(maxDep , n);
            return;
        }
        passfunc(r -> left , n+1);
        passfunc(r -> right, n +1);
        return;
    }
    int maxDepth(TreeNode* root) {
        passfunc(root,0);
        return maxDep;
    }
};