/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* bfs(Node* root , unordered_map<int , Node*>& memo){
        if(root == nullptr) return nullptr;
        if(memo.contains(root -> val)) return memo[root -> val];
        Node* temp = new Node(root -> val);
        memo[temp -> val] = temp;
        for(auto q : root -> neighbors) temp -> neighbors.push_back(bfs(q , memo));
        return temp;
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<int , Node*> memo;
        return bfs(node , memo);

    }
};