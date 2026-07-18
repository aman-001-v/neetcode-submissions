class Solution {
public:
    bool checkpalindrome(string s){
        for(int i = 0; i < s.length()/2 ; i++){
            if(s[i] != s[s.length() - 1 - i]){
                return false;
            }
        }
        return true;
    }
    void passfunc(string s , int pos , vector<string>& curr , vector<vector<string>>& result){
        if(s.empty()){
            result.push_back(curr);
            return;
        }
        for(int i = pos ; i <= s.length() ; i++){
            string lstr = "";
            for(int j = 0 ; j < i ; j++){
                lstr += s[j];
            }
            
            if(checkpalindrome(lstr)){
                curr.push_back(lstr);
                string rstr = "";
                for(int j = i; j < s.length() ; j++){
                    rstr += s[j];
                }
                passfunc(rstr , 1 , curr , result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> result;
        passfunc(s , 1 , curr , result);
        return result;
    }
};