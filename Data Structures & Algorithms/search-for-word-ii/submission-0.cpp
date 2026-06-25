class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            if(isPresent(board,words[i])) ans.push_back(words[i]);
        }
        return ans;
    }
    bool isPresent(vector<vector<char>>& board,string& word){
        bool ans=false;
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                     dfs(board,word,row,col,0,ans);
            }
        }
       
       return ans;
    }
    void dfs(vector<vector<char>>& board,string& word, int row, int col, int i, bool &ans){
        if(row<0|| col<0||row>=board.size()|| col>=board[0].size()){
            return;
        }
        
        if(board[row][col]!=word[i]){
            return;
        }
        if(i==word.size()-1){
         ans= true;
         return;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        if(temp==word[i]){
            dfs(board,word,row+1,col,i+1,ans);
           if(ans==true) {
            board[row][col] = temp;
            return;
            }
           dfs(board,word,row,col+1,i+1,ans);
           if(ans==true) {
            board[row][col] = temp;
            return;
            }
           dfs(board,word,row-1,col,i+1,ans);
           if(ans==true) {
            board[row][col] = temp;
            return;
            }
           dfs(board,word,row,col-1,i+1,ans);
           if(ans==true) {
            board[row][col] = temp;
            return;
            }
        }
        board[row][col]= temp;
    }
};
