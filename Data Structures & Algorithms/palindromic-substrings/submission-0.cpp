class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        for(int i = 0 ; i < s.length() ; i++){
            int p = i , q = i;

            while(p >= 0 && q < s.length()){
                if(s[p] == s[q]) count++;
                else break;
                p--;
                q++;
            }

            p = i , q = i + 1;

            while(p >= 0 && q < s.length()){
                if(s[p] == s[q]) count++;
                else break;
                p--;
                q++;
            }
        }
        return count;
    }
};