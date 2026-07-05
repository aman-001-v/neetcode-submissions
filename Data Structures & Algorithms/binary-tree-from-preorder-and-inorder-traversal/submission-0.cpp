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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 1) return new TreeNode(preorder[0]);
        else if (preorder.size() == 0) return nullptr;
        int root = preorder[0];
        vector<int> lpre , rpre , lin , rin;
        int i = 0;
        while(inorder[i] != preorder[0]){
            lin.push_back(inorder[i++]);
        }
        i++;
        while(i < inorder.size()){
            rin.push_back(inorder[i++]);
        }
        i = 1;
        while(lpre.size() != lin.size()){
            lpre.push_back(preorder[i++]);
        }
        while(rpre.size() != rin.size()){
            rpre.push_back(preorder[i++]);
        }
        TreeNode* left = buildTree(lpre , lin);
        TreeNode* right = buildTree(rpre , rin);
        return new TreeNode(preorder[0] , left , right);

    }
};