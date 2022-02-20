#pragma once
#include <string>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {

public:
    Trie();
    ~Trie();
    void insert(string word);

    bool search(string word);

    bool startsWith(string prefix);

private :
    //char c =  ' ';
    bool isWord = false;
    unordered_map<char, Trie*> tries;
};




class Node {

public :

    Node(char c) :
        c(c),
        isWord(false)
    {

    };

    char c;
    bool isWord = false;
    unordered_map<char, Node*> nodes;

};