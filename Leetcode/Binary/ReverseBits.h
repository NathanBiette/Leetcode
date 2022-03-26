#pragma once
#include <stdint.h>

//https://leetcode.com/problems/reverse-bits/
class ReverseBits
{
public : 
    
    static void swap(uint32_t& input, const uint32_t p1, const uint32_t p2, const uint32_t num)
    {
        if (num == 0 || (p1 == p2) || p1 + num > 32 || p2 + num > 32 || (p1 < p2 && p1 + num - 1 >= p2) || (p2 < p1 && p2 + num - 1 >= p1))
        {
            return;
        }
        uint32_t rightP = p1 < p2 ? p1 : p2;
        uint32_t leftP = p2 > p1 ? p2 : p1;
        uint32_t toShiftLeft = input;
        uint32_t toShiftRight = input;
        toShiftLeft = (toShiftLeft >> p1) & ((1U << num) - 1);
        toShiftRight = (toShiftRight >> p2) & ((1U << num) - 1);
        uint32_t Xor = toShiftLeft ^ toShiftRight;
        Xor = (Xor << p2) | (Xor << p1);
        input = input ^ Xor;
    }

    static void reverse(uint32_t& n, const uint32_t startBit, const uint32_t num)
    {
        if (num > 1)
        {
            reverse(n, startBit, num / 2);
            reverse(n, startBit + num / 2, num / 2);
            swap(n, startBit, startBit + num / 2, num / 2);
        }
    }

    static uint32_t reverseBits(uint32_t n)
    {
        reverse(n, 0, 32);
        return n;
    }

};


// Much simpler solution > do it by hand
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};