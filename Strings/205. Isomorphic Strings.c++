class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        map<char,int>mp1;
        map<char,int>mp2;
        for(auto x:s){
            if(mp1.count(x)!=0){
                continue;
            }
            mp1[x] = mp1.size();
        }
        for(auto x:t){
            if(mp2.count(x)!=0){
                continue;
            }
            mp2[x] = mp2.size();
        }
        if(mp1.size()!=mp2.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(mp1[s[i]]!=mp2[t[i]]){
                return false;
            }
        }
        return true;
    }
};