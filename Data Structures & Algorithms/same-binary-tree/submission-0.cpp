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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr){
            if(q == nullptr) return true;
            else return false;
        }
        if(q == nullptr){
            if(p == nullptr) return true;
            else return false;
        }
        if(p -> val != q -> val) return false;
        int f1 = isSameTree(p -> left , q -> left);
        int f2 = isSameTree(p -> right , q -> right);
        if(f1 == true && f2 == true) return true;
        else return false;
    }
};