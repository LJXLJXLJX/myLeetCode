#include "547_friend_circles.h"


using namespace std;

int findRoot(vector<int>& f, int v) {
	while (v != f[v])  v = f[v];
	return v;
}


int findCircleNum(std::vector<std::vector<int>>& M)
{
	vector<int> f(M.size(), -1);
	for (int i = 0; i < M.size(); ++i)
		f[i] = i;

	int group = M.size();

	for (int i = 0; i < M.size(); ++i) {
		for (int j = i + 1; j < M.size(); ++j) {
			if (M[i][j] == 1) {
				int fi = findRoot(f, i);
				int fj = findRoot(f, j);
				if (fi != fj) {
					f[fi] = fj;
					group--;
				}
			}
		}
	}
	return group;
}
