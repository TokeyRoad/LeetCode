//************************************
//	file：IsValidBrackets.h
//  author：Tokey
//  date：2019/07/04
//************************************

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false
*/
#pragma once
#include "head.h"

class IsValidBrackets {
public:
	bool isValid(string s) {
		if (s.length() % 2 != 0) {
			return false;
		}
		list<char> l;
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
			case '(':
			case '[':
			case '{': {
				l.push_back(s[i]);
				break;
			}
			case ')': {
				if (l.back() == '(') l.pop_back();
				else return false;
				break;
			}
			case ']': {
				if (l.back() == '[') l.pop_back();
				else return false;
				break;
			}
			case '}': {
				if (l.back() == '{') l.pop_back();
				else return false;
				break;
			}
			default: {
				return false;
			}
			}
		}
		if (l.size() == 0) {
			return true;
		}
		return false;
	}
};


