class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans;
        sort(strs.begin(),strs.end());
        string s1=strs[0],s2=strs[n-1];
        int n1=s1.size(), n2=s2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(s1[i]==s2[j]){
                ans+=s1[i];
                i++;
                j++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};