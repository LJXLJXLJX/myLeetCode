#include "swap_pairs.h"

ListNode * swapPairs(ListNode * head)
{
	ListNode* tmp = head;
	ListNode* res = head;
	if (res && (res->next))
		res = res->next;
	ListNode* prePairTail = NULL;
	while (head)
	{
		if (head->next == NULL)
			break;
		tmp = head;
		head = head->next;
		if (prePairTail != NULL)
			prePairTail->next = head;

		tmp->next = head->next;
		head->next = tmp;

		head = tmp->next;
		prePairTail = tmp;
	}
	return res;
}
