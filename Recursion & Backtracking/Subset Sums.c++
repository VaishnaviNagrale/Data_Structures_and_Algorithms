class Solution {
  public:
    void solve(int idx,vector<int>& arr,int sum,vector<int>& ans){
        if(idx>=arr.size()){
            ans.push_back(sum);
            return;
        }
        solve(idx+1,arr,sum+arr[idx],ans);
        solve(idx+1,arr,sum,ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>ans;
        int sum=0;
        solve(0,arr,sum,ans);
        return ans;
    }
};