class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        for(int i=0;i<temperatures.size();i++){
            int k=temperatures[i];
            if(i==temperatures.size()-1){
                ans.push_back(0);
            }
            for(int j=i+1; j<temperatures.size(); j++){
                if(temperatures[j]>k){
                    ans.push_back(j-i);
                    break;
                }
                else if(j==temperatures.size()-1){
                    ans.push_back(0);
                }
            }
        }
    return ans;
    }
};
