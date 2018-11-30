#include "simplify_path.h"

using namespace std;
string simplifyPath(string path) {
	vector<string> pathVec;
	if (path.front() != '/')
		path = "/" + path;
	if (path.back() != '/')
		path.push_back('/');
	int i = 0;
	while (path[i] == '/')
		++i;
	int head = i;
	for (i; i < path.size(); ++i)
	{
		if (path[i] == '/')
		{
			int len = i - head;
			string section(path, head, len);
			pathVec.push_back(section);
			if (path[i + 1] == '/')
				++i;
			while (path[i] == '/')
				++i;
			head = i;
		}
	}
	vector<string> simplifiedVec;
	for (string section : pathVec)
	{
		if (section == ".")
			continue;
		else if (section == "..")
		{
			if (!simplifiedVec.empty())
				simplifiedVec.pop_back();
		}
		else
			simplifiedVec.push_back(section);
	}
	if (simplifiedVec.empty())
		return "/";
	string res;
	for (string section : simplifiedVec)
		res += ("/" + section);
	return res;
}
