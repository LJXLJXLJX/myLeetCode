#include "data_structures.h"
#include <sstream>

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

void trimLeftTrailingSpaces(std::string & input)
{
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(std::string & input)
{
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}



TreeNode * stringToTreeNode(std::string input)
{
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}