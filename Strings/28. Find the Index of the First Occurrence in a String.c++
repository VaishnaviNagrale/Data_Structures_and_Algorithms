class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        //kmp algo
        // int kmp[n+1];
        // int i=0,j=1;
        // while(i<m){
        //     if(haystack[i]==needle[j+1]){
        //         j++;
        //         kmp[i] = j;
        //         i++;
        //     }else{
        //         if(j!=0){
        //             j = kmp[j];
        //         }else{
        //             i++;
        //         }
        //     }
        // }
        // i=0,j=0;
        // while(i<n){
        //     if(haystack[i]==needle[j+1]){
        //         i++;
        //         j++;
        //         if(j==m){
        //             return i-m;
        //         }
        //     }else{
        //         if(j!=0){
        //             j = kmp[j];
        //         }else{
        //             i++;
        //         }
        //     }
        // }
        // return -1;
        //Sliding window
        int i=0,j=0;
        while(j<n){
            if(j-i+1<m){
                j++;
            }
            else if(j-i+1==m){
                string s = haystack.substr(i,m);
                if(s==needle){
                    return i;
                }else{
                    i++;
                    j++;
                }
            }
        }
        return -1;
    }
};