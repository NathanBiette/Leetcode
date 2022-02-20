#include "ContainerWithMostWater.h"

// return the water maximally conatained into the whole set of containers
int ContainerWithMostWater::MaxArea(vector<int>& height)
{
	int totalArea = 0;
	int max = height[0];
	int maxIndex = 0;

	// Sum all the left limited containers
	for (int i = 1; i < height.size(); ++i)
	{
		if (max <= height[i])
		{
			totalArea += (i - maxIndex) * max;
			max = height[i];
			maxIndex = i;
		}
	}

	int currentMaxIndex = height.size() - 1;
	int currentMax = height[height.size() - 1];

	// Sum all the right limited containers
	for (int i = height.size() - 1; i >= maxIndex; i--)
	{
		if (currentMax < height[i])
		{
			totalArea += (currentMaxIndex - i) * currentMax;
			currentMax = height[i];
			currentMaxIndex = i;
		}
	}

	return totalArea;
}

int ContainerWithMostWater::MaxArea2(vector<int>& height)
{
	int maxTotalArea = 0;
	int max = height[0];
	int maxIndex = 0;

	// Sum all the left limited containers
	for (int i = 1; i < height.size(); ++i)
	{
		int currentArea = (i - maxIndex) * min(max, height[i]);
		if (maxTotalArea < currentArea)
		{
			maxTotalArea = currentArea;
		}

		if (max < height[i])
		{
			max = height[i];
			maxIndex = i;
		}
	}

	return maxTotalArea;
}

bool ContainerWithMostWater::TestSolution()
{
	vector<int> v = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	return ContainerWithMostWater::Solution(v) == 49;
}