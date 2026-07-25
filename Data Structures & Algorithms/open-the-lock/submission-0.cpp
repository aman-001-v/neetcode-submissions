class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string s = "0000";
        if(target == s) return 0;
        unordered_set<string> dead_end;
        unordered_set<string> visited;
        for(string q: deadends){
            dead_end.insert(q);
        }
        if(dead_end.contains(s)) return -1;
        queue<string> memo;
        memo.push(s);
        visited.insert(s);
        int count = 0;
        int n = 1;
        while(!memo.empty()){
            n = memo.size();
            for(int i = 0 ; i < n ; i++){
                s = memo.front();
                if(s == target) return count;
                
                for(int j = 0 ; j < 4 ; j++){
                    string t = s;
                    if(t[j] == '9') t[j] = '0';
                    else t[j] += 1;
                    if(!visited.contains(t) && !dead_end.contains(t)){
                        memo.push(t);
                        visited.insert(t);
                    } 
    
                }
                for(int j = 0 ; j < 4 ; j++){
                    string t = s;
                    if(t[j] == '0') t[j] = '9';
                    else t[j] -= 1;
                    if(!visited.contains(t) && !dead_end.contains(t)){
                        memo.push(t);
                        visited.insert(t);
                    } 
                }
                memo.pop();
            }
            count++;
            
        }
        return -1;
    }
};