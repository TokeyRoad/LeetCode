//************************************
//	file：LongestPalindrome.h
//  author：Tokey
//  date：2019/07/02
//************************************

/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

*/

#pragma once
#include "head.h"

class ZNConvert{
public:
	string convert(string s, int numRows) {
		if (s.length() <= numRows || numRows == 1) {
			return s;
		}
		string ret;
		int lineCount = s.length() / (numRows - 1);
		int retCount = s.length() % (numRows - 1);
		for (int i = 0; i < numRows; i++) {
			int curLine = 0;
			if (lineCount % 2 == 0) {	//偶数
				if (i == 0 || i == numRows - 1) {
					curLine = lineCount / 2;
				}
				else {
					curLine = lineCount;
				}
				if (i < retCount) {
					curLine += 1;
				}
			}
			else {						//奇数
				if (i == 0) {
					curLine = (lineCount + 1) / 2 ;
				}
				else if (i == numRows - 1) {
					curLine = (lineCount - 1) / 2;
				}
				else {
					curLine = lineCount;
				}
				if (i >= numRows - retCount) {
					curLine++;
				}
			}
			string lineRet;
			for (int j = 0; j < curLine; j++) {
				if (i == 0 || i == numRows - 1) {
					lineRet.push_back(s[(numRows - 1) * j * 2 + i]);
				}
				else {
					if (j % 2 == 0) {
						lineRet.push_back(s[(numRows - 1) * j + i]);
					}
					else {
						lineRet.push_back(s[(numRows - 1) * j + (numRows - 1 - i)]);
					}
				}
			}
			cout << i << ":" << lineRet.c_str() << endl;
			ret.append(lineRet);
		}
		return ret;
	}
};