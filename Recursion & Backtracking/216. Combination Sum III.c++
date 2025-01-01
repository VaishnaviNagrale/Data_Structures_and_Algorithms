class Solution {
public:
    void solve(int idx, int target, vector<int> arr, vector<int>& ds,
               vector<vector<int>>& ans,int k) {
        if (target == 0) {
            if(ds.size()==k){
                ans.push_back(ds);
            }
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i - 1]) {
                continue;
            }
            if (arr[i] > target) {
                break;
            }
            if (arr[i] <= target) {
                ds.push_back(arr[i]);
                solve(i + 1, target - arr[i], arr, ds, ans,k);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        for(int i=1;i<=9;i++){
            arr.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, n, arr, ds, ans,k);
        return ans;
    }
};