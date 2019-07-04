#pragma once
//************************************
//	file：MaxArea.h
//  author：Tokey
//  date：2019/07/03
//************************************

/*
定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

#include "head.h"


class MaxArea {
public:
	int maxArea(vector<int>& height) {
		if (height.size() < 2) {
			return 0;
		}
		int Max = 0;
		auto left = height.begin();
		auto right = height.end() - 1;
		int move = 0;	//1 表示移动左边， 2 表示移动右边
		int pre = 0;
		while (left < right) {
			switch (move) {
			case 1: {
				if (pre >= (*left)) {
					left++;
					continue;
				}
				break;
			}
			case 2: {
				if (pre >= (*right)) {
					right--;
					continue;
				}
				break;
			}
			}
			move = 0;
			int x = right - left;
			if ((*left) >= (*right)) {
				Max = max(Max, (x * (*right)));
				pre = (*right);
				right--;
				move = 2;
			}
			else {
				Max = max(Max, (x * (*left)));
				pre = (*left);
				left++;
				move = 1;
			}
		}
		return Max;
	}
};