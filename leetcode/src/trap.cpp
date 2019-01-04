#include "trap.h"

using namespace std;

int trap(std::vector<int>& height)
{
	int len = height.size();
	if (len == 0)
		return 0;
	int water = 0;
	int head = 0;
	int max = 0;
	int maxIndex = 0;
	for (int tail = head + 1; tail <= height.size() - 1; tail++)
	{
		if (height[tail] >= height[head])
		{
			for (int i = head + 1; i < tail; i++)
				water += std::max(0, (height[head] - height[i]));
			head = tail;
			max = 0;
			maxIndex = 0;	//maxIndex和max都是局部的 当head移位时应当复位
		}
		else
		{
			if (height[tail] >= max && (tail - head) > 1)
			{
				max = height[tail];
				maxIndex = tail;
			}

			if (tail == height.size() - 1)	//到最后也没找到比head大的 回到前面最大的 回不去的话直接结束
			{
				if (maxIndex == 0)
					return water;
				if (maxIndex > head)	//head都大于maxIndex了 就不能回去了
					tail = maxIndex;
				for (int i = head + 1; i < tail; i++)
					water += std::max(0, (height[tail] - height[i]));
				head = tail;
				max = 0;
				maxIndex = 0;	//maxIndex和max都是局部的 当head移位时应当复位
			}
		}
	}
	return water;
}
