#pragma once
#include "heads.h"


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stk.push(x);
		if (min_stk.empty())
			min_stk.push(x);
		else
			min_stk.push(std::min(x, min_stk.top()));
	}

	void pop() {
		stk.pop();
		min_stk.pop();
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return min_stk.top();
	}

	std::stack<int> stk;
	std::stack<int> min_stk;

};