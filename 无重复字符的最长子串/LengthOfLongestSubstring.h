//************************************
//	file：LongestPalindrome.h
//  author：Tokey
//  date：2019/07/02
//************************************

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

*/

#pragma once
#include "head.h"
class LengthOfLongestSubstring {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0) {
			return 0;
		}
		int start = 0, end = 0, len = 1;
		for (; end < s.length();) {
			string t = s.substr(start, end - start);
			size_t pos = t.find(s[end]);
			if (pos != string::npos) {
				len = max(len, end - start);
				size_t c_pos  = s.find(s[end], start);
				start = c_pos + 1;
			}
			else {
				len = max(len, end - start + 1); 
				end++;
			}
		}
		return len;
	}
};