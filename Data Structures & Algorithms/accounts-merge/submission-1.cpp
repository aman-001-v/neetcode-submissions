class Solution {
public:
    class unionfind{

        public:
            int val;
            unionfind* par;
            int rank;

            unionfind(){
                val = -1;
                par = nullptr;
                rank = 0;
            }
            unionfind(int val){
                this -> val = val;
                this -> par = this;
                this -> rank = 0;
            }
            unionfind* find(){
                unionfind* node = this;
                while(node -> par != node){
                    node -> par = node -> par -> par;
                    node = node -> par;
                }
                return node;
            }
            bool merge(unionfind* other){
                unionfind* p1 = this -> find();
                unionfind* p2 = other -> find();

                if(p1 == p2) return false;

                if(p1 -> rank > p2 -> rank) p2 -> par = p1;
                else if(p1 -> rank < p2 -> rank) p1 -> par = p2;
                else{
                    p2 -> par = p1;
                    p1 -> rank += 1;
                }
                return true;
            }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string , int> memo;
        vector<unionfind*> nodes(accounts.size() , nullptr);
        for(int i = 0 ; i < accounts.size() ; i++){
            nodes[i] = new unionfind(i);
        }
        for(int i = 0 ; i < accounts.size() ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                if(memo.contains(accounts[i][j])){
                    unionfind* n1 = nodes[i];
                    unionfind* n2 = nodes[memo[accounts[i][j]]];
                    n1 -> merge(n2);
                }
                else memo[accounts[i][j]] = i;
            }
        }

        vector<vector<string>> result;
        unordered_map<int , unordered_set<string>> temp;
        for(const auto& [email , key] : memo){
            int i = nodes[key] -> find() -> val;
            temp[i].insert(email);
        }

        for(const auto& [i , emails] : temp){
            result.resize(result.size() + 1);
            result[result.size() - 1].push_back(accounts[i][0]);
            for(const auto& email : emails) result[result.size() - 1].push_back(email);
            sort(result[result.size() - 1].begin() + 1 , result[result.size() - 1].end());
        }

        return result;
    }
};