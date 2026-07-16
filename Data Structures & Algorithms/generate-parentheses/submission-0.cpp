class Solution {
public:
    void passfunc(int n , int front , int back , string& curr , vector<string>& result){
         if (curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }
        if(front < n){
            curr += '(';
            passfunc(n , front + 1 , back , curr , result);
            curr.pop_back();
        }
        if(back < front){
            curr += ')';
            passfunc(n , front ,back + 1,curr , result);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> result;
        passfunc(n , 0 , 0 , curr , result);
        return result;

    }
};