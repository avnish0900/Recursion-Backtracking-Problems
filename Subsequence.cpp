#include<bits/stdc++.h>
using namespace std;

void subsequence(string str,int index,string ans){
  if(ans.length()!=0){
    cout<<ans<<endl;
  }
  for(int i=index+1;i<str.length();i++){
    ans+=str[i];
    subsequence(str,i,ans);
    ans=ans.erase(ans.length()-1);
  }
  return ;
}

int main(){
  string str;cin>>str;
  subsequence(str,-1,"");
}
