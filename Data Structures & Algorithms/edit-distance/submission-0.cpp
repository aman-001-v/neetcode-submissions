class Solution {
public:
    int passfunc(string word1 , string word2 , int i , int j , unordered_map<string , int>& memo){
        if(memo.contains(word1)){
            return memo[word1];
        }
        if(j == word2.length()){
            return word1.length() - i;
        }
        else if(i == word1.length()){
            return word2.length() - j;
        }
        if(word1[i] == word2[j]){
            return passfunc(word1 , word2 , i + 1 , j + 1 , memo);
        }
        string t1 = word1;
        t1.insert(t1.begin() + i , word2[j]);
        int a = passfunc(t1 , word2 , i + 1 , j + 1 , memo);
        t1 = word1;
        t1.erase(t1.begin() + i);
        int b = passfunc(t1 , word2 , i , j , memo);
        t1 = word1;
        t1[i] = word2[j];
        int c = passfunc(t1 , word2 , i + 1 , j + 1 , memo);

        return memo[word1] = 1 + min({a , b , c});
    }
    int minDistance(string word1, string word2) {
        unordered_map<string , int> memo;
        return passfunc(word1 , word2 , 0 , 0 , memo);
    }
};