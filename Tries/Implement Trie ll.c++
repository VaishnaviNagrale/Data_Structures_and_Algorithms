#include <bits/stdc++.h> 

class Node{
public:
    Node* links[26];
    int ew;
    int cp;
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        cp=0;
        ew=0;
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
    void increaseEnd(){
        ew++;
    }
    void increasePrefix(){
        cp++;
    }
    void deleteEnd(){
        ew--;
    }
    void reducePrefix(){
        cp--;
    }
    int getEnd(){
        return ew;
    }
    int getPrefix(){
        return cp;
    }
};
class Trie {
    Node* root;
public:
    Trie() { 
        root = new Node();
    }

    void insert(string& word) {
        int n = word.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string& word) {
        int n = word.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &prefix) {
        int n = prefix.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(node->containKey(prefix[i])){
                node = node->get(prefix[i]);
            }else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string& word) {
        int n = word.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }else{
                return;
            }
        }
        node->deleteEnd();
    }

};
