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
    int good_count = 0;
    void passfunc(TreeNode* root , int greatest){
        if(root == nullptr) return;
        if(root -> val >= greatest) good_count++;
        passfunc(root -> left , max(greatest , root -> val));
        passfunc(root -> right , max(greatest ,root -> val));
        return;
    }
    int goodNodes(TreeNode* root) {
        passfunc(root , root -> val);
        return good_count;
    }
};