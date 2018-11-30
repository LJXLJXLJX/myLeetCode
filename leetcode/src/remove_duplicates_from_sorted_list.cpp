#include "remove_duplicates_from_sorted_list.h"

ListNode * deleteDuplicates(ListNode * head)
{
	ListNode* indexHead = head;
	ListNode* indexTail = head;
	while (indexHead != NULL)
	{
		indexTail = indexHead->next;
		while (indexTail != NULL && indexTail->val == indexHead->val)
			indexTail = indexTail->next;
		indexHead->next = indexTail;
		indexHead = indexTail;
	}
	return head;
}
