#include "MaximumSubArray.h"

int MaximumSubArray::maxSubArray(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return INT_MIN;
	}

	int currentBestSum = INT_MIN;
	int indexOfLowestSum = -1;

	for (int i = 0; i < nums.size() ; ++i)
	{
		if (i > 0)
		{
			nums[i] += nums[i - 1];
		}
		if (indexOfLowestSum < 0)
		{
			if (currentBestSum < nums[i])
			{
				currentBestSum = nums[i];
			}
			if (nums[i] < 0)
			{
				indexOfLowestSum = i;
			}
		}
		else
		{
			if (currentBestSum < nums[i] - nums[indexOfLowestSum])
			{
				currentBestSum = nums[i] - nums[indexOfLowestSum];
			}
			if (nums[i] < nums[indexOfLowestSum])
			{
				indexOfLowestSum = i;
			}
		}
	}

	return currentBestSum;
}