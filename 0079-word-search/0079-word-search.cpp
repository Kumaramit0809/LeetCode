class Solution {
public:
    int n,m;
    bool check(vector<vector<char>>& board,int i,int j,string word,int k)
    {
        //correct condition
        if(k == word.size())return true;

        //base condition
        if(i >= m || i < 0 || j < 0 || j >= n || board[i][j] != word[k])return false;

        //store for backtracking later
        char temp = board[i][j];

        //mark the element as visited
        board[i][j] = 'v';

        bool ans = (
        //right 
        check(board,i+1,j,word,k+1) ||
        //down
        check(board,i,j+1,word,k+1) ||
        //left
        check(board,i-1,j,word,k+1) ||
        //up
        check(board,i,j-1,word,k+1));

        //backtrack
        board[i][j] = temp;
        
        return ans;

    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(check(board,i,j,word,0))return true;
            }
        }
        return false;
    }
};