#include "reverse_k_group.h"

using namespace std;

ListNode * reverseKGroup(ListNode * head, int k)
{
	ListNode* res = head;
	vector<ListNode*> temp;
	if (k == 1)
		return head;
	temp = {};
	int i = k;
	while (i-- && head)
	{
		temp.push_back(head);
		head = head->next;
	}
	if (temp.size() == k)
	{
		res = temp[k - 1];
		for (int i = k - 1; i > 0; i--)
			temp[i]->next = temp[i - 1];
	}
	else
		return res;
	temp[0]->next = reverseKGroup(head, k);
	return res;
}
