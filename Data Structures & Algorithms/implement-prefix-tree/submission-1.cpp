class PrefixTree {
public:
        unordered_set<string> memo;
    PrefixTree() {
        
    }
    
    void insert(string word) {
        memo.insert(word);
    }
    
    bool search(string word) {
        return memo.contains(word);
    }
    
    bool startsWith(string prefix) {
       for(const auto& q:memo){
            bool flag = true;
            for(int j = 0 ; j < prefix.length() ; j++){
                if(j >= q.length()){
                    flag = false;
                    break;
                }
                if(q[j] != prefix[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false; 
    }
};
