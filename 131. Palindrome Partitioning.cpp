class Solution {
public:
    bool palin(string str){
        int left = 0;
        int right = str.length()-1;
        while(left<right){
            if(str[left]!=str[right]){
                return false;
            }
            left+=1;
            right-=1;
        }
        return true;
    }
    void dfs(string str,vector<string>& path,vector<vector<string>> &ans){
        if(str.length()==0){
            ans.push_back(path);
            return ;
        }
        for(int i=0;i<str.length();i++){
            string left = str.substr(0,i+1);
            string right = str.substr(i+1);
            if(palin(left)){
                path.push_back(left);
                dfs(right,path,ans);
                path.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        dfs(s,path,ans);
        return ans;
    }
};
