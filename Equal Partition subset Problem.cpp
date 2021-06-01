class Solution{
public:
vector<vector<int>> dp;
bool dfs(int arr[],int N,int pos,int sum){
    if(sum==0){
        return true;
    }
    if(pos>=N or sum<0){
        return false;
    }
    if(dp[pos][sum]!=-1){
        return dp[pos][sum];
    }
    return dp[pos][sum] = dfs(arr,N,pos+1,sum-arr[pos]) or dfs(arr,N,pos+1,sum);
}



    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum & 1){
            return 0;
        }
        int ll = (sum/2)+1;
        dp.resize(N+1,vector<int>(sum/2+1,-1));
        return dfs(arr,N,0,sum/2);
    }
};
