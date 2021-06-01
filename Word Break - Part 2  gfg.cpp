
class Solution{
public:
void dfs(string str,string path,set<string>& s,vector<string> &ans){
    if(str.length()==0){
        path.pop_back();
        ans.push_back(path);
        return ;
    }
    for(int i=0 ;i<str.length();i++){
        string left = str.substr(0,i+1);
        if(s.find(left)!=s.end()){
            string right = str.substr(i+1);
            dfs(right,path+left+" ", s,ans );
        }
    }
}
    vector<string> wordBreak(int n, vector<string>& dict, string str)
    {
        set<string> s;
        for(auto i: dict){
            s.insert(i);
        }
        vector<string> ans;
        dfs(str,"",s,ans);
        return ans;
    }
};
