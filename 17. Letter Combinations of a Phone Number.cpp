class Solution {
public:
    string arr[9] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> dfs(string str){
        if(str.length()==0){
            vector<string> tt;
            tt.push_back("");
            return tt;
        }
        char ch = str[0];
        string right = str.substr(1);
        vector<string> temp = dfs(right);
        vector<string> result ;
        string code = arr[ch-'0'-1];
        for(int i=0;i<code.length();i++){
            char c = code[i];
            for(string s: temp){
                result.push_back(c+s);
            }
        }
        return result;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans = dfs(digits);
        if(ans.size()==1 and ans[0]==""){
            vector<string>xx;
            return xx;
        }
        return ans;
    }
};
