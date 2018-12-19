#include "restore_ip_addresses.h"

using namespace std;

bool isSegValid(std::string& seg)
{
	if (seg.front() == '1')
		return true;
	if (seg.front() == '2' && seg[1] < '5')
		return true;
	if (seg.front() == '2'&& seg[1] == '5'&& seg[2] <= '5')
		return true;
	return false;
}

void ipAddressesRecur(std::string& s, std::string curS, int index, int remainBytes, std::vector<std::string>& out)
{
	if (remainBytes < 0)
		return;
	int remainLen = s.size() - index;
	if (remainLen<remainBytes || remainLen>remainBytes * 4)
		return;
	if (index > s.size())
		return;
	if (index == s.size() && remainBytes == 0) {
		curS.pop_back();	//µ¯³öµã
		out.push_back(curS);
		return;
	}
	ipAddressesRecur(s, curS + s[index] + ".", index + 1, remainBytes - 1, out);
	if (s[index] == '0')
		return;
	ipAddressesRecur(s, curS + s.substr(index, 2) + ".", index + 2, remainBytes - 1, out);
	string seg = s.substr(index, 3);
	if (isSegValid(seg))
		ipAddressesRecur(s, curS + seg + ".", index + 3, remainBytes - 1, out);
}

std::vector<std::string> restoreIpAddresses(std::string s)
{
	vector<string> ret;
	string curS;
	ipAddressesRecur(s, curS, 0, 4, ret);
	return ret;
}
