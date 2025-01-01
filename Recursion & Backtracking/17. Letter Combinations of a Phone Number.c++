class Solution {
public:
    void solve(int idx,string digits,unordered_map<int,string>& mp,string& ds,vector<string>& ans){
        int n = digits.size();
        if(idx>=n){
            ans.push_back(ds);
            return;
        }
        string str = mp[digits[idx]-'0'];
        for(int i=0;i<str.size();i++){
            ds.push_back(str[i]);
            solve(idx+1,digits,mp,ds,ans);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        unordered_map<int,string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string ds = "";
        solve(0,digits,mp,ds,ans);
        return ans;
    }
};