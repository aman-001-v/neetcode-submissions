class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , int>> memo;
        for(int i = 0 ; i < points.size() ; i++){
            int t = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            memo.push({t , i});
            if(memo.size() > k) memo.pop();
        }
        vector<vector<int>> res;
        while(!memo.empty()){
            res.push_back(points[memo.top().second]);
            memo.pop();
        }
        return res;
    }
};
