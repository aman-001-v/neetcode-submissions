class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(int q: nums){
            n = n ^ q;
        }
        return n;
    }
};