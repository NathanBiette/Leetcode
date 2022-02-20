#pragma once
#include <string>
using namespace std;

// https://leetcode.com/problems/palindromic-substrings/
class PalindromicSubstrings {
public: 

    static int countSubstrings(string s);
    static int countSubstrings2(string s);
    static bool isPalindrome(string s);
    // Test case
    static bool TestSolution();
    // Solution
    static int Solution(string s) { return countSubstrings2(s); }
};