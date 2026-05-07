class Solution {
public:
    string minWindow(string s, string t) {
        
        int n=t.size();
        int n2=s.size();
        string ans;
        vector<int> count(256,0);
        vector<int> count2(256,0);
        vector<int> count3(256,0); 
        vector<int> count4(256,0); 
        int min=n2;
        int right=0;
        int left=0;
        int c=n;
        int lefts=0;
        int rights=n;

        for(auto it:t){
            count[it]++;
            count4[it]++;
        
        }
        for(auto it:s){
            count2[it]++;
        }
        for(int i=0; i<256;i++){
            if(count[i]>count2[i]){
                return "";
            }
        }
       while(left<n2){
         count=count4;
        if(count[s[left]]==0){
            left++;
            right++;
        }
        else{
            count[s[left]]--;
            while(count!=count3&& right<n2){
                right++;
                if(count[s[right]]>0){
                    count[s[right]]--;
                };
            }
            if(count==count3&& min>(right-left+1)){
                min=right-left+1;
                lefts=left;
                rights=right;
            }
            left++;
            right=left;
        }

       }
        ans=s.substr(lefts,rights-lefts+1);
    return ans;
    }
};
