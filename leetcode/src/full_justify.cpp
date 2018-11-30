#include "full_justify.h"

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> res;
	int rowLen = 0;	//每行当前的所需长度
	vector<string> rowWords;	//当前行所含单词
	int i = 0;
	bool firstWord = true;
	for (i; i < words.size();)
	{
		while (rowLen <= maxWidth && i < words.size())
		{
			if (words[i].size() > maxWidth)
				throw("存在单词长度大于最大行长度！");
			int tempLen = rowLen;
			rowWords.push_back(words[i]);
			tempLen += words[i].size();
			if (!firstWord)
				++tempLen;	//除了首字母 后面的每个字母前面至少一个空格 所以长度需要加一
			if (tempLen > maxWidth)
			{
				rowWords.pop_back();	//长度超了 吐出来
				break;
			}
			rowLen = tempLen;
			++i;	//下一个字母
			firstWord = false;
		}

		//经过上面的while 已经确定了一行 判断它是不是最后一行
		//是最后一行了
		string row;
		if (i == words.size())
		{
			for (string word : rowWords)
				row += (word + " ");
			row.pop_back();	//弹出最后一个空格
			while (row.size() < maxWidth)
				row.push_back(' ');	//末尾补空格直到达到最大长度

		}
		else if (rowWords.size() != 1)
		{
			int spaceNum = maxWidth - rowLen;	//还差的空格数量


			int	spaceNumOfEachInterval = spaceNum / (rowWords.size() - 1);	//每个间隔插入的空格数
			int spaceNumRest = spaceNum - spaceNumOfEachInterval * (rowWords.size() - 1);	//多出来的余数部分 每个间隔从前往后插直到用完即可
			for (int i = 0; i < rowWords.size(); ++i)
			{
				row += rowWords[i];
				if (i != rowWords.size() - 1)
				{
					row += " ";	//本身就有的空格

					for (int j = spaceNumOfEachInterval; j > 0; --j)
						row.push_back(' ');	//每个间隔平均的部分空格
				}
				if (spaceNumRest > 0)
				{
					row.push_back(' ');	//剩余的余数空格
					--spaceNumRest;
				}
			}
		}
		else
		{
			row += rowWords[0];
			while (row.size() != maxWidth)
				row.push_back(' ');
		}
		res.push_back(row);
		//搞定一行 重置以下变量
		rowLen = 0;
		rowWords.clear();
		firstWord = true;
	}
	return res;
}
