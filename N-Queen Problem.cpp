#include<bits/stdc++.h>
using namespace std;

// '0' means no Queen is placed
// '1' means 1  Queen is placed

bool isSafe(int **arr,int r,int c,int n){

  //checking if any queen already placed in that row for that specified column
  for(int i=0;i<r;i++){
    if(arr[i][c]==1){   
      return false;
    }
  }
  //checking if any queen already placed in diagonal (going in top-left most)
  int row=r,col=c;
  while(row>=0 and col>=0){
    if(arr[row][col]==1){
      return false;
    }
    row--;
    col--;
  }
  row=r,col=c;
  //checking if any queen already placed in diagonal(going in top-right most)
  while(row>=0 and col<n){
    if(arr[row][col]==1){
      return false;
    }
    row--;
    col++;
  }
  //if all cases checked and not found then returning true i.e. this position is safe
  return true; 
}

bool nQueen(int **arr,int x,int n){
  if(x>=n){
    return true;  // all N Queens are placed in best possible manner
  }
  for(int col=0;col<n;col++){
    if(isSafe(arr,x,col,n)){   // if this is safe position
      arr[x][col]=1;
      if(nQueen(arr,x+1,n)){  //checking for next queen i.e. it can be placed or not
        return true;         // if yes then  return true;
      }
      arr[x][col]=0;         //now backtrack or undo the previous move
    }
  }
  //checked all cases and not found any safe position thus returning false
  return false;      
}

int main(){
  int n;cin>>n;
  int **arr=new int* [n];
  for(int i=0;i<n;i++){
    arr[i]=new int[n];
    for(int j=0;j<n;j++){
      arr[i][j]=0;
    }
  }
  if(!nQueen(arr,0,n)){
    cout<<"Solution not Possible for this N\n";
  }
  else{
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<arr[i][j]<<" ";
      }
     cout<<endl;
    }
  }
}
