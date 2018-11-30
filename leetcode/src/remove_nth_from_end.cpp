#include "remove_nth_from_end.h"

ListNode * removeNthFromEnd(ListNode * head, int n)
{
	ListNode* current = new ListNode(0);
	current->next = head;
	ListNode* reference = current;
	while (n--)
	{
		reference = reference->next;
		if (!reference)
			return head;
	}
	while (reference->next)
	{
		reference = reference->next;
		current = current->next;
	}
	if (current->next == head)
		head = head->next;
	else
		current->next = current->next->next;
	return head;
}
