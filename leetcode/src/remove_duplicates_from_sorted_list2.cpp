#include "remove_duplicates_from_sorted_list2.h"

ListNode * deleteDuplicates2(ListNode * head)
{
	if (head == NULL)
		return NULL;
	ListNode* mark = head->val != INT_MIN ? new ListNode(INT_MIN) : new ListNode(INT_MIN + 1);
	mark->next = head;
	ListNode* indexHead = mark;
	ListNode* indexTail = indexHead;
	while (indexTail->next != NULL)
	{
		if (indexTail->next->val != indexTail->val &&
			(indexTail->next->next == NULL || indexTail->next->val != indexTail->next->next->val)
			)
		{
			indexHead->next = indexTail->next;
			indexHead = indexHead->next;
			indexTail = indexHead;
			continue;
		}
		indexTail = indexTail->next;
	}
	indexHead->next = NULL;
	return mark->next;
}
