class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> memo;
        if(a > 0) memo.push({a , 'a'});
        if(b > 0) memo.push({b , 'b'});
        if(c > 0) memo.push({c , 'c'});

        string res = "";
        while(!memo.empty()){
            pair<int , char> t1 = memo.top();
            memo.pop();
            if(t1.first > 1){
                res += t1.second;
                res += t1.second;
                t1.first -= 2;
            }
            else{
                res += t1.second;
                t1.first--;
            }
            if(t1.first == 0) continue;
            if(memo.empty()){
                return res;
            }
            pair<int , char> t2 = memo.top();
            memo.pop();

            int n = t2.first;
            if(!memo.empty()) n += memo.top().first;
            if(t2.first > 1 && (t1.first/2) + 1 < n){
                res += t2.second;
                res += t2.second;
                t2.first -= 2;
            }
            else{
                res += t2.second;
                t2.first--;
            }
            memo.push(t1);
            if(t2.first > 0) memo.push(t2);
        }
        return res;
    }
};