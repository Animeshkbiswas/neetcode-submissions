class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()!=1){
        int temp=pq.top();
        pq.pop();
        if(temp==pq.top()){
            pq.pop();
            if(pq.empty()){
            break;
           }
            continue;
        }
        
        else{
            int temp2= pq.top();
            pq.pop();
            pq.push(temp-temp2);
        }
        }
        if(!pq.empty()) return pq.top();
        return 0;
    }
};
