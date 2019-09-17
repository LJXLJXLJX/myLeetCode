#include "148_sort_list.h"

using namespace std;


ListNode* merge(ListNode* head, ListNode* mid) {

	ListNode* head_new = new ListNode(0);
	ListNode* cur = head_new;
	while (head != nullptr || mid != nullptr) {
		if (head == nullptr) {
			while (mid != nullptr) {
				ListNode* tmp = mid;
				mid = mid->next;
				tmp->next = nullptr;
				cur->next = tmp;
				cur = cur->next;
			}
		}
		else if (mid == nullptr) {
			while (head != nullptr) {
				ListNode* tmp = head;
				head = head->next;
				tmp->next = nullptr;
				cur->next = tmp;
				cur = cur->next;
			}
		}
		else {
			if (head->val < mid->val) {
				ListNode* tmp = head;
				head = head->next;
				tmp->next = nullptr;
				cur->next = tmp;
				cur = cur->next;
			}
			else {
				ListNode* tmp = mid;
				mid = mid->next;
				tmp->next = nullptr;
				cur->next = tmp;
				cur = cur->next;
			}
		}
	}
	ListNode* tmp = head_new;
	head_new = head_new->next;
	delete tmp;
	return head_new;
}


ListNode * sortList(ListNode * head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next != nullptr && fast->next->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* mid = slow->next;
	slow->next = nullptr;

	return merge(sortList(head), sortList(mid));
}
