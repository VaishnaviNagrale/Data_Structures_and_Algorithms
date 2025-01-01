class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                ans+=1;
            }else if(s[i]=='V'){
                if(i!=0 && s[i-1]=='I'){
                    ans-=1;
                    ans+=4;
                }else{
                    ans+=5;
                }
            }else if(s[i]=='X'){
                if(i!=0 && s[i-1]=='I'){
                    ans-=1;
                    ans+=9;
                }else{
                    ans+=10;
                }
            }else if(s[i]=='L'){
                if(i!=0 && s[i-1]=='X'){
                    ans-=10;
                    ans+=40;
                }else{
                    ans+=50;
                }
            }else if(s[i]=='C'){
                if(i!=0 && s[i-1]=='X'){
                    ans-=10;
                    ans+=90;
                }else{
                    ans+=100;
                }
            }else if(s[i]=='D'){
                if(i!=0 && s[i-1]=='C'){
                    ans-=100;
                    ans+=400;
                }else{
                    ans+=500;
                }
            }else if(s[i]=='M'){
                if(i!=0 && s[i-1]=='C'){
                    ans-=100;
                    ans+=900;
                }else{
                    ans+=1000;
                }
            }
        }
        return ans;
    }
};