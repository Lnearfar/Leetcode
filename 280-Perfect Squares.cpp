class Solution {
public:
    int numSquares(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        static vector<int> dp({0});
        while(dp.size()<=n){
            int m=dp.size();
            int tmp=INT_MAX;
            for(int i=1;i*i<=m;i++){
                tmp=min(dp[m-i*i]+1,tmp);
            }
            dp.push_back(tmp);
            printf("dp[%d]=%d\n",m,dp[m]);
        }
        return dp[n];
    }
};
