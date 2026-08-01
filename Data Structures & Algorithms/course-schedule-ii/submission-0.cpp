class Solution {
public:
    bool dfs(int i,vector<list<int>>& adj,vector<int>& vis, vector<int>& pathVis,vector<int>& ans){
        vis[i]=1;
        pathVis[i]=1;
        for(auto a :adj[i]){
            if(vis[a]==0){
               if( dfs(a,adj,vis,pathVis,ans)==false){
                return false;
               }
            }
            if(vis[a]==1&&pathVis[a]==1){
                return false;
            }
            
        }
        pathVis[i]=0;
        ans.push_back(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        vector<list<int>> adj(numCourses);
        vector<int> ans;
        for(int i=0; i<prerequisites.size();i++){
         adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0; i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj, vis, pathVis,ans)==false){
                    vector<int> a;
                    return a;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};