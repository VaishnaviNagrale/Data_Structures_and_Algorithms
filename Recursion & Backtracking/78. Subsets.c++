class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        for(int num=0;num<(1<<n);num++){
            vector<int>ds;
            ds.clear();
            for(int bit=0;bit<n;bit++){
                if(num&(1<<bit)){
                    ds.push_back(nums[bit]);
                }
            }
            ans.push_back(ds);
        }
        return ans;
    }
};