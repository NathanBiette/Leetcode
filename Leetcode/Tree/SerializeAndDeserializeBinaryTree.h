#pragma once
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    static void FillVector(TreeNode* root, vector<int>& flatTree, int& currentIndex);

    static TreeNode* ReconstructTree(vector<int>& flatTree, int currentIndex);

    // Encodes a tree to a single string.
    static string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    static TreeNode* deserialize(string data);

    static bool TestSolution();


};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));