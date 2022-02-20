#include <iostream>
#include "Array/ContainerWithMostWater.h"
#include "String/PalindromicSubstrings.h"

int main()
{
	//if(PalindromicSubstrings::isPalindrome("a"))
	//{
	//	std::cout << "Solution is palindrome \n";
	//}
	//else
	//{
	//	std::cout << "Solution is not\n";
	//}
	cout << "num palindrome " << PalindromicSubstrings::countSubstrings("aaabcdefgaba");
	cout << "num palindrome " << PalindromicSubstrings::countSubstrings2("aaabcdefgaba");
	return 0;
}