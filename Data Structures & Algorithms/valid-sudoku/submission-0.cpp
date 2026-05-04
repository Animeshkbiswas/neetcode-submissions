class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    int n =board.size();
       for(int i=0; i<9; i++){
        set<char> mpp;
        for(int j=0; j<9; j++){
             if(board[i][j] == '.') continue;
          auto it=  mpp.insert(board[i][j]);
          if(!it.second){
            return false;
          }
        
        }

       }
        for(int j=0; j<9; j++){
            set<char> mpp;
        for(int i=0; i<9; i++){

             if(board[i][j] == '.') continue;
          auto it=  mpp.insert(board[i][j]);
          if(!it.second){
            return false;
          }
        
        }

       }
        for(int i=0; i<9; i+=3){
        
        for(int j=0; j<9; j+=3){
             set<char> mpp;
             for(int k=i; k<i+3; k++){
                    for(int m=j; m<j+3; m++){
                          if(board[k][m] == '.') continue;
          auto it=  mpp.insert(board[k][m]);
          if(!it.second){
            return false;
          }
                    }
             }
        }
        }

    return true;
    }
};
