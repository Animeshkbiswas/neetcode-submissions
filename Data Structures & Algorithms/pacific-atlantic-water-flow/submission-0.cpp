class Solution {
public:
    void bfs(vector<vector<int>>& heights,int m,int n,vector<vector<pair<int,int>>>&grid, bool o,queue<pair<int,int>>& q){
        int row= heights.size();
        int col= heights[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr= m+ dr[k];
            int nc= n+ dc[k];
           
            if(nr>=0&&nc>=0&&nr<row&& nc<col&&heights[nr][nc]>=heights[m][n]){
                
                if(o==true) {
                     if(grid[nr][nc].first == 1)continue;
                    grid[nr][nc].first=1;
                    q.push({nr,nc});
                    }
                else{
                     if(grid[nr][nc].second== 1)continue;
                    grid[nr][nc].second=1;
                    q.push({nr,nc});
                }
            }
        }   
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row= heights.size();
        int col= heights[0].size();
        vector<vector<pair<int,int>>>grid(row,vector<pair<int,int>>(col,{0,0}));
        vector<vector<int>>ans;
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0||j==0){
                    q.push({i,j});
                    grid[i][j].first=1;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int m=p.first;
            int n=p.second;
            bfs(heights,m,n,grid,true,q);
            
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==row-1||j==col-1){
                    q.push({i,j});
                    grid[i][j].second=1;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int m=p.first;
            int n=p.second;
            bfs(heights,m,n,grid,false,q);
            
        }
        for(int i=0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j].first == 1 && grid[i][j].second == 1){
                    vector<int> k;
                    k.push_back(i);
                    k.push_back(j);
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
