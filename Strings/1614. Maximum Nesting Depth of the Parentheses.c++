class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        if(s.size()==0){
            return ans;
        }
        int cnt = 0;
        for(auto x:s){
            if(x=='('){
                cnt++;
            }else if(x==')'){
                cnt--;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};