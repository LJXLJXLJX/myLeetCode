#pragma once
#include "heads.h"
#include "data_structures.h"


ListNode* partition(ListNode* head, int x) {
	if (head == nullptr)
		return head;
	ListNode* smallHead = nullptr;
	ListNode* bigHead = nullptr;
	ListNode* smallCur = smallHead;
	ListNode* bigCur = bigHead;
	ListNode* cur = head;
	while (cur != nullptr) {
		if (cur->val < x) {
			if (smallHead == nullptr) {
				smallHead = cur;
				smallCur = cur;
			}
			else {
				smallCur->next = cur;
				smallCur = smallCur->next;
			}
		}
		else {
			if (bigHead == nullptr) {
				bigHead = cur;
				bigCur = cur;
			}
			else {
				bigCur->next = cur;
				bigCur = bigCur->next;
			}
		}
		ListNode* tmp = cur;
		cur = cur->next;
		tmp->next = nullptr;
	}
	if (smallHead != nullptr)
		smallCur->next = bigHead;
	else
		smallHead = bigHead;
	return smallHead;
}

