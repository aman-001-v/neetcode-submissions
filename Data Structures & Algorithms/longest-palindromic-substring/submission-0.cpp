class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;

        int longP = 0;
        int longQ = 0;

        for(int i = 0 ; i < s.length() ; i++){

            int p = i , q = i;
            int l = i , r = i + 1;
            if(s[l] == s[r]){
                    if(r - l > longQ - longP){
                        longQ = r;
                        longP = l;
                    }
            }

            while(p >= 0 && q < s.length()){
                if(s[p] == s[q]){
                    if(q - p > longQ - longP){
                        longQ = q;
                        longP = p;
                    }
                }else{
                    break;
                }
                p--;
                q++;
            }

            p = i;
            q = i + 1;
            while(p >= 0 && q < s.length()){
                if(s[p] == s[q]){
                    if(q - p > longQ - longP){
                        longQ = q;
                        longP = p;
                    }
                }else{
                    break;
                }
                p--;
                q++;
            }

        }
        string longestpali = "";
        for(int i = longP ; i <= longQ ; i++){
            longestpali += s[i];
        }

        return longestpali;
    }
};