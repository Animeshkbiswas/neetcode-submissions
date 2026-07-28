class Solution {
private:
    void bfs(vector<vector<int>>& grid,queue<pair<int,pair<int,int>>>& q,int m,int n,int time,int& maxtime){
        int row= grid.size();
        int col= grid[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr= m+ dr[k];
            int nc= n+ dc[k];
            if(nr>=0&&nc>=0&&nr<row&& nc<col&&grid[nr][nc]==1){
                grid[nr][nc]= 2;
                q.push({time+1,{nr,nc}});
                maxtime=max(time+1,maxtime);
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                     q.push({0,{i,j}});
                }
            }
        }
        int maxtime=0;
        while(!q.empty()){
            pair<int,pair<int,int>>p= q.front();
            q.pop();
            int time=p.first;
            pair<int,int> r=p.second;
            int m= r.first;
            int n= r.second;

            bfs(grid,q,m,n,time,maxtime);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                     return -1;
                }
            }
        }
        return maxtime;
    }
};