#include "unique_paths.h"

using namespace std;

//简单的排列问题
int uniquePaths(int m, int n) {
	if (m <= 1 && n <= 1)
		return 0;
	int rightSteps = m - 1;		//right steps needed
	int downSteps = n - 1;		//down steps needed
	int allSteps = m + n - 2;	//all steps needed
	int temp = min(downSteps, rightSteps);
	long long numerator = 1;
	long long denominator = 1;
	for (int i = allSteps; i > allSteps - temp; --i)
		numerator *= i;
	for (int i = temp; i > 0; --i)
		denominator *= i;
	return numerator / denominator;
}