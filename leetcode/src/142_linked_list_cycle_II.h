#pragma once

#include "heads.h"
#include "data_structures.h"

ListNode *detectCycle(ListNode *head) {
	if (head == nullptr)
		return nullptr;
	ListNode* fast = head;
	ListNode* slow = head;
	while (1) {
		if (slow->next == nullptr)
			return nullptr;
		else
			slow = slow->next;

		if (fast->next == nullptr || fast->next->next == nullptr)
			return nullptr;
		else
			fast = fast->next->next;

		if (fast == slow)
			break;
	}
	int len = 1;
	fast = fast->next;
	while (fast != slow) {
		fast = fast->next;
		len++;
	}
	slow = head;
	while (slow != fast) {
		slow = slow->next;
		for (int i = 0; i < len; ++i) {
			fast = fast->next;
			if (slow == fast)
				return slow;
		}
	}
	return slow;
}