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
    vector<TreeNode*> s;
    vector<TreeNode*> l;
    bool isValidBST(TreeNode* root) {

        for(auto const q:s){
            if(q-> val >= root -> val) return false;
        }
        for(auto const q:l){
            if(q -> val <= root -> val) return false;
        }
        bool left = true, right = true;
        if(root -> left != nullptr){
            l.push_back(root);
            left = isValidBST(root -> left);
            l.pop_back();
        }
        if(root -> right != nullptr){
            s.push_back(root);
            right = isValidBST(root -> right);
            s.pop_back();
        }
        return(left && right);
    }
};