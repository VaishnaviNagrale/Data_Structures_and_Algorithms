class Node{
    public:
    Node* links[2];

    Node(){
        for(int i=0;i<2;i++){
            links[i] = NULL;
        }
    }

    bool containKey(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMaximum(int num){
        Node* node = root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containKey(1-bit)){
               node = node->get(bit);
            }else{
                maxi = maxi | (1<<i);
                node = node->get(1-bit);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0;i<nums.size();++i){
            trie.insert(nums[i]);
        }
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,trie.getMaximum(nums[i]));
        }
        return maxi;
    }
};