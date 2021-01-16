#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>solution,int rows,int columns){
  cout<<"===============\n";
  for(int i=0;i<=rows;i++){
    for(int j=0;j<=columns;j++){
      cout<<solution[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"===============\n";
}

bool isSafe(int i, int j, vector<vector<int>>maze,int row,int col,vector<vector<int>>visited){
  if (i == -1 || i == row+1 || j == -1 || j == col+1 || visited[i][j] || maze[i][j] == 1)
    return false;
  return true;
}


bool pathExist(vector<vector<int>> maze,vector<vector<int>>solution,
vector<vector<int>>visited,int i,int j,int rows,int columns){
  

  if (i == -1 || i == rows+1 || j == -1 || j == columns+1 || visited[i][j] || maze[i][j] == 1){
    return false;
  }
  if(i==rows and j==columns){
    solution[i][j]=1;
    print(solution,rows,columns);
    return true;
  }
  visited[i][j]=true;
  solution[i][j]=1;
  bool right=pathExist(maze,solution,visited,i,j+1,rows,columns);
  bool bottom=pathExist(maze,solution,visited,i+1,j,rows,columns);
  bool up=pathExist(maze,solution,visited,i-1,j,rows,columns);
  bool left=pathExist(maze,solution,visited,i,j-1,rows,columns);
  if((right or left) or (up or bottom)){
    return true;
  }
  solution[i][j]=0;
  visited[i][j]=false;
  return false;
}


int main(){
  int rows,column;cin>>rows>>column;
  vector<vector<int>> maze( rows , vector<int> (column, 0)); 
  for(int i=0;i<rows;i++){
    for(int j=0;j<column;j++){
      cin>>maze[i][j];
    }
  }
  vector<vector<int>> solution( rows , vector<int> (column, 0));
  vector<vector<int>> visited( rows , vector<int> (column, 0));
  if(!pathExist(maze,solution,visited,0,0,rows-1,column-1)){
    cout<<"Path doesnot Exist\n";
  }
  return 0;
}
