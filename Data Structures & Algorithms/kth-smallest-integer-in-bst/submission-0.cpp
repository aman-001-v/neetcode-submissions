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
    bool flag = false;
    int n = 0;
    int answer = 0;
    int kthSmallest(TreeNode* root, int k) {
        bool f2 = false;
        if(!flag){
            if(root -> left == nullptr && root -> right == nullptr) flag = true;
            else if(root -> left != nullptr){
                kthSmallest(root -> left , k);
                f2 = true;
            }
        }
        if(root -> left != nullptr && !f2){
            kthSmallest(root -> left , k);
        }
        n++;
        if(n == k){
            answer = root -> val;
        }else{
            if(root-> right != nullptr){
                kthSmallest(root -> right , k);
            }
        }
        return answer;
    }
};