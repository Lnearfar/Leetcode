class Solution {
public:

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size();
        vector<vector<int>> visit(m,vector<int>(n));
        typedef pair<int,int> co;
        int rnd=-1;
        bool searched=false;
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

        queue<co> dfs;
        dfs.push(co(entrance[0],entrance[1]));
        maze[entrance[0]][entrance[1]]='+';
        //
        while(!dfs.empty()){
            rnd++;
            int k=dfs.size();
            for(int r=0;r<k;r++){
                co sch=dfs.front();
                int i=sch.first,j=sch.second;
                //if dlg
                //printf("searched (%d,%d) maze[i][j]=%c\n",i,j,maze[i][j]);
                dfs.pop();


                for(auto dir:dirs){
                    int next_i=i+dir.first,next_j=j+dir.second;

                    if(next_i>=0&&next_i<m&&next_j>=0&&next_j<n&&maze[next_i][next_j]=='.'){
                        if(next_i==0||next_i==m-1||next_j==0||next_j==n-1){
                            return rnd+1;
                        }
                        maze[next_i][next_j]='+';
                        dfs.push(co(next_i,next_j));
                    }
                }
            }
        }
        if(searched==true){
            return rnd;
        }
        else return -1;
    }
};
