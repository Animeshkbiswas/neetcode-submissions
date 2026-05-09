class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
       stack<int> stk;
       int i=  temperatures.size()-1;
       while(i>=0){
        if(stk.empty()){
            stk.push(i);
            ans.push_back(0);
            i--;
        }
        else if(temperatures[i]>=temperatures[stk.top()]){
            stk.pop();
            continue;
        }
        else{
            ans.push_back(stk.top()-i);
            stk.push(i);
            i--;
        }
        
       }
       reverse(ans.begin(),ans.end());
    return ans;
    }
};
