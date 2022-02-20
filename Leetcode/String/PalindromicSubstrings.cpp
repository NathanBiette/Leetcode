#include "PalindromicSubstrings.h"
#include <algorithm>
#include <iostream>

// probably can be optimized to reverse only half og the string
bool PalindromicSubstrings::isPalindrome(string s)
{
	string reversed = s;
	reverse(reversed.begin(), reversed.end());
	return reversed.compare(s) == 0;
}

int PalindromicSubstrings::countSubstrings(string s)
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j < s.size() - i + 1; j++)
		{
			if (isPalindrome(s.substr(i, j)))
			{
				//cout << s.substr(i, j) << "\n";
				count +=1;
			}
		}
	}
	return count;
}


int PalindromicSubstrings::countSubstrings2(string s)
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		// count the single letter
		count += 1;
		// even palindrome
		int currentSize = 0;
		while (i + currentSize + 1 < s.size() && i - currentSize >= 0 && s[i-currentSize] == s[i+currentSize+1])
		{
				count += 1;
				currentSize += 1;
		}

		// odd palindrome
		currentSize = 1;
		while (i + currentSize < s.size() && i - currentSize >= 0 && s[i - currentSize] == s[i + currentSize])
		{
			count += 1;
			currentSize +=1;
		}
	}
	return count;
}


