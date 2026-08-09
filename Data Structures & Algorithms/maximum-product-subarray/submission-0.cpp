class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int currmax = 1;
        int currmin = 1;

        for(int& q: nums){
            if(q == 0){
                currmax = 1;
                currmin = 1;
                result = max(q , result);
                continue;
            }
            int temp = currmax * q;

            currmax = max(q , max(currmax * q , currmin * q));
            currmin = min(q , min(temp , currmin * q));

            result = max(result , currmax);
        }
        return result;
    }
};
