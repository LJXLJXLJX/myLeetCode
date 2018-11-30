#include "add_two_numbers.h"

ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
	int l1Digit(l1->val), l2Digit(l2->val);
	int resultDigit((l1Digit + l2Digit) % 10);
	ListNode* result = new ListNode(resultDigit);
	ListNode* currentNode(result);
	int carry((l1Digit + l2Digit) / 10);
	l1 = l1->next;
	l2 = l2->next;
	while (1)
	{
		if (l1 == NULL && l2 == NULL && carry == 0)
			break;
		if (l1 == NULL)
			l1Digit = 0;
		else
		{
			l1Digit = l1->val;
			l1 = l1->next;
		}

		if (l2 == NULL)
			l2Digit = 0;
		else
		{
			l2Digit = l2->val;
			l2 = l2->next;
		}
		resultDigit = (l1Digit + l2Digit + carry) % 10;
		currentNode->next = new ListNode(resultDigit);
		currentNode = currentNode->next;
		carry = (l1Digit + l2Digit + carry) / 10;
	}
	return result;
}
