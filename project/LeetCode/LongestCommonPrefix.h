//************************************
//	file：LongestCommonPrefix.h
//  author：Tokey
//  date：2019/07/03
//************************************

/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
*/

#pragma once
#include "head.h"

class LongestCommonPrefix {
public:
	void Cmp(string & ret, string target) {
		for (int i = ret.length() - 1; i > 0; i--) {
			ret = ret.substr(0, i+1);
			if (target.find(ret) == 0) {
				return;
			}
		}
		ret = "";
	}
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) {
			return "";
		}
		if (strs.size() == 1) {
			return strs[0];
		}
		::sort(strs.begin(), strs.end());
		string ret(strs[0]);
		for (int i = 1; i < strs.size(); i++) {
			Cmp(ret, strs[i]);
			if (ret.length() == 0) {
				return "";
			}
		}
		return ret;
	}
};
