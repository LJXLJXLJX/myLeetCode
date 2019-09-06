#include "680_valid_palindrome_II.h"

bool validPalindrome(std::string s)
{
	int head = 0;
	int tail = s.size() - 1;
	bool is_palindrome = true;
	while (head < tail) {
		if (s[head] == s[tail]) {
			head++;
			tail--;
		}
		else {
			is_palindrome = false;
			break;
		}
	}
	if (is_palindrome)
		return true;

	bool is_palindrome1 = true;
	int head1 = head + 1;
	int tail1 = tail;
	while (head1 < tail) {
		if (s[head1] == s[tail1]) {
			head1++;
			tail1--;
		}
		else {
			is_palindrome1 = false;
			break;
		}
	}

	bool is_palindrome2 = true;
	int head2 = head;
	int tail2 = tail - 1;
	while (head2 < tail2) {
		if (s[head2] == s[tail2]) {
			head2++;
			tail2--;
		}
		else {
			is_palindrome2 = false;
			break;
		}
	}


	return is_palindrome1 || is_palindrome2;
}
