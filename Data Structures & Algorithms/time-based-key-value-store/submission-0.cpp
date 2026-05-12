class TimeMap {
public:
    unordered_map<string,map<int,string>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
       
        if(mpp.find(key)==mpp.end()){
            return "";
        }
        auto it = mpp[key].upper_bound(timestamp);
        if (it == mpp[key].begin()) {
                  return "";
            }
            --it; 
            return it->second;
       
    
    }
};
