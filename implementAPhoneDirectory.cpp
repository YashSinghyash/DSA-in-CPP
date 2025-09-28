#include <iostream>
#include <vector>
#include <string>
using namespace std;



class TrieNode{
    public:
        char data;
        TrieNode* children [26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for (int i = 0 ; i < 26 ; i++){
                children[i] = NULL;

            }
            isTerminal = false;
        }
};


class trie{
    public:
    TrieNode* root;
    trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if (word.length() == 0 ) {
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if (root->children[index] != NULL){
            child = root->children[index];

        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child , word.substr(1));

    }


    void insertWord(string word){
        insertUtil(root, word);
    }
    
    
    void prints(TrieNode*curr , vector<string>&temp , string prefix){
        if (curr->isTerminal == true){
            temp.push_back(prefix);
        }
        
        for (char ch ='a' ; ch <='z' ; ch++){
            TrieNode* next = curr->children[ch-'a'];
            
            if (next){
                prefix.push_back(ch);
                prints(next , temp , prefix );
                prefix.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev = root;
        vector <vector<string>> output;
        string prefix = "";
        
        for (int i = 0 ; i < str.length() ; i++){
            if (!prev){
                vector<string> temp = {"0"};
                output.push_back(temp);
                continue;
            }
            char last = str[i];
            prefix.push_back(last);
            
            TrieNode* curr = prev->children[last-'a'];
            if (!curr){
                vector<string> temp = {"0"};
                output.push_back(temp);
                prev = NULL;
                continue;
            }
            
            vector<string > temp;
            prints(curr, temp , prefix);
            output.push_back(temp);
            prev = curr;
            
        }
        
        return output;
        
        
        
    }



};




class Solution {
  public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        trie *t = new trie();
        
        
        for (int i = 0 ; i < n ; i++){
            string str = contact[i];
            
            t->insertWord(str);
        }
        
        
        return t->getSuggestions(s);        
    }
};