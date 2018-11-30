#include "merge_k_lists.h"

using namespace std;

ListNode * mergeKLists(std::vector<ListNode*>& lists)
{
	ListNode *preRes = new ListNode(0);
	ListNode *current = preRes;
	int numOFList = lists.size();
	int minVal = INT_MAX;
	int index = 0;	//链表的索引（第几个链表）
	for (int i = 0; i < numOFList; i++)
	{
		if (lists[i] == NULL)
		{
			if (i == numOFList - 1)
				lists.pop_back();
			else
			{
				swap(lists[i], lists[numOFList - 1]);
				lists.pop_back();
			}
			numOFList--;
			i--;
		}
	}
	while (numOFList > 0)
	{
		index = 0;
		minVal = INT_MAX;
		for (int i = 0; i < numOFList; i++)
		{
			if (lists[i]->val < minVal)
			{
				minVal = lists[i]->val;
				index = i;
			}
		}
		current->next = lists[index];
		current = current->next;
		lists[index] = lists[index]->next;
		if (lists[index] == NULL)
		{
			swap(lists[index], lists[numOFList - 1]);
			lists.pop_back();
			numOFList--;
		}
	}
	return preRes->next;
}
