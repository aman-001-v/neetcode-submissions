class WordDictionary {
public:
    WordDictionary* memo[26] = {nullptr};
    bool endOfWord = false;

    bool dfs(WordDictionary* root , string word){
        if(word == ""){
            return root -> endOfWord;
        }
        char c = word[0];
        word.erase(word.begin());
        if(c == '.'){
            for(int i = 0; i< 26 ; i++){
                if(root -> memo[i] != nullptr){
                    bool flag = dfs(root -> memo[i] , word);
                    if(flag) return true;
                }
            }
            return false;
        }else{
            if(root -> memo[(int)c - 97] == nullptr){
                return false;
            }
            return dfs(root -> memo[(int)c - 97] , word);
        }
    }
    WordDictionary() {

    }
    
    void addWord(string word) {
        WordDictionary* t = this;
        for(char c : word){            
            if(t -> memo[(int)c - 97] == nullptr){
                t -> memo[(int)c - 97] = new WordDictionary;
            }
            t = t -> memo[(int)c - 97];
        }
        t -> endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(this , word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */