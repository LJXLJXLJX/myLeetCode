#include "my_atoi.h"

int myAtoi(std::string str)
{
	int len = str.size();
	if (len == 0)
		return 0;
	long long result = 0;
	int i = 0;
	int sign = 1;
	int digit = 0;
	while (str[i] == ' ') { i++; }
	if (str[i] == '+')
	{
		sign = 1;
		i++;
	}
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i]<'0' || str[i]>'9')
		return 0;
	while (str[i] >= '0'&&str[i] <= '9')
	{
		digit = (int)(str[i] - '0');
		result = 10 * result + digit;
		if (result*sign > INT_MAX)
			return INT_MAX;
		if (result*sign < INT_MIN)
			return INT_MIN;
		i++;
	}
	result = result * sign;
	if (result > INT_MAX)
		return INT_MAX;
	else if (result < INT_MIN)
		return INT_MIN;
	else
		return result;
}
