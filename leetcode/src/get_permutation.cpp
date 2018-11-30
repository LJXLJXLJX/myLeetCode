#include "get_permutation.h"

using namespace std;

string getPermutation(int n, int k) {
	vector<string> table;
	string res = "";
	for (int i = 1; i <= n; ++i)
		table.push_back(to_string(i));
	while (!table.empty())
	{
		int fac = factorial(n - 1);
		int t = k / fac;
		if (t*fac < k)
		{
			k -= (t * fac);
			++t;
			res += table[t - 1];
			table.erase(table.begin() + t - 1);
			--n;
		}
		else if (t*fac == k)
		{
			res += table[t - 1];
			table.erase(table.begin() + t - 1);
			while (!table.empty())
			{
				res += table.back();
				table.pop_back();
			}
		}
	}
	return res;
}