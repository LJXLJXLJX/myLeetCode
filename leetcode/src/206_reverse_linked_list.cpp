#include "206_reverse_linked_list.h"


ListNode * reverseList(ListNode * head)
{
	ListNode* prev = nullptr;
	ListNode* curr = head;
	while (curr != nullptr) {
		ListNode* nextTemp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextTemp;
	}
	return prev;
}
