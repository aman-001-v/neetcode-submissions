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
    int maximum = -1001;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        maximum = max(maximum , max(root -> val + left + right , max( root -> val + left , max(root -> val + right , root -> val))));
        return max(root -> val + max(left , right), root -> val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maximum;
    }
};