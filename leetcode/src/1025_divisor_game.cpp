#include "1025_divisor_game.h"


using namespace std;



bool divisorGame(int N)
{
	vector<int>arr(N+1);
	arr[1] = 0;
	for (int i = 2; i <= N; ++i) {
		for (int j = i / 2; j < i; ++j) {
			if (arr[j] == 1)
				continue;
			else {
				int diff = i - j;
				if (i%diff == 0) {
					arr[i] = 1;
					break;
				}
			}
		}
	}
	return arr.back();
}
