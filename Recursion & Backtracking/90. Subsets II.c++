class Solution {
public:
    void solve(int idx, vector<int>& ds, set<vector<int>>& ss, vector<int>& arr) {
        ss.insert(ds);
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]){
                continue;
            }
            ds.push_back(arr[i]);
            solve(i + 1, ds, ss, arr);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ss;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(0, ds, ss, nums);
        vector<vector<int>> ans;
        for (auto& x : ss) {
            ans.push_back(x);
        }
        return ans;
    }
};