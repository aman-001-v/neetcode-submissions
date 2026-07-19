class Solution {
public:
    bool passfunc(vector<int>& nums , int pos , int k , int s , vector<int>& parts){
        if(pos == nums.size()){
            for(int q: parts){
                if(q != s) return false;
            }
            return true;
        }

        for(int i = 0 ; i < k ; i++){
            if(parts[i] + nums[pos] > s) continue;

            if(i > 0 && parts[i] == parts[i - 1]) continue;

            parts[i] += nums[pos];
            if(passfunc(nums , pos + 1 , k , s , parts)) return true;
            parts[i] -= nums[pos];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int q: nums) sum += q;

        if(sum % k != 0) return false;

        sort(nums.rbegin() , nums.rend());
        
        int s = sum / k;
        if(nums[0] > s) return false;

        vector<int> parts(k , 0);
        return passfunc(nums , 0 , k , s , parts);
    }
};