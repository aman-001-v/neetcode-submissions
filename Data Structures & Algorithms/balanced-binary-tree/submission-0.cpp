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
    bool flag = true;
    int passfunc(TreeNode* r){
        if(r == nullptr) return 0;
        int ld = passfunc(r -> left);
        int rd = passfunc(r -> right);
        if(abs(ld - rd)> 1) flag = false;
        return max(ld, rd) + 1;
    }
    bool isBalanced(TreeNode* root) {
        passfunc(root);
        return flag;
    }
};