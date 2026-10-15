class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n = hand.size();
        if(n % g != 0) return false;
        
        priority_queue<int , vector<int> , greater<int>> que;
        unordered_map<int , int> memo;
        
        
        for(int i = 0 ; i < n ; i++){
            if(!memo.contains(hand[i])) que.push(hand[i]);
            memo[hand[i]]++; 
        }
        
        while(!que.empty()){
            int t = que.top();
         
            for(int i = 0 ; i < g ; i++){
                memo[t + i]--;
                if(memo[t + i] < 0) return false;
            }
            while(!que.empty() && memo[que.top()] == 0){
                que.pop();
            }
         
        }
        return true;
    }
};