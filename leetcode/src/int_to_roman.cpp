#include "int_to_roman.h"

using namespace std;

std::string intToRoman(int num)
{
	int thousands = num / 1000;
	int hundreds = (num % 1000) / 100;
	int tens = (num % 1000 % 100) / 10;
	int digits = num % 1000 % 100 % 10;
	string thousandStr(""), hundredStr(""), tenStr(""), digitStr("");
	switch (thousands)
	{
	case 0:
		break;
	case 1:
		thousandStr = "M";
		break;
	case 2:
		thousandStr = "MM";
		break;
	case 3:
		thousandStr = "MMM";
	default:
		break;
	}
	switch (hundreds)
	{
	case 0:
		break;
	case 1:
		hundredStr = "C";
		break;
	case 2:
		hundredStr = "CC";
		break;
	case 3:
		hundredStr = "CCC";
		break;
	case 4:
		hundredStr = "CD";
		break;
	case 5:
		hundredStr = "D";
		break;
	case 6:
		hundredStr = "DC";
		break;
	case 7:
		hundredStr = "DCC";
		break;
	case 8:
		hundredStr = "DCCC";
		break;
	case 9:
		hundredStr = "CM";
		break;
	default:
		break;
	}
	switch (tens)
	{
	case 0:
		break;
	case 1:
		tenStr = "X";
		break;
	case 2:
		tenStr = "XX";
		break;
	case 3:
		tenStr = "XXX";
		break;
	case 4:
		tenStr = "XL";
		break;
	case 5:
		tenStr = "L";
		break;
	case 6:
		tenStr = "LX";
		break;
	case 7:
		tenStr = "LXX";
		break;
	case 8:
		tenStr = "LXXX";
		break;
	case 9:
		tenStr = "XC";
		break;
	default:
		break;
	}
	switch (digits)
	{
	case 0:
		break;
	case 1:
		digitStr = "I";
		break;
	case 2:
		digitStr = "II";
		break;
	case 3:
		digitStr = "III";
		break;
	case 4:
		digitStr = "IV";
		break;
	case 5:
		digitStr = "V";
		break;
	case 6:
		digitStr = "VI";
		break;
	case 7:
		digitStr = "VII";
		break;
	case 8:
		digitStr = "VIII";
		break;
	case 9:
		digitStr = "IX";
		break;
	default:
		break;
	}
	return thousandStr + hundredStr + tenStr + digitStr;
}
