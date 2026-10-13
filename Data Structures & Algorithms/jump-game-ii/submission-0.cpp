class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int , int>> memo;
        int res = 0;
        memo.push({nums[0] , 0});
        while(memo.top().second < n - 1){
            int i = memo.top().second;
            memo.pop();
            for(int j = nums[i] ; j > 0 ; j--){
                if(i + j < n - 1){
                    memo.push({i + j + nums[i + j] , i + j});
                }
                else return res + 1;
            }
            res++;
            if(memo.size() == 0) return 0;

        }
        return res;
    }
};