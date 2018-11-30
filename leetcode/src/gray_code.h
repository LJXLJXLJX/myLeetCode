#pragma once
#include "heads.h"

/*
这题基本上没有难度 主要是得知道格雷码生成的过程和原理 

格雷码生成过程
从0开始
1.翻转最右边的位
2.翻转从右边开始 第一个1的左边的位
重复以上步骤 直到从右边开始 第一个1左边没有位

*/

std::vector<int> grayCode(int n);

