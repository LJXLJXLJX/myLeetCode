#include "data_structures.h"


using namespace std;

ListNode::ListNode(int x) : val(x), next(NULL) {}

ListNode::ListNode(std::vector<int> vec)
{
	if (vec.empty())
		throw("vector can't be empty!");
	ListNode* head = new ListNode(vec[0]);
	ListNode* index = head;
	for (int i = 1; i < vec.size(); ++i)
	{
		index->next = new ListNode(vec[i]);
		index = index->next;
	}
	index = NULL;
	this->val = head->val;
	this->next = head->next;
}


void ListNode::push_back(int x)
{
	ListNode* current = this;
	if (current == NULL)
		current = new ListNode(x);
	else while (current->next)
		current = current->next;
	current->next = new ListNode(x);
}

void ListNode::print()
{
	if (this == NULL)
	{
		return;
	}
	cout << val;
	if (next != NULL)
	{
		cout << "->";
		next->print();
	}
	if (next == NULL)
		cout << endl;
}


bool compareIntervals(const Interval &a, const Interval &b)
{
	if (a.start < b.start)
		return true;
	else if (a.start > b.start)
		return false;
	else if (a.end < b.end)
		return true;
	else
		return false;
}

void prettyPrintTree(TreeNode * node, string prefix, bool isLeft)
{
	if (node == nullptr) {
		cout << "Empty tree";
		return;
	}

	if (node->right) {
		prettyPrintTree(node->right, prefix + (isLeft ? "©¦   " : "    "), false);
	}

	cout << prefix + (isLeft ? "©¸©¤©¤ " : "©°©¤©¤ ") + to_string(node->val) + "\n";

	if (node->left) {
		prettyPrintTree(node->left, prefix + (isLeft ? "    " : "©¦   "), true);
	}
}