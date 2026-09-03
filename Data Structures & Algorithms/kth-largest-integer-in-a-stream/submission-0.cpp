class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> memo;
    int k = 0;
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for(const int& q: nums){
            memo.push(q);
        }
    }
    
    int add(int val) {
        memo.push(val);
        while(memo.size() > k){
            memo.pop();
        }
        return memo.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */