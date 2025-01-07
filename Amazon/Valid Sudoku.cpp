class Solution {
public:
    bool check(int i,int j,vector<vector<char>> &board){
        unordered_set<char> st;
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(board[x+i][y+j]!='.' && st.count(board[x+i][y+j])) return false;
                else if(board[x+i][y+j]!='.') st.insert(board[x+i][y+j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //all verticals
        for(int i=0;i<9;i++){
            unordered_set<char> st;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && st.count(board[i][j])) return false;
                else if(board[i][j]!='.') st.insert(board[i][j]);
            }
        }
        
        //all verticals
        for(int j=0;j<9;j++){
            unordered_set<char> st;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.' && st.count(board[i][j])) return false;
                else if(board[i][j]!='.') st.insert(board[i][j]);
            }
        }

        //All 3*3 boxes
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!check(i,j,board)) return false;
            }
        }
        
        return true;
    }
};
