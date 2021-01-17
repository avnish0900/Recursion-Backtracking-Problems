#include<bits/stdc++.h>
using namespace std;

// that particular number denotes that particular move
void print(int **arr,int n){
  cout<<"=====================\n";
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<arr[i][j]<<"  ";
    }
    cout<<endl;
  }
  cout<<"=====================\n";
}

void knight(int **arr,int row,int col,int move,int n){
  if(row<0 or col<0 or row>=n or col>=n or arr[row][col]>0){
    return ; //out of boundries or already have done that move previously 
  }
  if(move==(n*n)){        //last move rest are done
    arr[row][col]=move;
    print(arr,n);         
    arr[row][col]=0;      //backtrack or undo the previous moves
    return ;
  }
  arr[row][col]=move;
  knight(arr,row-2,col+1,move+1,n);
  knight(arr,row-1,col+2,move+1,n);
  knight(arr,row+1,col+2,move+1,n);       //discover all the possible moves
  knight(arr,row+2,col+1,move+1,n);
  knight(arr,row+2,col-1,move+1,n);
  knight(arr,row+1,col-2,move+1,n);
  knight(arr,row-1,col-2,move+1,n);
  knight(arr,row-2,col-1,move+1,n);
  arr[row][col]=0;                        // if not 
}

int main(){
  int n;cin>>n;
  int r,c;cin>>r>>c;
  int **arr=new int *[n];
  for(int i=0;i<n;i++){
    arr[i]=new int [n];
    for(int j=0;j<n;j++){
      arr[i][j]=0;            //all are initially zero
    }
  }
  //passing particular row and column to start from and starting with move 1
  knight(arr,r,c,1,n);        
}
