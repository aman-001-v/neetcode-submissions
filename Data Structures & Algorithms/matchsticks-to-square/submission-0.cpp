#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.empty()) return false;
        
        long long total = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        if (total % 4 != 0) return false;
        
        int target = total / 4;
        sort(matchsticks.rbegin(), matchsticks.rend()); // descending
        
        if (matchsticks[0] > target) return false;
        
        vector<int> sides(4, 0);
        return dfs(0, matchsticks, sides, target);
    }
    
private:
    bool dfs(int idx, const vector<int>& sticks, vector<int>& sides, int target) {
        if (idx == sticks.size()) {
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;
        }
        
        for (int i = 0; i < 4; ++i) {
            // Skip duplicate empty sides (pruning)
            if (i > 0 && sides[i] == sides[i - 1]) continue;
            
            if (sides[i] + sticks[idx] <= target) {
                sides[i] += sticks[idx];
                if (dfs(idx + 1, sticks, sides, target)) return true;
                sides[i] -= sticks[idx];
            }
        }
        return false;
    }
};