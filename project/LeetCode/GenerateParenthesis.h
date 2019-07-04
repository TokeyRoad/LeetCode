//************************************
//	file：GenerateParenthesis.h
//  author：Tokey
//  date：2019/07/04
//************************************

/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
例如，给出 n = 3，生成结果为：
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]

*/
#pragma once
#include "head.h"

class GenerateParenthesis {
public:
	void pushChar(int left, int right, vector<string>& v, string ret) {
		if (left > 0) {
			string t(ret);
			int t_left = left;
			int t_right = right;
			t.push_back('(');
			t_left--;
			t_right++;
			pushChar(t_left, t_right, v, t);
		}
		if (right > 0) {
			ret.push_back(')');
			right--;
			if ((left | right) == 0) {
				v.push_back(ret);
				return;
			}
			pushChar(left, right, v, ret);
		}
	}
	vector<string> generateParenthesis(int n) {
		if (n <= 0) {
			return vector<string>();
		}
		vector<string> v;
		string ret = "";
		pushChar(n, 0, v, ret);
		return v;
	}
};
