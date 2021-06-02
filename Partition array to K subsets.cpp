class Solution{
  public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
        /*
        Solution: Backtracking with DP to check which elements have been already used
        TC: O(2^n) We know this is a NP problem so TC won't be that important
        SC: O(n)
        */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        vector<bool> visited(nums.size(), 0);
        return partition(0, k, 0, sum / k, nums, visited);
    }
    
    bool partition(int pos, int k, int curr, int target,        const vector<int>& nums, vector<bool> visited) {
        if (k == 1) return true; // if there is only one bucket to fill, return true
        if (curr == target) return partition(0, k - 1, 0, target, nums, visited);
        for (size_t i = pos; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true; // choose this for this bucket
                if (partition(i + 1, k, curr + nums[i], target, nums, visited)) return true;
                visited[i] = false; // unchoose this for this bucket
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         vector<int> nums(n);
         for(int i=0;i<n;i++){
             nums[i] = a[i];
         }
         return canPartitionKSubsets(nums,k);
    }
};
