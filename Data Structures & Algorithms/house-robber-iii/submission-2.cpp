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
    pair<int,int> passfunc(TreeNode* root){
        if(root == nullptr) return {0,0};
        pair<int,int> left = passfunc(root -> left);
        pair<int,int> right = passfunc(root -> right);

        return {root-> val +left.second + right.second , max(left.second , left.first) + max(right.first , right.second)};

    }
    int rob(TreeNode* root) {
        pair<int, int> result = passfunc(root);
        return max(result.first , result.second);
    }
};