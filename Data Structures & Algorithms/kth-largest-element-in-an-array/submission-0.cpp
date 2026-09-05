class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> memo;

        for(int i = 0 ; i < nums.size() ; i++){
            memo.push(nums[i]);
            if(memo.size() > k) memo.pop();
        }
        return memo.top();
    }
};