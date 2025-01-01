class Solution {
public:
    string frequencySort(string s) {
        map<char,int>freq;
        priority_queue<pair<int,char>,vector<pair<int,char>>>maxheap;
        
        for(auto ch:s){
            freq[ch]++;
        }
        
        for(auto &value:freq){
            maxheap.push({value.second,value.first});
        }
        string str="";
        while(!maxheap.empty()){
            
            int cnt=maxheap.top().first;
            char c=maxheap.top().second;
            
            for(int i=0;i<cnt;i++){
                str+=c;
            }
            maxheap.pop();
        }
        return str;
    }
};