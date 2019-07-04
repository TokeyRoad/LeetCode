//************************************
//	file：LongestPalindrome.h
//  author：Tokey
//  date：2019/07/02
//************************************

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
s
示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
*/
#pragma once
#include "head.h"

class LongestPalindrome {
public:
	int getArroundLen(int left, int right, string s) {
		int len = 0;
		while (left != -1 && right != s.length()) {
			if (s[left] == s[right]) {
				len++;
				left--;
				right++;
			}
			else {
				break;
			}
		}
		return len;
	}
	string longestPalindrome(string s) {
		if (s.length() == 0) {
			return "";
		}
		int max_len = 0;
		int s_start = 0, s_end = 0;
		for (int i = 0; i < s.length(); i++) {
			int len1 = getArroundLen(i, i, s) - 1;
			int len2 = getArroundLen(i, i + 1, s);

			if (max_len >= len1*2 + 1 && max_len >= len2 * 2) {
				continue;
			}
			else {
				if (len1*2 +1 > len2*2) {
					max_len = len1 * 2 + 1;
					s_start = i - len1;
					s_end = i + len1;
				}
				else {
					max_len = len2 * 2;
					s_start = i + 1 - len2;
					s_end = i + len2;
				}
			}
		}
		return s.substr(s_start, s_end - s_start + 1);
	}
};