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
    unordered_map<int , int> memo;
    TreeNode* passfunc(vector<int>& preorder , int ps , int pe , vector<int>& inorder , int is ,int ie){
        if(ps >= pe || is >= ie) return nullptr;
        int rootval = preorder[ps];
        TreeNode* root = new TreeNode(rootval);

        int mid = memo[rootval];
        root -> left = passfunc(preorder , ps + 1 , ps + mid -is + 1 , inorder , is , mid );
        root -> right = passfunc(preorder , ps + mid - is + 1 , pe , inorder , mid + 1 , ie);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i< n ; i++){
            memo[inorder[i]] = i;
        }
        return passfunc(preorder , 0 , n , inorder , 0 , n);
    }   
};