#include <bits/stdc++.h> 
class Node{
    public:
    Node* links[26];
    bool flag;

    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        flag = false;
    }

    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool prefixExists(string word) {
        int n = word.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
               if(node->isEnd() == false){
                   return false;
               } 
            }else{
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
   Trie trie;
   for(auto it:a){
       trie.insert(it);
   }
   string longest = "";
   for(auto it:a){
       if(trie.prefixExists(it)){
           if(it.length() > longest.length()){
               longest = it;
           }
           else if(it.length() == longest.length() && it<longest){
               longest = it;
           }
       }
   }
   return (longest.length()==0) ? "None" : longest;
}