class Solution {
public:
    bool ans;
    bool visited[101][101];
    void dfs(vector<vector<char>>& arr, string str, int i,  int j, int n, int m, int idx){
        if(i<0 or j<0 or i>=n or j>=m or visited[i][j]==true or  arr[i][j]!=str[idx]){
            return ;
        }
        if(idx==str.length()-1 and arr[i][j]==str[str.length()-1]){
            ans = true;
            return ;
        }
        visited[i][j] = true;
        dfs(arr, str, i+1,j,n,m, idx+1);
        dfs(arr, str, i-1,j,n,m ,idx+1);
        dfs(arr, str, i,j+1,n,m, idx+1);
        dfs(arr, str, i,j-1,n,m ,idx+1);
        visited[i][j] = false;
    }


    bool isWordExist(vector<vector<char>>& arr, string str) {
        ans = false;
        memset(visited, false, sizeof(visited));
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==str[0]){
                    ans = false;
                    dfs(arr, str, i,j,arr.size(), arr[0].size(),0);
                    if(ans == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
