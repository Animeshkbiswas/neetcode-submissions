class DisJoinset{
vector<int> size,parent;
public:
    DisJoinset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findPar(int l){
        if(l==parent[l]) return l;
        return parent[l]=findPar(parent[l]);
    }
    void s(int u, int v){
        u = findPar(u);
        v= findPar(v);
        if(size[u]<size[v]){
            parent[u]= v;
            size[v]+=size[u];
        }
        else{
            parent[v]= u;
            size[u]+=size[v];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        DisJoinset ds(n);
        vector<int> res;
        for(int i=0;i<n;i++){
            int u= edges[i][0];
            int v= edges[i][1];
            if(ds.findPar(u)==ds.findPar(v)){
                res.push_back(u);
                res.push_back(v);
                return res;
            }
            ds.s(u,v);
        }
        
    return res;
    }
};
