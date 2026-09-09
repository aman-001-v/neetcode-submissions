class Solution {
public:
    string reorganizeString(string s) {
        vector<int> memo(26 , 0);
        for(int i = 0 ; i < s.length() ; i++){
            memo[s[i] - 'a']++;
        }
        priority_queue<pair<int , char>> que;
        for(int i = 0 ; i < 26 ; i++){
            if(memo[i] != 0){
                que.push({memo[i] , 'a' + i});
            }
        }
        string res = "";
        while(!que.empty()){
            pair<int , char> t1 = que.top();
            que.pop();
            res += t1.second;
            t1.first--;
            if(t1.first == 0) continue;
            if(que.empty()) return "";
            pair<int , char> t2 = que.top();
            que.pop();
            res += t2.second;
            t2.first--;
            que.push(t1);
            if(t2.first > 0) que.push(t2);
        }
        return res;
    }
};