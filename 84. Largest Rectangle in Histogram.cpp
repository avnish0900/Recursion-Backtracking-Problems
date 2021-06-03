class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> s;
        // arr.push(0);
        int ans = 0;
        int i=0;
        int n =arr.size();
        while(i<n){
          while(!s.empty() and arr[s.top()] > arr[i])  {
              int tt = s.top();
              int ht = arr[tt];
              s.pop();
              if(s.empty()){
                  ans = max(ans , ht*i);
              }else{
                  int tt = i-s.top()-1;
                  ans = max(ans,tt*ht);
              }
          }
           s.push(i);
            i++;
        }
        
        while(!s.empty()){
            int tt = s.top();
            int xx = arr[tt];
            s.pop();
            if(s.empty()){
                ans = max(ans, xx*i );
            }
            else{
                ans=max(ans,xx*(i-s.top()-1));
            }
        }
        return ans;
    }
};
