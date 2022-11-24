class Solution {
public:
    typedef pair<int,int> co;
    //dirs = (i-1,j),(i+1,j)....
    vector<co> dirs={{-1,0},{1,0},{0,-1},{0,1}};

    bool dfs(vector<vector<char>>& board,vector<vector<int>>&visit, string word,int depth,co c ){
        int cx=c.first,cy=c.second;
        if(depth==word.length()&&board[cx][cy]==word[depth-1]){return true;}
        bool rst=false;
        visit[cx][cy]=0;
        for(auto dir:dirs){
            int nextcx=cx+dir.first,nextcy=cy+dir.second;
            if(nextcx>=0&&nextcx<board.size()&&nextcy>=0&&nextcy<board[0].size()&&visit[nextcx][nextcy]==1&&board[nextcx][nextcy]==word[depth]){
                if(dfs(board,visit,word,depth+1,co(nextcx,nextcy))) rst=true;
                visit[nextcx][nextcy]=1;
            }
        }
        visit[cx][cy]=1;
        return rst;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> visit(m,vector<int>(n,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,visit,word,1,co(i,j))==true) return true;
                }
            }
        }
        return false;
    }
};
