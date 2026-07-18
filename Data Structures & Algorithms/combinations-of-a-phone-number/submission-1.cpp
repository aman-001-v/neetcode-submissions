class Solution {
public:
    void passfunc(string& digits , int pos , vector<vector<char>>& memo , vector<string>& result , string& curr){
        if(pos == digits.length()){
            result.push_back(curr);
            return;
        }
        int n = digits[pos] - '0';
        for(int i = 0 ; i < memo[n - 2].size() ;i++){
            curr.push_back(memo[n - 2][i]);
            passfunc(digits , pos + 1 , memo , result , curr);
            curr.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<vector<char>> memo = {{'a' , 'b' , 'c'},
                                    {'d' , 'e' , 'f'},
                                    {'g' , 'h' , 'i'},
                                    {'j' , 'k' , 'l'},
                                    {'m' , 'n' , 'o'},
                                    {'p' , 'q' , 'r' , 's'},
                                    {'t' , 'u' , 'v'},
                                    {'w' , 'x' , 'y' , 'z'}};

        string curr = "";
        vector<string> result;
        passfunc(digits , 0 , memo , result , curr);
        return result;

    }
};