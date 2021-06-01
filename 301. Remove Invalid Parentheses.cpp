class Solution {
public:
    int minremoval(string str){
        stack<char> s;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                s.push(str[i]);
            }
            else{
                if(str[i]!=')'){
                    continue;
                }
                else{
                    if(s.size()==0){
                        s.push(str[i]);
                    }
                    else{
                        char ch = s.top();
                        if(ch == '('){
                            s.pop();
                        }
                        else{
                            s.push(str[i]);
                        }
                    }
                }
            }
        }
        return s.size();
    }
    bool valid(string str){
        stack<char> s;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                s.push(str[i]);
            }
            else{
                if(str[i]!=')'){
                    continue;
                }
                else{
                    if(s.size()==0){
                        s.push(str[i]);
                    }
                    else{
                        char ch = s.top();
                        if(ch == '('){
                            s.pop();
                        }
                        else{
                            s.push(str[i]);
                        }
                    }
                }
            }
        }
        if(s.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
    void dfs(string str,int removes, set<string>& ss,vector<string> &ans,set<string> &already_computed){
        if(removes==0){
            if(valid(str)){
                if(ss.find(str)==ss.end()){
                    ss.insert(str);
                    ans.push_back(str);
                    return;
                }
                return;
            }
            return ;
        }
        for(int i=0;i<str.length();i++){
            string left = str.substr(0,i);
            string right = str.substr(i+1);
            if(already_computed.find(left+right)==already_computed.end()){
                already_computed.insert(left+right);
               dfs(left+right,removes-1,ss,ans,already_computed);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int removal_allowed = minremoval(s);
        vector<string>ans;
        set<string> ss;
        set<string> already_computed;
        dfs( s,removal_allowed,ss,ans,already_computed);
        return ans;
    }
};
