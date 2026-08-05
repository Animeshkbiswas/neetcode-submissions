class Solution {
public:
    int ss(int n){
        int temp=0;
        while(n>=1){
            temp +=(n%10)*(n%10);
            n=n/10;
        }
        return temp;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        n= ss(n);
        while(s.find((n))==s.end()){
            s.insert(n);
            n=ss(n);
            if(n==1){
                return true;
            }
        }
        
    return false;
    }
};
