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

    static bool TestSolution(vector<string> func, vector<string> inputs, vector<bool> sol);
    static bool TestSolution();
private :
    // you don't even need to store a character in the node, the character is stored in the hashmap entry
    bool isWord = false;
    unordered_map<char, Trie*> tries;
};
