class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0 ; i < n ; i++){
            int tank = gas[i] - cost[i];
            int j = i + 1;
            
            while(tank > 0 && j % n != i){
                tank += gas[j % n] - cost[j % n];
                j++;
            }
            if(j % n == i && tank >= 0) return i;
        }
        return -1;
    }
};