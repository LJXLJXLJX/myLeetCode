#include "roman_to_int.h"

int romanToInt(std::string s)
{
	int thousands = 0, hundreds = 0, tens = 0, digits = 0;
	int index = 0;
	int count = 0;
	while (s.find('M') != -1)
	{
		index = s.find('M');
		if (index != -1)
		{
			if (index == 0)
			{
				count = 0;
				while (s.front() == 'M')
				{
					s.erase(s.begin());
					count++;
				}
				thousands = count;
			}
			else
			{
				hundreds = 9;
				s.erase(s.begin(), s.begin() + 2);
			}
		}
	}
	//D substr
	index = s.find('D');
	if (index != -1)
	{
		if (index == 0)
		{
			s.erase(s.begin());
			count = 0;
			while (s.front() == 'C')
			{
				s.erase(s.begin());
				count++;
			}
			hundreds = 5 + count;
		}
		else
		{
			hundreds = 4;
			s.erase(s.begin(), s.begin() + 2);
		}
	}

	//C substr
	while (s.find('C') != -1)
	{
		index = s.find('C');
		if (index != -1)
		{
			if (index == 0)
			{
				count = 0;
				while (s.front() == 'C')
				{
					s.erase(s.begin());
					count++;
				}
				hundreds = count;
			}
			else
			{
				tens = 9;
				s.erase(s.begin(), s.begin() + 2);
			}
		}
	}

	//L substr
	index = s.find('L');
	if (index != -1)
	{
		if (index == 0)
		{
			s.erase(s.begin());
			count = 0;
			while (s.front() == 'X')
			{
				s.erase(s.begin());
				count++;
			}
			tens = 5 + count;
		}
		else
		{
			tens = 4;
			s.erase(s.begin(), s.begin() + 2);
		}
	}

	//X substr
	while (s.find('X') != -1)
	{
		index = s.find('X');
		if (index != -1)
		{
			if (index == 0)
			{
				count = 0;
				while (s.front() == 'X')
				{
					s.erase(s.begin());
					count++;
				}
				tens = count;
			}
			else
			{
				digits = 9;
				s.erase(s.begin(), s.begin() + 2);
			}
		}
	}

	//V substr
	index = s.find('V');
	if (index != -1)
	{
		if (index == 0)
		{
			s.erase(s.begin());
			count = 0;
			while (!s.empty())
			{
				s.pop_back();
				count++;
			}
			digits = 5 + count;
		}
		else
		{
			digits = 4;
			s.erase(s.begin(), s.begin() + 2);
		}
	}

	//I substr
	index = s.find('I');
	if (index != -1)
	{
		count = 0;
		while (!s.empty())
		{
			s.pop_back();
			count++;
		}
		digits = count;
	}
	return thousands * 1000 + hundreds * 100 + tens * 10 + digits;
}
