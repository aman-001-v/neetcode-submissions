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
    int diameter = 0;
    int passfunc(TreeNode* r){
        if(r == nullptr) return 0;
        int lt = passfunc(r -> left);
        int rt = passfunc(r-> right);
        diameter = max(diameter, lt + rt);
        return max(lt , rt) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        passfunc(root);
        return diameter;

    }
};