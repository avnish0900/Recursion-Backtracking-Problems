#include <bits/stdc++.h>
using namespace std;
bool CanWePlace(int sudoku[][9],int i,int j,int n,int number){
  for(int x=0;x<n;x++){
    if(sudoku[x][j]==number||sudoku[i][x]==number)
      return false;          
  }
  int sq=sqrt(n);
  int sub_matrix_row = (i/sq)*sq;
  int sub_matrix_col = (j/sq)*sq;
  for(int x=sub_matrix_row;x<sub_matrix_row+sq;x++){
    for(int y=sub_matrix_col;y<sub_matrix_col+(n/sq);y++){
      if(sudoku[x][y]==number){
        return false;
      }
    }
  }
  return true;
}

bool solution_to_Sudoku(int sudoku[][9],int i,int j,int n){
  if(i==n){
    cout<<endl<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<sudoku[i][j]<<" ";
      }
      cout<<endl;
    }
    return true;
  }
  if(j==n){
    return solution_to_Sudoku(sudoku,i+1,0,n);
  }
  if(sudoku[i][j]!=0){
    return solution_to_Sudoku(sudoku,i,j+1,n);
  }
  else {for(int number=1;number<=n;number++){
    if(CanWePlace(sudoku,i,j,n,number)){
      sudoku[i][j]=number;
      if(solution_to_Sudoku(sudoku,i,j+1,n)){
        return true;
      }
    }
  }
  sudoku[i][j]=0;
  return false;
  }
}

int main() {
  int n;
  cin>>n;
  int sudoku[9][9]={0};
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>sudoku[i][j];
    }
  }
  solution_to_Sudoku(sudoku,0,0,n);
  return 0;
}
