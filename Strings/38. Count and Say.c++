class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s = countAndSay(n-1);
        cout<<s;
        vector<pair<char,int>>mp;
        int cnt=1;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && s[i]==s[i+1]){
                cnt++;
            }else{
                mp.push_back({s[i],cnt});
                cnt=1;
            }
        }
        string ans = "";
        for(auto it:mp){
            ans += ( to_string(it.second) + it.first);
        }
        mp.clear();
        return ans;
    }
};