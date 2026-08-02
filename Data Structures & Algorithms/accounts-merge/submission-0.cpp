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
            unionfind* find(unionfind* node){
                while(node -> par != node){
                    node -> par = node -> par -> par;
                    node = node -> par;
                }
                return node;
            }
            bool merge(unionfind* n1 , unionfind* n2){
                unionfind* p1 = n1 -> find(n1);
                unionfind* p2 = n2 -> find(n2);

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
                    n1 -> merge(n1 , n2);
                }
                else memo[accounts[i][j]] = i;
            }
        }
        for(int i = 0 ; i < accounts.size() ; i++){
            nodes[i] -> find(nodes[i]);
        }
        for(int i = 0 ; i < accounts.size() ; i++){
            nodes[i] -> find(nodes[i]);
        }

        vector<vector<string>> result(accounts.size() , vector<string>());

        for(const auto& [email , key] : memo){
            if(result[nodes[key] -> par -> val].empty()) result[nodes[key] -> par -> val].push_back(accounts[nodes[key] -> par -> val][0]);
            result[nodes[key] -> par -> val].push_back(email);
        }

        for(int i = 0 ; i < result.size() ; i++){
            if(result[i].empty()) result.erase(result.begin() + i--);
            else sort(result[i].begin() + 1 , result[i].end());
        }
        
        return result;
    }
};