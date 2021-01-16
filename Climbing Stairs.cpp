#include<bits/stdc++.h>
using namespace std;
int countWays(int n) { 
  int dp[n + 1]; 
  dp[0] = 1; 
  dp[1] = 1; 
  dp[2] = 2; 
  for (int i = 3; i <= n; i++) 
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]; 
  return dp[n]; 
}
void solve(int n,int i,char *ans){
  if(n==0){
    ans[i]='\0';
    cout<<ans<<"\n";
    return ;
  }
  if(n<0){
    return ;
  }
  ans[i]='1';
  solve(n-1,i+1,ans);
  ans[i]='2';
  solve(n-2,i+1,ans);
  ans[i]='3';
  solve(n-3,i+1,ans);
}

void print(int n){
  char ans[n+1];
  solve(n,0,ans);
}

int main(){
  int n=5;
  cout<<"Total ways are = "<<countWays(n)<<endl;
  print(n);
}
