class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       
        vector<int> count(26,0);
        for(auto it: s1){
            count[it-'a']++;
        }
        int n1=s1.size();
        int n2=s2.size();
        int left=0;
        int right=n1;
        vector<int>count2(26,0);
        for(int i=0; i<n1;i++){
            count2[s2[i]-'a']++;
        }
         if(count==count2){
                return true;
            }
        while(right<n2){
            
            
                
                count2[s2[left]-'a']--;
                left++;

               count2[s2[right]-'a']++;
               right++;
            if(count==count2){
                return true;
            }
            
        }
return false;
    }
};
