#include "max_area.h"

using namespace std;

int maxArea(std::vector<int>& height)
{
	int left = 0;
	int right = height.size() - 1;
	int area = 0;
	int maxArea = 0;
	while (right - left > 0)
	{
		area = min(height[left], height[right])*(right - left);
		if (area > maxArea)
			maxArea = area;
		if (height[left] < height[right])
			left++;
		else
			right--;
	}
	return maxArea;
}
