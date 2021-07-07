
class Solution{
public:
bool visited[501][501];
bool can(int i, int j, int n, int m, vector<vector<char>>& arr){
    if(i>=0 and j>=0 and i<n and j<m and visited[i][j]==false and arr[i][j]=='O' ){
        return true;
    }
    return false;
}
void dfs(int i, int j, int n, int m, vector<vector<char>>& arr ){
    visited[i][j] = true;
    arr[i][j] = 'Y';
    if(can(i+1,j,n,m,arr)){
        dfs(i+1,j,n,m,arr);
    }
    if(can(i-1,j,n,m,arr)){
        dfs(i-1,j,n,m,arr);
    }
    if(can(i,j+1,n,m,arr)){
        dfs(i,j+1,n,m,arr);
    }
    if(can(i,j-1,n,m,arr)){
        dfs(i,j-1,n,m,arr);
    }
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> arr){
        memset(visited, false, sizeof(visited));
       
        for(int i=0;i<n;i++){
            if(arr[i][0]=='O' and visited[i][0]==false){
                dfs(i,0,n,m,arr);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i][m-1]=='O' and visited[i][m-1]==false){
                dfs(i,m-1,n,m,arr);
            }
        }
        for(int i=0;i<m;i++){
            if(arr[0][i]=='O' and visited[0][i]==false){
                dfs(0,i,n,m,arr);
            }
        }
        for(int i=0;i<m;i++){
            if(arr[n-1][i]=='O' and visited[n-1][i]==false){
                dfs(n-1,i,n,m,arr);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='O'){
                    arr[i][j] = 'X';
                }
                else if(arr[i][j]=='Y'){
                    arr[i][j] = 'O';
                }
            }
        }
        return arr;
    }
};
