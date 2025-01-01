class Solution {
public:
    void solve(string str,int open,int close,vector<string>& ans){
        if(open==0 && close==0){
            ans.push_back(str);
            return;
        }
        if(open==close){
            str.push_back('(');
            solve(str,open-1,close,ans);
        }
        else if(open==0){
            str.push_back(')');
            solve(str,open,close-1,ans);
        }
        else if(close==0){
            str.push_back('(');
            solve(str,open-1,close,ans);
        }
        else{
            string s1=str;
            string s2=str;
            s1.push_back('(');
            s2.push_back(')');
            solve(s1,open-1,close,ans);
            solve(s2,open,close-1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open = n;
        int close = n;
        string str;
        solve(str,open,close,ans);
        return ans;
    }
};