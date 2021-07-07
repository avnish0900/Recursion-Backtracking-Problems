class Solution {
public:
bool visited[51][51];
bool ans ;
bool can(int i,int j,int n, int m, vector<vector<char>>& arr, string str, int pos){
    if(i>=0 and j>=0 and i<n and j<m and visited[i][j]==false and arr[i][j]==str[pos] ){
        return true;
    }
    return false;
}

void dfs(int i,int j,int n,int m, vector<vector<char>>& arr, string str, int pos){
    if(pos==str.length()-1 and arr[i][j]==str[pos]){
        ans = true;
        return ;
    }
    if(pos >= str.length()-1){
        return ;
    }
    visited[i][j] = true;
    if(can(i+1,j,n,m,arr,str,pos+1)){
        dfs(i+1,j,n,m,arr,str,pos+1);
    }
    if(can(i,j+1,n,m,arr,str,pos+1)){
        dfs(i,j+1,n,m,arr,str,pos+1);
    }
    if(can(i-1,j,n,m,arr,str,pos+1)){
        dfs(i-1,j,n,m,arr,str,pos+1);
    }
    if(can(i,j-1,n,m,arr,str,pos+1)){
        dfs(i,j-1,n,m,arr,str,pos+1);
    }
    if(can(i+1,j-1,n,m,arr,str,pos+1)){
        dfs(i+1,j-1,n,m,arr,str,pos+1);
    }
    if(can(i+1,j+1,n,m,arr,str,pos+1)){
        dfs(i+1,j+1,n,m,arr,str,pos+1);
    }
    if(can(i-1,j-1,n,m,arr,str,pos+1)){
        dfs(i-1,j-1,n,m,arr,str,pos+1);
    }
    if(can(i-1,j+1,n,m,arr,str,pos+1)){
        dfs(i-1,j+1,n,m,arr,str,pos+1);
    }
    visited[i][j] = false;
}
	vector<string> wordBoggle(vector<vector<char> >& arr, vector<string>& dictionary) {
	    vector<string>tt ;
	    ans = false;
	    set<string>ss;
	    int n = arr.size(), m= arr[0].size();
	    memset(visited, false, sizeof(visited));
	    map<string, int> mm;
	    for(string str: dictionary){
	        mm[str]++;
	    }
	    for(string str:dictionary ){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<m;j++){
	                if(arr[i][j]==str[0] and visited[i][j]==false){
	                    dfs(i,j,n,m,arr,str,0);
	                    if(ans == true){
	                        if(mm[str]>=1){
	                            ss.insert(str);
                                tt.push_back(str);
                                mm[str]--;
	                        }
	                        ans = false;
	                    }
	                }
	            }
	        }
	    }
	    return tt;
	}
};
