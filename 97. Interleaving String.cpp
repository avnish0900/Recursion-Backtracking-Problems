class Solution {
public:
    int dp[101][101];
    bool dfs(string s1,string s2,string s3,int n,int m,int len){
        if(len==0){
            return true;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int a =0;
        int b =0;
        if(n-1>=0 and s1[n-1]==s3[len-1]){
            a=dfs(s1,s2,s3,n-1,m,len-1);
        }
        if(m-1>=0 and s2[m-1]==s3[len-1]){
            b=dfs(s1,s2,s3,n,m-1,len-1);
        }
        dp[n][m]= (a or b);
        return dp[n][m];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int len = s3.length();
        if((n+m)!=len){
            return false;
        }
        dp[n][m];
        memset(dp,-1,sizeof(dp));
        return dfs(s1,s2,s3,n,m,len);
    }
};
