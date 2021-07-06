class Solution{
    public:
    
    void dfs(vector<int> g[], int src, vector<bool>& visited){
        visited[src] = true;
        for(int i=0;i<g[src].size();i++){
            if(visited[g[src][i]]==false){
                dfs(g, g[src][i], visited);
            }
        }
    }
    
    bool connected(vector<int> g[], vector<bool>& marked, int src){
        vector<bool> visited(marked.size(), false);
        dfs(g, src, visited);
        for(int i=0;i<marked.size()-1;i++){
            if(marked[i] and !visited[i]){
                return false;
            }
        }
        return true;
    }
    
    int isCircle(int N, vector<string> A){
        int n =N;
        N = N+100;
        vector<int> g[N+1];
        vector<int>inn(N+1), out(N+1);
        vector<bool> marked(N+1, false);
        for(string str: A){
            int f = str[0]-'a';
            int  l = str[str.length()-1]-'a';
            marked[f] = marked[l] = true;
            inn[l]++;out[f]++;
            g[f].push_back(l);
        }
        for(int i=0;i<N;i++){
            if(inn[i]!=out[i]){
                return false;
            }
        }
        string ss = A[0];
        char chh = ss[0];
        int nn = chh-'a';
        return connected(g, marked, nn);
    }
};
