class Solution {
public:
    struct nodes{
        vector<int> val;
        nodes* left = nullptr;
        nodes* right = nullptr;

        nodes(){

        }
        nodes(vector<int> val){
            this -> val = val;
        }
    };
    vector<vector<int>> subsets;
    void dfs(nodes* root , vector<int>& nums , int pos){
        if(pos == nums.size()) return;
        vector<int> temp = root -> val;
        temp.push_back(nums[pos]);
        root -> left = new nodes(temp);
        root -> right = new nodes(root -> val);
        dfs(root -> left , nums , pos + 1);
        dfs(root -> right , nums , pos + 1);
    }
    void createsubsets(nodes* root){
        if(!root -> left && !root -> right){
            subsets.push_back(root -> val);
            return;
        }
        createsubsets(root -> left);
        createsubsets(root -> right);
    }
    int subsetXORSum(vector<int>& nums) {
        nodes* root = new nodes;
        dfs(root , nums , 0);
        int result = 0;
        createsubsets(root);
        for(const auto& q: subsets){
            int t = 0;
            for(int i : q){
                t = t ^ i;
            }
        result += t;
        }
        return result;
    }
};