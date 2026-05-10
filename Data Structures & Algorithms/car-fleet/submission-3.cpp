class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int> mpp;
        vector<double> time;
        int s= speed.size();
        int ans=s;
        for(int i=0; i<speed.size();i++){
            mpp[position[i]]=speed[i];
        }

        for(auto it:mpp){
            time.push_back((float)(target-(it.first))/(it.second));
        }
        for(int i=s-1; i>0; i--){
            if(time[i]>=time[i-1]){
                time[i-1]=time[i];
                ans--;
            }
        }
    return ans;
    }
};
