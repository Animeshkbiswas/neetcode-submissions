class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        string ans;
        vector<int> need(256,0);
        vector<int> window(256,0); 

        for(auto it:t){
            need[it]++; 
        }
        int required=0;
        
        for(int i=0; i<256; i++){
            if(need[i]>0){
                required++;
            }
        }
        int formed=0;
        int left=0;
        int minLen =INT_MAX;
        int start=0;
        for(int right=0; right<s.size(); right++){
            char c= s[right];
            window[c]++;
            if(window[c]==need[c] && need[c]>0){
                formed++;
            }
            while(formed==required){
                  if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];
                window[ch]--;
                if(window[ch] < need[ch] && need[ch] > 0){
                    formed--;
                }

                left++;
            }
        }


        if(minLen == INT_MAX) return "";



        ans=s.substr(start,minLen);
    return ans;
    }
};
