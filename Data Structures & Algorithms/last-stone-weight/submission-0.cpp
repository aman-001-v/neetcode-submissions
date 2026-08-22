class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin() , stones.end());

        while(stones.size() > 1){
            int a = stones[stones.size() - 1];
            int b = stones[stones.size() - 2];
            stones.pop_back();
            stones.pop_back();
            int i = 0;
            if(a - b != 0){
                while(i < stones.size()){
                    if(stones[i] >= a - b) break;
                    i++;
                }

                stones.insert(stones.begin() + i , a - b);
            }
        }
        if(stones.size() != 0) return stones[0];
        else return 0;
    }
};