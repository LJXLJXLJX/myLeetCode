#include "merge_two_lists.h"

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2)
{
	ListNode* res = new ListNode(0);
	ListNode* current = res;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			current->next = l1;
			//current->next = new ListNode(l1->val);
			l1 = l1->next;
		}
		else
		{
			current->next = l2;
			//current->next = new ListNode(l2->val);
			l2 = l2->next;
		}
		current = current->next;
	}
	if (l1 != NULL)
		current->next = l1;
	else
		current->next = l2;
	return res->next;
}
