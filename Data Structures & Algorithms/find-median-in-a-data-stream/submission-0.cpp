class MedianFinder {
public:
    priority_queue<int> que1;
    priority_queue<int , vector<int> , greater<int>> que2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       int n1 = que1.size();
       int n2 = que2.size();
       if(n1 == n2){
            if(!que1.empty() && num <= que1.top()) que1.push(num);
            else que2.push(num);
       }
       else if(n1 < n2){
            if(num <= que2.top()) que1.push(num);
            else{
                que1.push(que2.top());
                que2.pop();
                que2.push(num);
            }
       }
        else{
            if(num >= que1.top()) que2.push(num);
            else{
                que2.push(que1.top());
                que1.pop();
                que1.push(num);
            }
        }
    }
    
    double findMedian() {
        int n1 = que1.size();
        int n2 = que2.size();
        if(n1 == n2){
            return (double)(que1.top() + que2.top())/2.0;
        }
        else if(n1 > n2) return que1.top();
        else return que2.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */