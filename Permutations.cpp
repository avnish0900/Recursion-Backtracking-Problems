#include<bits/stdc++.h>
using namespace std;

void permutation(string inn,int i){
  if(inn[i]=='\0'){
    cout<<inn<<endl;
    return ;
  }
  for(int j=i;inn[j]!='\0';j++){
    swap(inn[i],inn[j]);
    permutation(inn,i+1);
    swap(inn[i],inn[j]);
  }
  return ;
}

int main(){
  string inn;
  cin>>inn;
  permutation(inn,0);
}
