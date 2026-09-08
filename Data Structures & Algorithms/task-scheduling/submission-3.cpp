class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> memo(26 , 0);
        for(char& q: tasks){
            memo[q - 'A']++;
        }
        int maxfreq = 0;
        int maxcount = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(memo[i] > maxfreq){
                maxfreq = memo[i];
                maxcount = 1;
            }
            else if(memo[i] == maxfreq){
                maxcount++;
            }
        }
        int t = ((maxfreq - 1) * (n + 1)) + maxcount;
        return max((int)tasks.size() , t);
    }
};