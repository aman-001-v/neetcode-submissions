class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        int p2 = 1 , p1 = 2;
        for(int i = 3 ; i <= n ; i++){
            int current = p1 + p2;
            p2 = p1;
            p1 = current;
        }
        return p1;
    }
};