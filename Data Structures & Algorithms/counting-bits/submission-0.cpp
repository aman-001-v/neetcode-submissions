class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1 , 0);
        for(int i = 0 ; i < n + 1 ; i++){
            int t = i;
            int count = 0;
            while(t > 0){
                if(t & 1 == 1) count++;
                
                t = t >> 1;
            }
            res[i]= count;
        }
        return res;
    }
};