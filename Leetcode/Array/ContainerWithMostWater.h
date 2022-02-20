#pragma once
#include <vector>
using namespace std;

// https://leetcode.com/problems/container-with-most-water/
class ContainerWithMostWater {
public:
    // Total water trapped
    static int MaxArea(vector<int>& height);
    // Biggest container 
    static int MaxArea2(vector<int>& height);
    // Test case
    static bool TestSolution();
    // Solution
    static int Solution(vector<int>& height) { return MaxArea2(height); }
};