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
			maxIndex = 0;	//maxIndex��max���Ǿֲ��� ��head��λʱӦ����λ
		}
		else
		{
			if (height[tail] >= max && (tail - head) > 1)
			{
				max = height[tail];
				maxIndex = tail;
			}

			if (tail == height.size() - 1)	//�����Ҳû�ҵ���head��� �ص�ǰ������ �ز�ȥ�Ļ�ֱ�ӽ���
			{
				if (maxIndex == 0)
					return water;
				if (maxIndex > head)	//head������maxIndex�� �Ͳ��ܻ�ȥ��
					tail = maxIndex;
				for (int i = head + 1; i < tail; i++)
					water += std::max(0, (height[tail] - height[i]));
				head = tail;
				max = 0;
				maxIndex = 0;	//maxIndex��max���Ǿֲ��� ��head��λʱӦ����λ
			}
		}
	}
	return water;
}
