//
// Created by ljx on 19-1-30.
//

#include "string_without_AAA_or_BBB.h"

using namespace std;



/*
 * use list , need extra space.
 */
std::string strWithout3a3b(int A, int B) {
    list<char> lst;
    int bigNum = A >= B ? A : B;
    int smallNum = A < B ? A : B;
    char charBig = A >= B ? 'a' : 'b';
    char charSmall = A < B ? 'a' : 'b';
    for (int i = 0; i < bigNum; ++i)
        lst.push_back(charBig);
    auto lstIt = lst.begin();
    for (int i = 0; i < bigNum / 2; ++i) {
        ++++lstIt;
        if(smallNum<=0)
            break;
        lst.insert(lstIt,charSmall);
        smallNum--;
    }
    lstIt=++lst.begin();
    while(smallNum-->0){
        lst.insert(lstIt,charSmall);
        ++++++lstIt;
    }
    string ret;
    for(lstIt=lst.begin();lstIt!=lst.end();++lstIt)
        ret.push_back(*lstIt);

    return ret;
}

/*
 * leetcode 100% elegant.
 *
 * 让多的先开始多搞，每次上两个，当数量不再多时就每次只上一个
 */

//string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
//    if (A < B)
//        return strWithout3a3b(B, A, b, a, res);
//
//    auto updateResStr = [](string& res, int& Val, char& cur) {
//        res += cur;
//        Val--;
//    };
//    while (A > 0 || B > 0) {
//        if (A > 0)
//            updateResStr(res, A, a);
//        if (A > B)
//            updateResStr(res, A, a);
//        if (B > 0)
//            updateResStr(res, B, b);
//    }
//
//    return res;
//}