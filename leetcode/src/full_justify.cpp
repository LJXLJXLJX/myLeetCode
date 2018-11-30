#include "full_justify.h"

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> res;
	int rowLen = 0;	//ÿ�е�ǰ�����賤��
	vector<string> rowWords;	//��ǰ����������
	int i = 0;
	bool firstWord = true;
	for (i; i < words.size();)
	{
		while (rowLen <= maxWidth && i < words.size())
		{
			if (words[i].size() > maxWidth)
				throw("���ڵ��ʳ��ȴ�������г��ȣ�");
			int tempLen = rowLen;
			rowWords.push_back(words[i]);
			tempLen += words[i].size();
			if (!firstWord)
				++tempLen;	//��������ĸ �����ÿ����ĸǰ������һ���ո� ���Գ�����Ҫ��һ
			if (tempLen > maxWidth)
			{
				rowWords.pop_back();	//���ȳ��� �³���
				break;
			}
			rowLen = tempLen;
			++i;	//��һ����ĸ
			firstWord = false;
		}

		//���������while �Ѿ�ȷ����һ�� �ж����ǲ������һ��
		//�����һ����
		string row;
		if (i == words.size())
		{
			for (string word : rowWords)
				row += (word + " ");
			row.pop_back();	//�������һ���ո�
			while (row.size() < maxWidth)
				row.push_back(' ');	//ĩβ���ո�ֱ���ﵽ��󳤶�

		}
		else if (rowWords.size() != 1)
		{
			int spaceNum = maxWidth - rowLen;	//����Ŀո�����


			int	spaceNumOfEachInterval = spaceNum / (rowWords.size() - 1);	//ÿ���������Ŀո���
			int spaceNumRest = spaceNum - spaceNumOfEachInterval * (rowWords.size() - 1);	//��������������� ÿ�������ǰ�����ֱ�����꼴��
			for (int i = 0; i < rowWords.size(); ++i)
			{
				row += rowWords[i];
				if (i != rowWords.size() - 1)
				{
					row += " ";	//������еĿո�

					for (int j = spaceNumOfEachInterval; j > 0; --j)
						row.push_back(' ');	//ÿ�����ƽ���Ĳ��ֿո�
				}
				if (spaceNumRest > 0)
				{
					row.push_back(' ');	//ʣ��������ո�
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
		//�㶨һ�� �������±���
		rowLen = 0;
		rowWords.clear();
		firstWord = true;
	}
	return res;
}
