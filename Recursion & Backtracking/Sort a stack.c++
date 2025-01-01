void insertSortedWay(stack<int>& s,int ele){
    if(s.size()==0 || s.top()<=ele){
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    insertSortedWay(s,ele);
    s.push(temp);
}
void SortedStack :: sort()
{
    if(s.size()<=1){
        return;
    }  
    int ele = s.top();
    s.pop();
    sort();
    insertSortedWay(s,ele);
    return;
}