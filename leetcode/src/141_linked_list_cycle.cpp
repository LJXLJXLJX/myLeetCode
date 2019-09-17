#include "141_linked_list_cycle.h"

bool hasCycle(ListNode * head)
{
	if (head == nullptr)
		return false;
	ListNode* fast = head;
	ListNode* slow = head;
	while (1) {
		if (slow->next == nullptr)
			return false;
		else
			slow = slow->next;

		if (fast->next == nullptr || fast->next->next == nullptr)
			return false;
		else
			fast = fast->next->next;

		if (fast == slow)
			return true;
	}

	return false;
}
