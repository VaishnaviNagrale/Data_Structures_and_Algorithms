class Solution {
public:
    void solve(int idx, int target, vector<int> arr, vector<int>& ds,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
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
                solve(i + 1, target - arr[i], arr, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, ds, ans);
        return ans;
    }
};