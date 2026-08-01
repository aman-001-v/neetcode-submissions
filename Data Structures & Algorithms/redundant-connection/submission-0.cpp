class Solution {
public:
    class unionfind{
        private:
            unionfind* par;
            int height;

        public:
            unionfind(){
                this -> par = this;
                height = 0;
            }
            unionfind(unionfind* par , int height){
                this -> par = par;
                this -> height = height + 1;

            }

            unionfind* find(unionfind* node){
                if(node -> par == node) return node;

                while(node -> par != node){
                    node -> par = node -> par -> par;
                    node = node -> par;
                }
                return node;
            }

            bool merge(unionfind* t1 , unionfind* t2){
                unionfind* p1 = t1 -> find(t1);
                unionfind* p2 = t2 -> find(t2);
                if(p1 == p2) return false;
                if(p1 -> height > p2 -> height){
                    p2 -> par = p1;
                }
                else if(p1 -> height < p2 -> height){
                    p1 -> par = p2;
                }
                else{
                    p2 -> par = p1;
                    p1 -> height += 1;
                }
                return true;
            }

    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<unionfind*> memo(edges.size() , nullptr);
        for(int i = 0 ; i < edges.size() ; i++){
            unionfind* t1;
            unionfind* t2;
            if(memo[edges[i][0] - 1] == nullptr){
                t1 = new unionfind();
                memo[edges[i][0] - 1] = t1;
            } else t1 = memo[edges[i][0] - 1];

            if(memo[edges[i][1] - 1] == nullptr){
                t2 = new unionfind();
                memo[edges[i][1] - 1] = t2;
            } else t2 = memo[edges[i][1] - 1];

            if(!t1 -> merge(t1 , t2)) return edges[i];
        }
        return {};
    }
};