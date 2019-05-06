#pragma once
#include "heads.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x);
	ListNode(std::vector<int> vec);
	void push_back(int x);
	void print();
};


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}

};

bool compareIntervals(const Interval &a, const Interval &b);


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void prettyPrintTree(TreeNode* node, std::string prefix = "", bool isLeft = true);

void trimLeftTrailingSpaces(std::string &input);

void trimRightTrailingSpaces(std::string &input);

TreeNode* stringToTreeNode(std::string input);