class Solution {
public:
    vector<string> pattern(string str){
        string temp = str;
        vector<string> result;
        for(int i = 0 ; i< str.length() ; i++){
            temp[i]='.';
            result.push_back(temp);
            temp = str;
        }
        return result;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string , vector<string>> memo;
        bool endExists = false;
        for(string& w: wordList){
            if(w == endWord) endExists = true;
            vector<string> patternList = pattern(w);
            for(string& q: patternList){
                memo[q].push_back(w);
            }
        }

        if(!endExists) return 0;

        int length = 0;
        queue<string> bucket;
        unordered_set<string> visited;
        bucket.push(beginWord);
        visited.insert(beginWord);
        while(!bucket.empty()){
            length++;
            int n = bucket.size();
            for(int i = 0 ; i < n ; i++){   
                if(bucket.front() == endWord) return length;
                vector<string> patternStart = pattern(bucket.front());
                bucket.pop();
                for(string& p : patternStart){
                    for(string& w: memo[p]){
                        if(!visited.contains(w)){
                            bucket.push(w);
                            visited.insert(w);
                        }
                    }
        
                }
            }
        }
        
        return 0;

    }
};