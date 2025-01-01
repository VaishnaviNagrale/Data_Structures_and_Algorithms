class Solution {
public:
    string rotate(string s,int d){
        reverse(s.begin(),s.begin()+d);
        reverse(s.begin()+d,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
        bool rotateString(string s, string goal) {
            if(s.size()!=goal.size()){
                return false;
            }
        for(int i=0;i<s.size();i++){
            string r=rotate(s,i);
             if(goal==r){
                 return true;
             }
        }
            return false;
    }
};