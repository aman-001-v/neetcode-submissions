class Solution {
public:
    void passfunc(string& s , int pos , string& curr ,string temp , unordered_set<string>& memo , vector<string>& result){
        // cout << curr <<endl;
        if(pos == s.size()){
            curr.pop_back();
            result.push_back(curr);
            return;
        }
        for(int i = pos; i< s.size() ; i++){
            if(memo.contains(temp)){
                string t = curr + temp + " ";
                passfunc(s , i , t , "" , memo , result);
            }
            temp += s[i];
        }
        if(memo.contains(temp)){
                string t = curr + temp + " ";
                passfunc(s , s.size() , t , "" , memo , result);
            }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> memo;
        for(auto q: wordDict) memo.insert(q);
        string curr = "";
        vector<string> result;
        passfunc(s , 0 , curr , "" , memo , result);
        return result;
    }
};