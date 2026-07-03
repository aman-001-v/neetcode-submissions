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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root -> val == key){
            if(root -> right == nullptr && root -> left == nullptr) return nullptr;
            else if(root -> right == nullptr){
                return root -> left;
            }
            else if(root -> left == nullptr){
                return root -> right;
            }
            else{
                TreeNode* t1 = root -> right -> left;
                TreeNode* t2 = root;
                root -> right -> left = root;
                root = root -> right;
                root -> left = t2;
                t2 -> right = t1;
                root -> left = deleteNode(root -> left , key);
            }
        }
        else if(root -> val > key){
            root -> left = deleteNode(root -> left , key);
        }
        else root -> right = deleteNode(root -> right , key);

        return root;
    }
};