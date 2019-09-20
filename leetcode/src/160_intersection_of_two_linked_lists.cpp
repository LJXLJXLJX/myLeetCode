#include "160_intersection_of_two_linked_lists.h"

ListNode * getIntersectionNode(ListNode * headA, ListNode * headB)
{
	if (headA == nullptr || headB == nullptr)
		return nullptr;
	int len_a = 1;
	int len_b = 1;
	ListNode* cur = headA;
	while (cur->next != nullptr) {
		len_a++;
		cur = cur->next;
	}
	cur = headB;
	while (cur->next != nullptr) {
		len_b++;
		cur = cur->next;
	}

	int diff = abs(len_a - len_b);

	ListNode* ll;
	ListNode* sl;

	if (len_a < len_b) {
		ll = headB;
		sl = headA;
	}
	else {
		ll = headA;
		sl = headB;
	}

	for (int i = 0; i < diff; ++i) {
		ll = ll->next;
	}

	while (sl != ll) {
		sl = sl->next;
		ll = ll->next;
	}

	return sl;
}
