#include "rotate_right.h"

using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
	ListNode* temp(head);
	ListNode* tail = nullptr;
	int len = 0;
	while (temp != NULL)
	{
		if (temp != NULL && temp->next == NULL)
			tail = temp;
		++len;
		temp = temp->next;
	}
	if (len <= 1)
		return head;
	tail->next = head;

	k %= len;
	temp = head;
	for (int i = 1; i < len - k; ++i)
		temp = temp->next;
	head = temp->next;
	temp->next = NULL;
	return head;
}