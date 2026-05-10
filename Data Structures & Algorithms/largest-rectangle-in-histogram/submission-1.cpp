class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;
        int left=1;
        int m=heights[0];
        stk.push({heights[0],0});
        while(left<heights.size()){
            if(heights[left]>=stk.top().first){
                stk.push({heights[left],left});
                m=max(heights[left],m);
                left++;
            }
            else {
                int k;
                int idx;
                while(!stk.empty() && heights[left]<stk.top().first){
               k= stk.top().first*(left-stk.top().second);
                m=max(k,m);
                
                idx=stk.top().second;
                stk.pop();
                }
                stk.push({heights[left],idx});
                left++;
            }
        }
            while(!stk.empty()){
                int k;
                k= stk.top().first*(heights.size()-stk.top().second);
                m=max(k,m);
                stk.pop();
            }
            
        
    return m;
    }
};
