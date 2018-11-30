#include "utils.h"

//Çó½×³Ë
int factorial(int n)
{
	int res = 1;
	if (n == 0)
		return res;
	for (int i = n; i > 0; i--)
		res *= i;
	return res;
}
