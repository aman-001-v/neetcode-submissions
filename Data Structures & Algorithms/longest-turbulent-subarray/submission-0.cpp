class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int curr = 0;
        int global = 0;
        int i = 1;
        bool flag = false;
        while(i < arr.size()){
            if(!flag){
                if(arr[i - 1] < arr[i]){
                    flag = true;
                    curr++;
                }
                else{
                    global = max(global , curr);
                    if(arr[i - 1] > arr[i]) curr = 1;
                    else curr = 0;
                }
            }
            else{
                if(arr[i - 1] > arr[i]){
                    flag = false;
                    curr++;
                }
                else{
                    global = max(global , curr);
                    if(arr[i - 1] < arr[i]) curr = 1;
                    else curr = 0;
                }
            }
            i++;
        }
        global = max(global , curr);
        return global + 1;
    }
};