class Solution{
public:
    void insert(stack<int>& St,int ele){
        if(St.size()==0){
            St.push(ele);
            return;
        }
        int temp = St.top();
        St.pop();
        insert(St,ele);
        St.push(temp);
    }
    void Reverse(stack<int> &St){
        if(St.size()<=1){
            return;
        }
        int top = St.top();
        St.pop();
        Reverse(St);
        insert(St,top);
        return;
    }
};