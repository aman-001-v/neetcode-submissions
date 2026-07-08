class PrefixTree {
public:
    char val;
    unordered_map<char,PrefixTree*> memo;
    bool eow = false;

    PrefixTree() {
        val = '.';
    }
    PrefixTree(char val){
        this -> val = val;
    }
    
    void insert(string word) {
        PrefixTree* t = this;
        for(int i = 0; i < word.length() ; i++){
            if(!(t -> memo.contains(word[i]))){
                PrefixTree* temp = new PrefixTree(word[i]);
                t -> memo[word[i]] = temp;
                
            }
            t = t -> memo[word[i]];
        }
        
        t -> eow = true;
    }
    
    bool search(string word) {
        PrefixTree* t = this;
        for(int i = 0; i < word.length(); i++){
            if(!( t -> memo.contains(word[i]))){
                return false;
            }
            t = t -> memo[word[i]];
        }
        return t -> eow;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* t = this;
        for(int i = 0; i < prefix.length(); i++){
            if(!(t -> memo.contains(prefix[i]))){
                return false;
            }
            t = t -> memo[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */