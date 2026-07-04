/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* passfunc(vector<vector<int>>& grid , int row_start , int row_end , int column_start , int column_end){
        int check = grid[row_start][column_start];
        bool flag = true;
        for(int i = row_start ; i<row_end ; i++){
            for(int j = column_start ; j < column_end ; j++){
                if(grid[i][j] != check){
                    flag = false;
                    break;
                }
            }
            if(flag == false){
                break;
            }
        }
        if(flag == true){
            if(check == 0) flag = false;
            return new Node(flag , true);
        }else{
            Node* top_left = passfunc(grid , row_start , (row_start+row_end)/2, column_start , (column_start+column_end)/2);
            Node* top_right = passfunc(grid , row_start , (row_start+row_end)/2 , (column_start+column_end)/2 , column_end);
            Node* bottom_left = passfunc(grid , (row_start+row_end)/2 , row_end , column_start , (column_start+column_end)/2);
            Node* bottom_right = passfunc(grid , (row_start+row_end)/2 , row_end , (column_start+column_end)/2 , column_end);
            return new Node(true , false,top_left , top_right , bottom_left , bottom_right);
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* root = passfunc(grid,0,n,0,n);
        return root;
    }
};