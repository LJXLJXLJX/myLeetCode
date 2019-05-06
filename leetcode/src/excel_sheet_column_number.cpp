#include "excel_sheet_column_number.h"


using namespace std;

int titleToNumber(std::string s)
{
	int ret = 0;
	int powNum = s.size() - 1;
	for (int i = 0; i < s.size(); ++i) {
		ret += pow(26, powNum)*static_cast<int>(s[i] - 'A' + 1);
		powNum--;
	}
	return ret;
}
