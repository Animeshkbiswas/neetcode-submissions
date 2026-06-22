class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(maxheap.empty()||num<=maxheap.top()) {
        maxheap.push(num);
       }
       else{
        minheap.push(num);
       }
        if(maxheap.size() > minheap.size()+1){
            int ma=maxheap.top();
            maxheap.pop();
            minheap.push(ma);
        }
        if(minheap.size() > maxheap.size()+1){
            int mi=minheap.top();
            minheap.pop();
            maxheap.push(mi);
        }
        if(!minheap.empty()){
        if(maxheap.top()>minheap.top()){
        int ma=maxheap.top();
        maxheap.pop();
        int mi=minheap.top();
        minheap.pop();
        maxheap.push(mi);
        minheap.push(ma);
            
        }

        
    }
    }
    
    double findMedian() {
        if((maxheap.size()-minheap.size())==0){
            return (maxheap.top()+minheap.top())/2.0;
        }
        else{
            if(maxheap.size()>minheap.size()){
                return maxheap.top();
            }
            else{
                return minheap.top();
            }
        }
    return 0;
    }
};
