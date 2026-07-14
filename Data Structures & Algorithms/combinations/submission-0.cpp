class Solution {
public:
    void passfunc(int n , int k , vector<vector<int>>& result , vector<int>& curr , int num){
        if(curr.size() == k){
            result.push_back(curr);
            return;
        }
        for(int i = num; i <= n ; i++){
            curr.push_back(i);
            passfunc(n , k , result , curr , i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        passfunc(n , k , result , curr , 1);
        return result;
    }
};